
// 043_Random4Multiply4Number.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy043_Random4Multiply4NumberApp: 
// �йش����ʵ�֣������ 043_Random4Multiply4Number.cpp
//

class CMy043_Random4Multiply4NumberApp : public CWinApp
{
public:
	CMy043_Random4Multiply4NumberApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy043_Random4Multiply4NumberApp theApp;