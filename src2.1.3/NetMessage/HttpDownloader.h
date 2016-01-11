#ifndef __HTTPDOWNLOADER_H__
#define __HTTPDOWNLOADER_H__

#include "cocoa/CCObject.h"
#include "../Common/TLCommon.h"
#include "semaphore.h"
#include <queue>
#include "curl/curl.h"

class FileDownloadTask
{
public:
    FileDownloadTask()
    {
        memset(this, 0, sizeof(*this));
    }
    char sUrl[256];
    char sSaveTo[256];
    int nTag;
};

class FileDownloadResult
{
public:
    FileDownloadResult()
    {
        nTag = 0;
		iCode = 0;
		memset(errbuf, 0, sizeof(errbuf));
		buffer.clear();
    }
    int nTag;
    int iCode;
    char errbuf[CURL_ERROR_SIZE];

    // 可选，响应内容
    std::vector<char> buffer;
};

class CHttpDownloader: public cocos2d::CCObject
{
public:
    static CHttpDownloader* sharedHttpDownloader();
    static void purgeSharedHttpDownloader();
    CHttpDownloader();
    ~CHttpDownloader();
    void getContent(const char* sUrl, int nTag);
    void saveToFile(const char* sUrl, const char* sSaveTo, int nTag);
    void register_callback(int handler) { m_nLuaCallback = handler; };
    void register_progress_callback(int handler) { m_nLuaProgressCallback = handler; };
    int get_progress_callback() { return m_nLuaProgressCallback; };
protected:
    void process(float fElapsed);
    void process_response();
    void process_progress();

    XL_ThreadHandle m_send_thread;
    int m_nLuaCallback;
    int m_nLuaProgressCallback;
};

#endif // __HTTPDOWNLOADER_H__
