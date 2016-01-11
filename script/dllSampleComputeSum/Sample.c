

#include <TChar.h>
#include "mm_jsapi.h"
#include <windows.h>




// A sample function
// Every implementation of a Javascript function must have this signature
JSBool computeSum(JSContext *cx, JSObject *obj,  unsigned int argc,   jsval *argv, jsval *rval)
{
	long a, b,  sum;

	//wchar_t file[256];
	const wchar_t* file = L"D:\\lol\\trunk\\clientdata2.1.3\\script\\parsexml.bat";
	//wchar_t param[256];
	const wchar_t* param = L"";
	//param[0] = 0;
	//wchar_t dir[256];
	const wchar_t* dir = L"D:\\lol\\trunk\\clientdata2.1.3\\script";

	// Make sure the right number of arguments were passed in
	if (argc != 2)
		return JS_FALSE;

	// Convert the two arguments from jsvals to longs
	if (JS_ValueToInteger(cx, argv[0], &a) == JS_FALSE ||
		JS_ValueToInteger(cx, argv[1], &b) == JS_FALSE)
		return JS_FALSE;

	// Perform the actual work
	sum = a + b;

	// Package the return value as a jsval
	*rval = JS_IntegerToValue(sum);


	// Perform the actual work
	ShellExecute(NULL, L"open", file, param, dir, SW_SHOWNORMAL);

	// Indicate success
	return JS_TRUE;
}


JSBool executeCmd(JSContext *cx, JSObject *obj,  unsigned int argc,   jsval *argv, jsval *rval)
{
	wchar_t* param;
	wchar_t* dir;
	wchar_t* file;
	unsigned int dir_len;
	unsigned int file_len;
	unsigned int param_len;
	long rtn;
	
	// 取得参数
	if (argc != 3)
	{
		return JS_FALSE;
	}
		
	dir = JS_ValueToString(cx, argv[0], &dir_len);
	if(dir == NULL || dir_len == 0)
	{
		dir = L"";
	}
	file = JS_ValueToString(cx, argv[1], &file_len);
	if(file == NULL || file_len == 0)
	{
		return JS_FALSE;
	}
	param = JS_ValueToString(cx, argv[2], &param_len);
	if(param == NULL || param_len == 0)
	{
		param = L"";
	}

	// 执行
	rtn = (long)ShellExecute(NULL, L"open", file, param, dir, SW_SHOWNORMAL);

	// 设置返回值
	*rval = JS_IntegerToValue(rtn);

	return JS_TRUE;
}


// MM_STATE is a macro that expands to some definitions that are

// needed in order interact with Flash.  This macro must be
// defined exactly once in your library
MM_STATE


// Flash calls MM_Init when your library is loaded
void
MM_Init()
{
	// sample function
	JS_DefineFunction(_T("computeSum"),			computeSum,			2);
	JS_DefineFunction(_T("executeCmd"),			executeCmd,			3);
}


void
MM_Terminate()
{
	// clean up memory here
}
