
// OfflineDataStorgeTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// COfflineDataStorgeTestApp: 
// �йش����ʵ�֣������ OfflineDataStorgeTest.cpp
//

class COfflineDataStorgeTestApp : public CWinApp
{
public:
	COfflineDataStorgeTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern COfflineDataStorgeTestApp theApp;