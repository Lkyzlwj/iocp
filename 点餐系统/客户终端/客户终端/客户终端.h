
// �ͻ��ն�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ͻ��ն�App:
// �йش����ʵ�֣������ �ͻ��ն�.cpp
//

class C�ͻ��ն�App : public CWinApp
{
public:
	C�ͻ��ն�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ͻ��ն�App theApp;