
// �����ն�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�����ն�App:
// �йش����ʵ�֣������ �����ն�.cpp
//

class C�����ն�App : public CWinApp
{
public:
	C�����ն�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�����ն�App theApp;