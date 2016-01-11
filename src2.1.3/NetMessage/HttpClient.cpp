#include "HttpClient.h"
#include "pthread.h"
#include "google/protobuf/message_lite.h"
#include <unistd.h>
#include <fcntl.h>
#include "CCCommon.h"
#include "CCLuaEngine.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "CCFileUtils.h"

#ifdef WIN32
#include <Windows.h>
#pragma comment(lib,"wsock32.lib")
int pipe(int fildes[2])
{
    int tcp1, tcp2;
    sockaddr_in name;
    memset(&name, 0, sizeof(name));
    name.sin_family = AF_INET;
    name.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    int namelen = sizeof(name);
    tcp1 = tcp2 = -1;

    int tcp = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp == -1){
        goto clean;
    }
    if (bind(tcp, (sockaddr*)&name, namelen) == -1){
        goto clean;
    }
    if (listen(tcp, 5) == -1){
        goto clean;
    }
    if (getsockname(tcp, (sockaddr*)&name, &namelen) == -1){
        goto clean;
    }
    tcp1 = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp1 == -1){
        goto clean;
    }
    if (-1 == connect(tcp1, (sockaddr*)&name, namelen)){
        goto clean;
    }

    tcp2 = accept(tcp, (sockaddr*)&name, &namelen);
    if (tcp2 == -1){
        goto clean;
    }
    if (closesocket(tcp) == -1){
        goto clean;
    }
    fildes[0] = tcp1;
    fildes[1] = tcp2;
    return 0;
clean:
    if (tcp != -1){
        closesocket(tcp);
    }
    if (tcp2 != -1){
        closesocket(tcp2);
    }
    if (tcp1 != -1){
        closesocket(tcp1);
    }
    return -1;
}
#else
#include <arpa/inet.h>
#endif

#if USE_NAMED_SEMAPHORE
#else
static sem_t m_kQuitSem;
#endif

static std::string strHttpClientSemaphore;
const char* getHttpClientSemaphore()
{
    strHttpClientSemaphore = std::string( "s_http" ) + getProjectNickname();

    return strHttpClientSemaphore.c_str();
}

static std::string strResetSemaphore;
const char* getResetSemaphore()
{
    strResetSemaphore = std::string( "s_rsthttp" ) + getProjectNickname();

    return strResetSemaphore.c_str();
}

USING_NS_CC;
size_t http_client_write_buffer( void* ptr, size_t size, size_t nmemb, void* stream )
{
    std::vector<char>* recvBuffer = (std::vector<char>*)stream;
    size_t sizes = size * nmemb;

    // add data to the end of recvBuffer
    // write data maybe called more than once in a single request
    recvBuffer->insert( recvBuffer->end(), (char*)ptr, (char*)ptr+sizes );

    return sizes;
}

size_t http_client_write_file( void* ptr, size_t size, size_t nmemb, FILE* fp )
{
    size_t n = fwrite( ptr, size, nmemb, fp );

    return n;
}

static bool multi_curl_need_quit = false;

#ifdef WIN32
static void http_thread( void* data )
#else
static void* http_thread( void* data )
#endif
{
    CURLM* curl_m = NULL;
    CURLSH* curl_msg_share = NULL;
    CURLSH* curl_file_share = NULL;
    std::map<CURL*,HttpRequest*> mapCURLToRequest;

    HttpRequest* pRequest = NULL;

    timeval tvTimeOut;

    long curl_timeo = -1;

    while( !multi_curl_need_quit )
    {
#ifdef WIN32
        Sleep( 1 );
#endif

        // 如果需要重置的话
        if( TLHttpClient::sharedHttpClient()->m_bReset )
        {
            if( curl_m != NULL )
            {
                std::map<CURL*,HttpRequest*>::iterator iter = mapCURLToRequest.begin();
                std::map<CURL*,HttpRequest*>::iterator iter_end = mapCURLToRequest.end();
                for( ; iter != iter_end; ++iter )
                    curl_multi_remove_handle( curl_m, iter->first );

                for( iter = mapCURLToRequest.begin(); iter != iter_end; ++iter )
                {
                    curl_easy_cleanup( iter->first );
                    delete iter->second;
                }

                curl_multi_cleanup( curl_m );
                curl_share_cleanup( curl_msg_share );
                curl_share_cleanup( curl_file_share );

            }

            // 重新初始化
            curl_m = curl_multi_init();
            curl_msg_share = curl_share_init();
            curl_file_share = curl_share_init();

            curl_share_setopt( curl_msg_share, CURLSHOPT_SHARE, CURL_LOCK_DATA_COOKIE );
            curl_share_setopt( curl_msg_share, CURLSHOPT_SHARE, CURL_LOCK_DATA_DNS );

            curl_share_setopt( curl_file_share, CURLSHOPT_SHARE, CURL_LOCK_DATA_DNS );

            mapCURLToRequest.clear();

            TLHttpClient::sharedHttpClient()->m_bReset = false;
        }

        // select
        fd_set fdRead;
        fd_set fdWrite;
        fd_set fdExcept;

        FD_ZERO( &fdRead );
        FD_ZERO( &fdWrite );
        FD_ZERO( &fdExcept );

        int nMaxFD = -1;
        curl_multi_fdset( curl_m, &fdRead, &fdWrite, &fdExcept, &nMaxFD );

#ifndef WIN32
        int nPipeReadFD = TLHttpClient::sharedHttpClient()->getPipeReadFD();
        FD_SET( nPipeReadFD, &fdRead );

        if( nPipeReadFD > nMaxFD )
            nMaxFD = nPipeReadFD;
#endif

        tvTimeOut.tv_usec = 0;
#ifdef WIN32
        tvTimeOut.tv_sec = 1.0f;
#else
        tvTimeOut.tv_sec = 50.0f;
#endif

        // reset time out
        curl_multi_timeout( curl_m, &curl_timeo );
        if( curl_timeo >= 0 )
        {
            tvTimeOut.tv_sec = curl_timeo / 1000;
            if( tvTimeOut.tv_sec > 1 )
                tvTimeOut.tv_sec = 1;
            else
                tvTimeOut.tv_usec = ( curl_timeo % 1000 ) * 1000;
        }

        int nSelRetCode = ::select( nMaxFD + 1, &fdRead, &fdWrite, &fdExcept, &tvTimeOut );

#ifndef WIN32
        if( FD_ISSET( nPipeReadFD, &fdRead ) )
        {
            char szBuf[1024];
            while( true )
            {
                int nRet = read( nPipeReadFD, szBuf, 1024 );
                if( nRet == -1 )
                {
                    if( errno == EAGAIN || errno == EWOULDBLOCK )
                        break;
                }
                else if( nRet == 0 )
                {
                    printf( "========================================================================================================\n" );
                    printf( "========================================================================================================\n" );
                    printf( "========================================================================================================\n" );
                    printf( "http client error : 非阻塞下，竟然 read() 返回了 0 ！这是神马情况！\n" );
                    printf( "========================================================================================================\n" );
                    printf( "========================================================================================================\n" );
                    printf( "========================================================================================================\n" );
                }
            }
        }
#endif

        // request
        while( (pRequest = TLHttpClient::sharedHttpClient()->getSendRequest()) != NULL )
        {
            CURL* curl = curl_easy_init();
            curl_multi_add_handle( curl_m, curl );
            mapCURLToRequest[curl] = pRequest;
            pRequest->set_opt( curl );
            if (pRequest->getRequestType() == HTTP_REQUEST_TYPE_MSG)
            {
                curl_easy_setopt(curl, CURLOPT_SHARE, curl_msg_share);
            }
            else if (pRequest->getRequestType() == HTTP_REQUEST_TYPE_FILE)
            {
                curl_easy_setopt(curl, CURLOPT_SHARE, curl_file_share);
            }
        }

        // perform
        int running_handles;
        curl_multi_perform( curl_m, &running_handles );

        // callback
        int nMsgLeft;
        while( true )
        {
            CURLMsg* msg = curl_multi_info_read( curl_m, &nMsgLeft );
            if( msg == NULL )
                break;

            std::map<CURL*,HttpRequest*>::iterator iter = mapCURLToRequest.find( msg->easy_handle );
            CCAssert( iter != mapCURLToRequest.end(), "这是不可能的!" );

            if( msg->data.result == CURLE_COULDNT_CONNECT || msg->data.result == CURLE_OPERATION_TIMEDOUT )
            {
                long http_code = 0;
                curl_easy_getinfo( msg->easy_handle, CURLINFO_RESPONSE_CODE, &http_code );

                iter->second->setHttpErrorCode( http_code );

                iter->second->setErrorString( msg->data.result == CURLE_COULDNT_CONNECT ? "   15服务器未开启!" : "   连接超时!" );

                // finish 内部会自己清理自己，包括有可能 delete this
                iter->second->finish();

                // 清理 
                CURL* easy_handle = msg->easy_handle;
                curl_multi_remove_handle( curl_m, easy_handle );
                curl_easy_cleanup( easy_handle );

                mapCURLToRequest.erase( iter );
            }

            if( msg->data.result == CURLE_OK )
            {
                long http_code = 0;
                curl_easy_getinfo( msg->easy_handle, CURLINFO_RESPONSE_CODE, &http_code );

                iter->second->setHttpErrorCode( http_code );

                if( http_code != 200 )
                {
                    if( http_code == 740 && iter->second->getRequestType() == HTTP_REQUEST_TYPE_MSG )
                    {
                        HttpRequestMsg* pMsgRequest = (HttpRequestMsg*)iter->second;
                        const std::vector<char>& vecRecvBuffer = pMsgRequest->getRecvBuffer();

                        if( !vecRecvBuffer.empty() )
                        {
                            std::string strErrorString( &vecRecvBuffer[0], vecRecvBuffer.size() );
                            iter->second->setErrorString( strErrorString );
                            printf( "========================================================================================================\n" );
                            printf( "http error : %ld\n", http_code );
                            printf( "error string : %s\n", strErrorString.c_str() );
                            printf( "========================================================================================================\n" );
                        }
                        else
                        {
                            printf( "========================================================================================================\n" );
                            printf( "http error : %ld\n", http_code );
                            printf( "message id = %d\n", pMsgRequest->getMsgID() );
                            printf( "没有对应的 error code 和 error string !\n" );
                            printf( "========================================================================================================\n" );
                        }
                    }
                    else
                    {
                        printf( "========================================================================================================\n" );
                        printf( "http error : %ld\n", http_code );
                        printf( "========================================================================================================\n" );
                    }
                }

                if( msg->msg == CURLMSG_DONE )
                {
                    // finish 内部会自己清理自己，包括有可能 delete this
                    iter->second->finish();

                    // 清理 
                    CURL* easy_handle = msg->easy_handle;
                    curl_multi_remove_handle( curl_m, easy_handle );
                    curl_easy_cleanup( easy_handle );

                    mapCURLToRequest.erase( iter );
                }
            }
        }
    }

    // 
    std::map<CURL*,HttpRequest*>::iterator iter = mapCURLToRequest.begin();
    std::map<CURL*,HttpRequest*>::iterator iter_end = mapCURLToRequest.end();
    for( ; iter != iter_end; ++iter )
    {
        curl_multi_remove_handle( curl_m, iter->first );
    }

    for( iter = mapCURLToRequest.begin(); iter != iter_end; ++iter )
    {
        curl_easy_cleanup( iter->first );

        delete iter->second;
    }

    curl_multi_cleanup( curl_m );
    curl_share_cleanup( curl_msg_share );
    curl_share_cleanup( curl_file_share );

    //
    sem_post( TLHttpClient::sharedHttpClient()->getQuitSem() );

#ifndef WIN32
    return NULL;
#endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
HttpRequest::HttpRequest( int nRequestType, int nCallbackHandler )
: m_nRequestType(nRequestType)
, m_nCallbackHandler(nCallbackHandler)
{
}

HttpRequest::~HttpRequest()
{
    if( m_nCallbackHandler > 0 )
        CCLuaEngine::defaultEngine()->removeScriptHandler( m_nCallbackHandler );
}

void HttpRequest::finish()
{
    delete this;
}

HttpRequestMsg::HttpRequestMsg( int nMsgID, const std::string& strURLPrefix, const std::string& strContentType, int nCallbackHandler )
: HttpRequest(HTTP_REQUEST_TYPE_MSG,nCallbackHandler)
, m_nMsgID(nMsgID)
, m_strURLPrefix(strURLPrefix)
, m_strContentType(strContentType)
{
    if( m_strContentType.empty() )
        m_strContentType = "Content-Type: application/protobuf";

    m_bAppendToRecv = true;
}

HttpRequestMsg::~HttpRequestMsg()
{
}

void HttpRequestMsg::set_opt( CURL* curl )
{
    curl_easy_setopt( curl, CURLOPT_NOSIGNAL, 1L);

    m_vecRecvBuffer.clear();

    memset(m_szBuf, 0, sizeof(m_szBuf));
    if( m_nMsgID != -1 )
    {
        if( m_strURLPrefix.empty() )
            snprintf( m_szBuf, sizeof(m_szBuf), "%s/%d", TLHttpClient::sharedHttpClient()->getDefaultURL().c_str(), m_nMsgID );
        else
            snprintf( m_szBuf, sizeof(m_szBuf), "%s/%s/%d", TLHttpClient::sharedHttpClient()->getDefaultURL().c_str(), m_strURLPrefix.c_str(), m_nMsgID );
    }
    else
    {
        snprintf( m_szBuf, sizeof(m_szBuf), "%s", m_strURLPrefix.c_str() );

        curl_easy_setopt( curl, CURLOPT_CONNECTTIMEOUT, 3 );
        curl_easy_setopt( curl, CURLOPT_TIMEOUT, 10 );
    }

    curl_easy_setopt( curl, CURLOPT_URL, m_szBuf );

    const std::string& strCookiePath = TLHttpClient::sharedHttpClient()->getCookiePath();
    curl_easy_setopt( curl, CURLOPT_COOKIEFILE, strCookiePath.c_str() );            // Read cookie file
    curl_easy_setopt( curl, CURLOPT_COOKIEJAR, strCookiePath.c_str() );             // Write cookie file

    // 
    struct curl_slist* curlHeader = NULL;
    curlHeader = curl_slist_append( curlHeader, m_strContentType.c_str() );
    curl_easy_setopt( curl, CURLOPT_HTTPHEADER, curlHeader );

    curl_easy_setopt( curl, CURLOPT_POST, 1 );

    if( m_vecSendBuffer.size() > 0 )
    {
        // protobuf
        curl_easy_setopt( curl, CURLOPT_POSTFIELDS, (char*)&m_vecSendBuffer[0] );
        curl_easy_setopt( curl, CURLOPT_POSTFIELDSIZE, m_vecSendBuffer.size() );
    }
    else
    {
        curl_easy_setopt( curl, CURLOPT_POSTFIELDS, NULL );
        curl_easy_setopt( curl, CURLOPT_POSTFIELDSIZE, 0 );
    }

    curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, http_client_write_buffer );
    curl_easy_setopt( curl, CURLOPT_WRITEDATA, &m_vecRecvBuffer );
}

void HttpRequestMsg::finish()
{
    // 不需要 delete this，因为还要返回给消息处理线程 
    // 后由消息处理线程执行 delete
    TLHttpClient::sharedHttpClient()->appendRequestToRecv( this );
}

void HttpRequestMsg::setRecvBuffer( const char* szRevcBuf, unsigned int nLength )
{
    m_vecRecvBuffer.insert( m_vecRecvBuffer.end(), (char*)szRevcBuf, (char*)szRevcBuf+nLength );
}

void HttpRequestMsg::setSendBuffer( const char* szSendBuf, unsigned int nLength )
{
    m_vecSendBuffer.insert( m_vecSendBuffer.end(), (char*)szSendBuf, (char*)szSendBuf+nLength );
}

HttpRequestFile::HttpRequestFile( const char* szRequestURL, const char* szSaveTo, int nCallbackHandler )
: HttpRequest(HTTP_REQUEST_TYPE_FILE,nCallbackHandler)
, m_strRequestURL(szRequestURL)
, m_strSaveTo(szSaveTo)
, m_pWriteFP(NULL)
{
}

HttpRequestFile::~HttpRequestFile()
{
    if( m_pWriteFP != NULL )
    {
        fclose( m_pWriteFP );
        m_pWriteFP = NULL;
    }
}

void HttpRequestFile::set_opt( CURL* curl )
{

    curl_easy_setopt( curl, CURLOPT_NOSIGNAL, 1L);
    //curl_easy_setopt( curl, CURLOPT_ERRORBUFFER, pResult->errbuf );
    curl_easy_setopt( curl, CURLOPT_URL, m_strRequestURL.c_str() );
    //curl_easy_setopt( curl, CURLOPT_FAILONERROR, true );
    curl_easy_setopt( curl, CURLOPT_FOLLOWLOCATION, true );

    // 不需要 save to 的话，就只返回内容，否则就保存成文件
    if( m_strSaveTo.empty() )
    {
        m_vecRecvBuffer.clear();
        curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, http_client_write_buffer );
        curl_easy_setopt( curl, CURLOPT_WRITEDATA, &m_vecRecvBuffer );
    }
    else
    {
        m_pWriteFP = fopen( m_strSaveTo.c_str(), "wb" );
        if( m_pWriteFP == NULL )
        {
            printf( "open file( %s ) failed !\n", m_strSaveTo.c_str() );

            return;
        }

        curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, http_client_write_file );
        curl_easy_setopt( curl, CURLOPT_WRITEDATA, m_pWriteFP );
    }
}

void HttpRequestFile::finish()
{
    if( m_pWriteFP != NULL )
    {
        fclose( m_pWriteFP );
        m_pWriteFP = NULL;
    }

    TLHttpClient::sharedHttpClient()->appendRequestToRecv( this );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TLHttpClient* g_pTLHttpClient = NULL;
TLHttpClient::TLHttpClient()
: m_nPlaybackScriptHanlder(0)
, m_bReset(true)
{
#ifndef WIN32
    if( pipe( m_nPipeFD ) < 0 )
    {
        CCLog( "create pipe error !" );

        return;
    }

    fcntl( m_nPipeFD[0], F_SETFL, O_NONBLOCK );
    fcntl( m_nPipeFD[1], F_SETFL, O_NONBLOCK );
#endif

    // 
    LockInit( m_kSendLock );
    LockInit( m_kRecvLock );

#if USE_NAMED_SEMAPHORE
    m_pQuitSem = sem_open( getHttpClientSemaphore(), O_CREAT, 0644, 0 );
    if( m_pQuitSem == SEM_FAILED )
    {
        CCLog( "http client quit semaphore init error: %s\n", strerror( errno ) );
        CCAssert(false, "open named sem failed");
    }
#else
    int iRet = sem_init( &m_kQuitSem, 0, 0 );
    if (iRet<0)
    {
        CCLog("sem_init error: %d %s", iRet, strerror(errno));
    }
    m_pQuitSem = &m_kQuitSem;
#endif

#ifdef WIN32
	m_hWorkTread = _beginthread( &http_thread, 0, this );
#else
    pthread_create( &m_hWorkTread, NULL, &http_thread, NULL );
#endif
}

TLHttpClient::~TLHttpClient()
{
    multi_curl_need_quit = true;

    sem_wait( m_pQuitSem );

	LockRelease( m_kSendLock );
	LockRelease( m_kRecvLock );

#if USE_NAMED_SEMAPHORE
    sem_close( m_pQuitSem );
    sem_unlink( getHttpClientSemaphore() );
    sem_unlink( getResetSemaphore() );
#else
    sem_destroy( m_pQuitSem );
#endif
}

TLHttpClient* TLHttpClient::sharedHttpClient()
{
    if( g_pTLHttpClient == NULL )
        g_pTLHttpClient = new TLHttpClient;

    return g_pTLHttpClient;
}

void TLHttpClient::Process()
{
    CAutoLock autoLock( m_kRecvLock );

	while( !m_quRecvRequest.empty() )
	{
		HttpRequest* pRequest = m_quRecvRequest.front();
        m_quRecvRequest.pop();

        if( pRequest == NULL )
            continue;

        if( pRequest->m_nCallbackHandler > 0 )
        {
            int nArgNum = 0;
            switch( pRequest->m_nRequestType )
            {
                case HTTP_REQUEST_TYPE_MSG:
                    {
                        HttpRequestMsg* pMsgRequest = (HttpRequestMsg*)pRequest;

                        if( pMsgRequest->m_vecRecvBuffer.size() == 0 )
                        {
                            CCLuaEngine::defaultEngine()->getLuaStack()->pushString( "", 0 );
                        }
                        else
                        {
                            CCLuaEngine::defaultEngine()->getLuaStack()->pushString( &pMsgRequest->m_vecRecvBuffer[0], pMsgRequest->m_vecRecvBuffer.size() );
                        }

                        nArgNum += 1;
                    }
                    break;
                case HTTP_REQUEST_TYPE_FILE:
                    {
                        HttpRequestFile* pFileRequest = (HttpRequestFile*)pRequest;

                        // save to 的话，就返回文件名，否则就返回接收到的内容
                        if( pFileRequest->m_strSaveTo.empty() )
                        {
                            CCLuaEngine::defaultEngine()->getLuaStack()->pushString( &pFileRequest->m_vecRecvBuffer[0], pFileRequest->m_vecRecvBuffer.size() );
                        }
                        else
                        {
                            CCLuaEngine::defaultEngine()->getLuaStack()->pushString( pFileRequest->m_strSaveTo.c_str(), pFileRequest->m_strSaveTo.length() );
                        }

                        nArgNum += 1;
                    }
                    break;
            }

            // http code
            nArgNum += 1;
            CCLuaEngine::defaultEngine()->getLuaStack()->pushInt( pRequest->m_nHttpErrorCode );

            // 错误信息 
            if( !pRequest->m_strErrorString.empty() )
            {
                if( pRequest->m_strErrorString.size() > 5 )
                {
                    std::string strErrorCode( &pRequest->m_strErrorString[0], 5 );
                    std::string strErrorMsg( &pRequest->m_strErrorString[5], pRequest->m_strErrorString.size() - 5 );

                    nArgNum += 2;

                    CCLuaEngine::defaultEngine()->getLuaStack()->pushString( pRequest->m_strErrorString.c_str(), 5 );
                    CCLuaEngine::defaultEngine()->getLuaStack()->pushString( &pRequest->m_strErrorString[5], pRequest->m_strErrorString.size() - 5 );
                }
                else
                {
                    nArgNum += 1;

                    CCLuaEngine::defaultEngine()->getLuaStack()->pushString( pRequest->m_strErrorString.c_str(), pRequest->m_strErrorString.size() );
                }
            }

            // 
            CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( pRequest->m_nCallbackHandler, nArgNum );
        }

		//////////////////////////////////////////////////////////////////////////
		delete pRequest;
	}
}

void TLHttpClient::sendMsg( int nMsgID, int nCallbackHandler, const std::string& strURLPrefix, const std::string& strContentType, ::google::protobuf::MessageLite* pMsg )
{
	std::string strMsgContent;
	pMsg->SerializeToString( &strMsgContent );

    sendMsg( nMsgID, nCallbackHandler, strURLPrefix, strContentType, strMsgContent.c_str(), strMsgContent.length() );
}

void TLHttpClient::sendMsg( int nMsgID, int nCallbackHandler, const std::string& strURLPrefix, const std::string& strContentType, const char* szSendBuf, int nLength )
{
    HttpRequestMsg* pRequest = new HttpRequestMsg( nMsgID, strURLPrefix, strContentType, nCallbackHandler );
    pRequest->setSendBuffer( szSendBuf, nLength );

    appendRequestToSend( pRequest );
}

void TLHttpClient::requestFile( const char* szRequestURL, const char* szSaveTo, int nCallbackHandler )
{
    HttpRequestFile* pRequest = new HttpRequestFile( szRequestURL, szSaveTo, nCallbackHandler );
    appendRequestToSend( pRequest );
}

void TLHttpClient::appendRequestToSend( HttpRequest* pRequest )
{
    CAutoLock autoLock( m_kSendLock );

    m_quSendRequest.push( pRequest );

#ifndef WIN32
    write( getPipeWriteFD(), "1", 1 );
#endif
}

HttpRequest* TLHttpClient::getSendRequest()
{
    CAutoLock autoLock( m_kSendLock );

    if( m_bReset )
    {
#ifndef WIN32
        write( getPipeWriteFD(), "1", 1 );
#endif

        return NULL;
    }

	if( !m_quSendRequest.empty() )
	{
		HttpRequest* pRequest = m_quSendRequest.front();
		m_quSendRequest.pop();

		return pRequest;
	}

	return NULL;
}

void TLHttpClient::appendRequestToRecv( HttpRequest* pRequest )
{
    CAutoLock autoLock( m_kRecvLock );

    if( m_nPlaybackScriptHanlder > 0 )
    {
        int nArgNum = 3;

        // request type
        CCLuaEngine::defaultEngine()->getLuaStack()->pushInt( (int)pRequest->m_nRequestType );

        switch( pRequest->m_nRequestType )
        {
            case HTTP_REQUEST_TYPE_MSG:
                {
                    HttpRequestMsg* pMsgRequest = (HttpRequestMsg*)pRequest;

                    // message id
                    CCLuaEngine::defaultEngine()->getLuaStack()->pushInt( (int)pMsgRequest->m_nMsgID );

                    // string buffer
                    CCLuaEngine::defaultEngine()->getLuaStack()->pushString( &pMsgRequest->m_vecRecvBuffer[0], pMsgRequest->m_vecRecvBuffer.size() );
                }
                break;
            case HTTP_REQUEST_TYPE_FILE:
                {
                    HttpRequestFile* pFileRequest = (HttpRequestFile*)pRequest;

                    // message id
                    CCLuaEngine::defaultEngine()->getLuaStack()->pushInt( 0 );

                    // string buffer
                    CCLuaEngine::defaultEngine()->getLuaStack()->pushString( pFileRequest->m_strSaveTo.c_str(), pFileRequest->m_strSaveTo.length() );
                }
                break;
            default: CCAssert( false, "Request type error !" ); break;
        }// End switch( pRequest->m_nRequestType )

        CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( m_nPlaybackScriptHanlder, nArgNum );
    }

	m_quRecvRequest.push( pRequest );
}

void TLHttpClient::appendRequestToRecv( int nRequestType, int nMsgID, int nCallbackHandler, const char* szContent, int nLength )
{
    // 服务器请求文件的这个，因为 nCallbackHandler 无法确定，导致在回放里面无法处理，淡淡的忧伤啊 
    if( nRequestType == HTTP_REQUEST_TYPE_FILE )
    {
        if( nCallbackHandler > 0 )
        {
            std::string strRealPath(szContent,nLength);
            CCLuaEngine::defaultEngine()->getLuaStack()->pushString( strRealPath.c_str(), strRealPath.length() );
            CCLuaEngine::defaultEngine()->getLuaStack()->executeFunctionByHandler( nCallbackHandler, 1 );
        }

        return;
    }

    HttpRequest* pRequest = NULL;
    switch( nRequestType )
    {
        case HTTP_REQUEST_TYPE_MSG:
            {
                HttpRequestMsg* pMsgRequest = new HttpRequestMsg( nMsgID, "recv", "", nCallbackHandler );
                pMsgRequest->setRecvBuffer( szContent, nLength );

                pRequest = pMsgRequest;
            }
            break;
    }// End switch( nRequestType )

    CAutoLock autoLock( m_kRecvLock );

	m_quRecvRequest.push( pRequest );
}

void TLHttpClient::setPlaybackScriptHandler( int nHandler )
{
    if( m_nPlaybackScriptHanlder > 0 )
        CCLuaEngine::defaultEngine()->getLuaStack()->removeScriptHandler( m_nPlaybackScriptHanlder );

    m_nPlaybackScriptHanlder = nHandler;
}

void TLHttpClient::setResetHttpClient()
{
    CAutoLock autoLock( m_kSendLock );

    m_bReset = true;

#ifndef WIN32
    write( getPipeWriteFD(), "1", 1 );
#endif
}

