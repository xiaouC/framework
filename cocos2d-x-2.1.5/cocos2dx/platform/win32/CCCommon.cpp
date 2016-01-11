/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include "platform/CCCommon.h"
#include "CCStdC.h"

NS_CC_BEGIN

#define MAX_LEN         (cocos2d::kMaxLogLen + 1)

CCLogFunction _logFunction = NULL;

void CCSetLogFunction(CCLogFunction func)
{
	_logFunction = func;
}

void CCLog(const char * pszFormat, ...)
{
    char szBuf[MAX_LEN];

    va_list ap;
    va_start(ap, pszFormat);
    vsnprintf_s(szBuf, MAX_LEN, MAX_LEN, pszFormat, ap);
    va_end(ap);

    WCHAR wszBuf[MAX_LEN] = {0};
    MultiByteToWideChar(CP_UTF8, 0, szBuf, -1, wszBuf, sizeof(wszBuf));
    OutputDebugStringW(wszBuf);
    OutputDebugStringA("\n");

    WideCharToMultiByte(CP_ACP, 0, wszBuf, sizeof(wszBuf), szBuf, sizeof(szBuf), NULL, FALSE);
    printf("%s\n", szBuf);
}

void CCMessageBox(const char * pszMsg, const char * pszTitle)
{
    MessageBoxA(NULL, pszMsg, pszTitle, MB_OK);
}

void CCLuaLog(const char *pszMsg)
{
    int bufflen = MultiByteToWideChar(CP_UTF8, 0, pszMsg, -1, NULL, 0);
    WCHAR* widebuff = new WCHAR[bufflen + 1];
    memset(widebuff, 0, sizeof(WCHAR) * (bufflen + 1));
    MultiByteToWideChar(CP_UTF8, 0, pszMsg, -1, widebuff, bufflen);

    OutputDebugStringW(widebuff);
    OutputDebugStringA("\n");

	bufflen = WideCharToMultiByte(CP_ACP, 0, widebuff, -1, NULL, 0, NULL, NULL);
	char* buff = new char[bufflen + 1];
	memset(buff, 0, sizeof(char) * (bufflen + 1));
	WideCharToMultiByte(CP_ACP, 0, widebuff, -1, buff, bufflen, NULL, NULL);
	puts(buff);

	if(_logFunction)
	{
		_logFunction(buff);
	}

	delete[] widebuff;
	delete[] buff;
}

struct CCStackTraceInfo
{
	const char* _func;
	int _ln;
	CCStackTraceInfo* _prev;
	CCStackTraceInfo* _next;
};

CCStackTraceInfo* _stack_trace_head = NULL;
CCStackTraceInfo* _current_stack_trace = NULL;

CCStackTrace::CCStackTrace(const char* func, int ln)
{	
	if(_current_stack_trace == NULL)
	{
		CCStackTraceInfo* info = new CCStackTraceInfo;
		info->_func = func;
		info->_ln = ln;
		info->_prev = NULL;
		info->_next = NULL;
		_current_stack_trace = info;
		_stack_trace_head = info;
	}
	else
	{
		if(_current_stack_trace->_next == NULL)
		{
			CCStackTraceInfo* info = new CCStackTraceInfo;
			info->_func = func;
			info->_ln = ln;
			info->_next = NULL;
			info->_prev = _current_stack_trace;
			_current_stack_trace->_next = info;
			_current_stack_trace = info;
		}
		else
		{
			_current_stack_trace = _current_stack_trace->_next;
			_current_stack_trace->_func = func;
			_current_stack_trace->_ln = ln;
		}		
	}
}

CCStackTrace::~CCStackTrace()
{
	if(_current_stack_trace)
	{
		_current_stack_trace = _current_stack_trace->_prev;
	}
}

CC_DLL std::string GetStackTraceString()
{
	if(_stack_trace_head == NULL)
	{
		return "";
	}

	std::string s;
	CCStackTraceInfo* info = _stack_trace_head;
	do
	{
		s += info->_func;
		s += ":";
		s += info->_ln;
		s += "\n";
	}while(info && info != _current_stack_trace);
	
	return s;
}

NS_CC_END
