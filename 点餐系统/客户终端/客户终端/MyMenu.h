#pragma once
#include "afxcmn.h"


// CMyMenu �Ի���

class CMyMenu : public CDialogEx
{
	DECLARE_DYNAMIC(CMyMenu)

public:
	CMyMenu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyMenu();

// �Ի�������
	enum { IDD = IDD_MY_MENU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	CListCtrl m_list1;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
