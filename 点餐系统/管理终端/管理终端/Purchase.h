#pragma once
#include "afxcmn.h"


// CPurchase �Ի���

class CPurchase : public CDialogEx
{
	DECLARE_DYNAMIC(CPurchase)

public:
	CPurchase(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPurchase();

// �Ի�������
	enum { IDD = IDD_PURCHASE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	void Update1(CString str);
	void Update2(CString str);
	void Update3(CString str);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
