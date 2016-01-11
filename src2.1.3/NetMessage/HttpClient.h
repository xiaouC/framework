#pragma once
#include "../Common/TLCommon.h"
#include "semaphore.h"
#include "curl/curl.h"
#include <queue>
#include <map>

namespace google { namespace protobuf { class MessageLite; } }

////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum HTTP_REQUEST_TYPE
{
    HTTP_REQUEST_TYPE_MSG,
    HTTP_REQUEST_TYPE_FILE,
};

class HttpRequest
{
    friend class TLHttpClient;
    friend class MultiCURLManager;
public:
    HttpRequest( int nRequestType, int nCallbackHandler );
    virtual ~HttpRequest();

    int getRequestType() const { return m_nRequestType; }
    bool getAppendToRecv() const { return m_bAppendToRecv; }

    void setHttpErrorCode( int nHttpCode ) { m_nHttpErrorCode = nHttpCode; }
    void setErrorString( const std::string& strErrorString ) { m_strErrorString = strErrorString; }

    virtual void set_opt( CURL* curl ) = 0;
    virtual void finish();              // 默认情况下，这个 finish 会 delete this 

protected:
    int m_nRequestType;
    bool m_bAppendToRecv;               // 当请求处理完了后，是否需要放回 m_quRecvRequest 队列里面，交给主线程处理 
    int m_nCallbackHandler;

    int m_nHttpErrorCode;
    std::string m_strErrorString;
};

class HttpRequestMsg : public HttpRequest
{
    friend class TLHttpClient;
public:
    HttpRequestMsg( int nMsgID, const std::string& strURLPrefix, const std::string& strContentType, int nCallbackHandler );
    virtual ~HttpRequestMsg();

    virtual void set_opt( CURL* curl );
    virtual void finish();

    void setRecvBuffer( const char* szRevcBuf = NULL, unsigned int nLength = 0 );
    void setSendBuffer( const char* szSendBuf = NULL, unsigned int nLength = 0 );

    int getMsgID() const { return m_nMsgID; }
    const std::vector<char>& getRecvBuffer() { return m_vecRecvBuffer; }

protected:
    char m_szBuf[128];
    int m_nMsgID;
    std::string m_strURLPrefix;
    std::string m_strContentType;
    std::vector<char> m_vecRecvBuffer;
    std::vector<char> m_vecSendBuffer;
};

class HttpRequestFile : public HttpRequest
{
    friend class TLHttpClient;
public:
    HttpRequestFile( const char* szRequestURL, const char* szSaveTo, int nCallbackHandler );
    virtual ~HttpRequestFile();

    virtual void set_opt( CURL* curl );
    virtual void finish();

protected:
    std::string m_strRequestURL;
    std::string m_strSaveTo;
    std::vector<char> m_vecRecvBuffer;
    FILE* m_pWriteFP;
};

class TLHttpClient
{
public:
    TLHttpClient();
    ~TLHttpClient();

    static TLHttpClient* sharedHttpClient();

	void Process();

public:
    // 添加到请求队列，等待发送给服务器 
    void sendMsg( int nMsgID, int nCallbackHandler, const std::string& strURLPrefix, const std::string& strContentType, ::google::protobuf::MessageLite* pMsg );
    // 添加到请求队列，等待发送给服务器 
    void sendMsg( int nMsgID, int nCallbackHandler, const std::string& strURLPrefix, const std::string& strContentType = "", const char* pszMsgData = NULL, int nLength = 0 );

    // 添加到请求队列，等待发送给服务器，这里是请求下载一个文件
    void requestFile( const char* szRequestURL, const char* szSaveTo, int nCallbackHandler );

    void appendRequestToSend( HttpRequest* pRequest );
    HttpRequest* getSendRequest();              // multi curl 线程通过调用这个函数，从请求队列提取一个请求，进行处理 

    int getPipeReadFD() const { return m_nPipeFD[0]; }
    int getPipeWriteFD() const { return m_nPipeFD[1]; }
    sem_t* getQuitSem() { return m_pQuitSem; }

protected:
    XL_LOCK m_kSendLock;
	std::queue<HttpRequest*> m_quSendRequest;

    int m_nPipeFD[2];

    sem_t* m_pQuitSem;
    XL_ThreadHandle m_hWorkTread;

public:
    // 这里不是发送，而是服务器返回后，添加到待处理队列，等待主线程处理 
	void appendRequestToRecv( HttpRequest* pRequest );

    // 游戏回放才会用到，其他地方不要调用 
    // 对应请求文件后的回调函数，在这里无法确定，目前无法在回放里面解决，淡淡的忧伤 
    void appendRequestToRecv( int nRequestType, int nMsgID, int nCallbackHandler, const char* szContent, int nLength );

protected:
	XL_LOCK m_kRecvLock;
	std::queue<HttpRequest*> m_quRecvRequest;

public:
    void setDefaultURL( const std::string& strDefaultURL ) { m_strDefaultURL = strDefaultURL; }
    const std::string& getDefaultURL() const { return m_strDefaultURL; }

    void setCookiePath( const std::string& strCookiePath ) { m_strCookiePath = strCookiePath; }
    const std::string& getCookiePath() const { return m_strCookiePath; }

    void setPlaybackScriptHandler( int nHandler );

protected:
    std::string m_strDefaultURL;
    std::string m_strCookiePath;

    int m_nPlaybackScriptHanlder;

public:
    void setResetHttpClient();
    bool m_bReset;
};
