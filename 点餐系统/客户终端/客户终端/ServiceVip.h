#pragma once
#include "afxcmn.h"


// CServiceVip �Ի���

class CServiceVip : public CDialogEx
{
	DECLARE_DYNAMIC(CServiceVip)

public:
	CServiceVip(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CServiceVip();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton4();
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
};
