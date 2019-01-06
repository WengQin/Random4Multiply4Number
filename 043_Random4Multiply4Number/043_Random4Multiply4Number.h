
// 043_Random4Multiply4Number.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CMy043_Random4Multiply4NumberApp: 
// 有关此类的实现，请参阅 043_Random4Multiply4Number.cpp
//

class CMy043_Random4Multiply4NumberApp : public CWinApp
{
public:
	CMy043_Random4Multiply4NumberApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy043_Random4Multiply4NumberApp theApp;