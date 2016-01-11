#include <string.h>
#include "CCScheduler.h"
#include "HttpDownloader.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "CCDirector.h"

USING_NS_CC;

static CHttpDownloader* _instance=NULL;

#ifdef WIN32
#pragma comment(lib, "wsock32")
#include <process.h>
#include <io.h>
#include <direct.h>
#else
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include "sys/socket.h"
#include "arpa/inet.h"
#include "pthread.h"
#endif

static sem_t* m_pSem = NULL;

#if USE_NAMED_SEMAPHORE
#else
static sem_t m_send_sem;
#endif

static std::string strDownloaderSemaphore;
const char* getDownloaderSemaphore()
{
    strDownloaderSemaphore = std::string( "sem_downloader" ) + getProjectNickname();

    return strDownloaderSemaphore.c_str();
}

static bool need_quit = false;

static XL_LOCK m_send_lock;
static std::queue<FileDownloadTask*> m_send_queue;

static XL_LOCK m_result_lock;
static std::queue<FileDownloadResult*> m_result_queue;

static XL_LOCK m_progress_lock;
static std::queue<int> m_progress_queue;

size_t write_file(void *ptr, size_t size, size_t nmemb, FILE *fp)
{
    size_t n = fwrite(ptr, size, nmemb, fp);
    if (n<nmemb)
    {
        CCLOGERROR("write file failed %d", ferror(fp));
    }
    // progress callback
    if (n>0)
    {
        LockEnter( m_progress_lock );
        m_progress_queue.push(n);
        LockLeave( m_progress_lock );
    }
    return n;
}

size_t write_buffer(void *ptr, size_t size, size_t nmemb, void *stream)
{
    std::vector<char> *recvBuffer = (std::vector<char>*)stream;
    size_t sizes = size * nmemb;

    // add data to the end of recvBuffer
    // write data maybe called more than once in a single request
    recvBuffer->insert(recvBuffer->end(), (char*)ptr, (char*)ptr+sizes);
    return sizes;
}

static bool ensure_directory_exists(const char* path)
{
    std::string tmp(path);
    size_t pos = tmp.rfind('/');
    if (pos==std::string::npos)
    {
        // no directory
        return true;
    }
    std::string dir = tmp.substr(0, pos);

#ifdef WIN32
	if( _access( dir.c_str(), 0 ) != -1 )
		return true;
	return _mkdir( dir.c_str() ) == 0;	// 0 ³É¹¦, -1 Ê§°Ü
#else
	if (access(dir.c_str(), F_OK) == 0)
		return true;
	return mkdir(dir.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)==0;
#endif
}

#ifdef WIN32
static void download_thread(void *data)
#else
static void* download_thread(void *data)
#endif
{
    int iRet=0;
#ifdef WIN32
    CURLcode curlRet = curl_global_init(CURL_GLOBAL_WIN32);
#else
	CURLcode curlRet = curl_global_init(CURL_GLOBAL_NOTHING);
#endif
    if (curlRet!=CURLE_OK)
    {
        CCLOGERROR("curl init failed %d", curlRet);
#ifndef WIN32
        return NULL;
#else
        return;
#endif
    }
    CURL *curl = curl_easy_init();
    while (true)
    {
        iRet = sem_wait(m_pSem);
        if (iRet<0)
        {
#ifdef WIN32
            CCLOGERROR("file download thread sem_wait error %d", iRet);
#else
            CCLOGERROR("file download thread sem_wait error: %d %s", iRet, strerror(errno));
#endif
            break;
        }

        if (need_quit)
        {
            break;
        }

        FileDownloadTask* pTask = NULL;
        LockEnter( m_send_lock );
        if (!m_send_queue.empty())
        {
            pTask = m_send_queue.front();
            m_send_queue.pop();
        }
        LockLeave( m_send_lock );

        if (pTask==NULL)
        {
            continue; 
        }

        FileDownloadResult *pResult = new FileDownloadResult();
        pResult->nTag = pTask->nTag;

        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, pResult->errbuf);
        curl_easy_setopt(curl, CURLOPT_URL, pTask->sUrl);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);

        if (pTask->sSaveTo[0]!='\0')
        {
            /*
            if (!ensure_directory_exists(pTask->sSaveTo))
            {
                pResult->iCode = -1;
                XLSprintf(pResult->errbuf, sizeof(pResult->errbuf)-1, "create directory failed %s", pTask->sSaveTo);
                goto send_result;
            }
            */
            FILE *fp = fopen(pTask->sSaveTo, "wb");
            if (fp==NULL)
            {
                pResult->iCode = -1;
                XLSprintf(pResult->errbuf, sizeof(pResult->errbuf)-1, "open file failed %s", pTask->sSaveTo);
                goto send_result;
            }
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_file);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            pResult->iCode = curl_easy_perform(curl);
            fclose(fp);
        }
        else
        {
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_buffer);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &pResult->buffer);
            pResult->iCode = curl_easy_perform(curl);
        }

send_result:
        if (pTask!=NULL)
            delete pTask;
        // send result
        LockEnter( m_result_lock );
        m_result_queue.push(pResult);
        LockLeave( m_result_lock );
    }
#if USE_NAMED_SEMAPHORE
    sem_close(m_pSem);
    sem_unlink(getDownloaderSemaphore());
#else
    sem_destroy(m_pSem);
#endif
    m_pSem = NULL;
    curl_easy_cleanup(curl);
    curl = NULL;
    curl_global_cleanup();
#ifndef WIN32
    return NULL;
#endif
}

CHttpDownloader* CHttpDownloader::sharedHttpDownloader()
{
    if (_instance==NULL)
    {
        _instance = new CHttpDownloader();
    }
    return _instance;
}

void CHttpDownloader::purgeSharedHttpDownloader()
{
    if (_instance!=NULL)
    {
		CCDirector::sharedDirector()->getScheduler()->unscheduleAllForTarget(_instance);
    }
    CC_SAFE_RELEASE_NULL(_instance);
}

CHttpDownloader::CHttpDownloader()
{
	need_quit = false;

    m_nLuaCallback = 0;
    m_nLuaProgressCallback = 0;
    LockInit(m_send_lock);
    LockInit(m_result_lock);
    LockInit(m_progress_lock);
#if USE_NAMED_SEMAPHORE
    m_pSem = sem_open(getDownloaderSemaphore(), O_CREAT, 0644, 0);
    if( m_pSem == SEM_FAILED )
    {
        CCLOG( "CCTextureCache async thread semaphore init error: %s\n", strerror( errno ) );
        CCAssert(false, "open named sem failed");
    }
#else
    int iRet = sem_init(&m_send_sem, 0, 0);
    if (iRet<0)
    {
#ifdef WIN32
            CCLOGERROR("sem_init error %d", iRet);
#else
            CCLOGERROR("sem_init error: %d %s", iRet, strerror(errno));
#endif
        CCAssert(false, "init sem failed");
    }
    m_pSem = &m_send_sem;
#endif
    CCDirector::sharedDirector()->getScheduler()->scheduleSelector( schedule_selector(CHttpDownloader::process), this, 0, false);

#ifdef WIN32
	m_send_thread = _beginthread( &download_thread, 0, NULL );
#else
	pthread_create( &m_send_thread, NULL, &download_thread, NULL );
#endif

}

CHttpDownloader::~CHttpDownloader()
{
	need_quit = true;

    sem_post(m_pSem);

    LockRelease(m_send_lock);
    LockRelease(m_result_lock);
    LockRelease(m_progress_lock);

    while(!m_result_queue.empty())
    {
        FileDownloadResult *pResult = m_result_queue.front();
        if (pResult!=NULL)
        {
            delete pResult;
        }
        m_result_queue.pop();
    }

    while(!m_progress_queue.empty())
        m_progress_queue.pop();

    if (m_nLuaCallback>0)
    {
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nLuaCallback );
        m_nLuaCallback = 0;
    }

    if (m_nLuaProgressCallback>0)
	{
		CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nLuaProgressCallback );
        m_nLuaProgressCallback = 0;
    }
}

void CHttpDownloader::getContent(const char* sUrl, int nTag)
{
    CCAssert(sUrl!=NULL, "invalid argument");
	CAutoLock autoLock( m_send_lock );

    FileDownloadTask *task = new FileDownloadTask();
    strncpy(task->sUrl, sUrl, sizeof(task->sUrl));
    task->nTag = nTag;

    m_send_queue.push(task);

	sem_post(m_pSem);
}

void CHttpDownloader::saveToFile(const char* sUrl, const char* sSaveTo, int nTag)
{
    CCAssert(sUrl!=NULL, "invalid argument");
    CCAssert(sSaveTo!=NULL, "invalid argument");
	CAutoLock autoLock( m_send_lock );

    FileDownloadTask *task = new FileDownloadTask();
    strncpy(task->sUrl, sUrl, sizeof(task->sUrl)-1);
    strncpy(task->sSaveTo, sSaveTo, sizeof(task->sSaveTo)-1);

    task->nTag = nTag;

    m_send_queue.push(task);

	sem_post(m_pSem);
}

void CHttpDownloader::process_progress()
{
    CAutoLock autoLock( m_progress_lock );
    int progress = 0;
    while ( !m_progress_queue.empty() )
    {
        progress += m_progress_queue.front();
        m_progress_queue.pop();
    }
    if (progress>0 && m_nLuaProgressCallback>0)
    {
		CCLuaEngine::defaultEngine()->getLuaStack()->pushInt( progress );
		CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nLuaProgressCallback, 1 );
    }
}

void CHttpDownloader::process_response()
{
    CAutoLock autoLock( m_result_lock );
    while ( !m_result_queue.empty() )
    {
        FileDownloadResult* pResult = m_result_queue.front();
        m_result_queue.pop();
        if (m_nLuaCallback>0)
        {
			CCLuaEngine::defaultEngine()->getLuaStack()->pushInt( pResult->nTag );
			CCLuaEngine::defaultEngine()->getLuaStack()->pushInt( pResult->iCode );

			int argNum = 4;
			if( pResult->buffer.size() == 0 )
			{
				CCLuaEngine::defaultEngine()->getLuaStack()->pushString( pResult->errbuf );
				argNum = 3;
			}
			else
			{
				void* pBuffer = reinterpret_cast<void*> (&pResult->buffer[0]);
				int iBufferLen = pResult->buffer.size();
				CCLuaEngine::defaultEngine()->getLuaStack()->pushString( (const char*)pBuffer, iBufferLen);
				CCLuaEngine::defaultEngine()->getLuaStack()->pushInt( iBufferLen );
			}
			CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nLuaCallback, argNum );
        }
        delete pResult;
    }
}

void CHttpDownloader::process(float fElapsed)
{
    process_response();
    process_progress();
}
