#pragma once
#include "afxcmn.h"


// CAllBill �Ի���

class CAllBill : public CDialogEx
{
	DECLARE_DYNAMIC(CAllBill)

public:
	CAllBill(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAllBill();

// �Ի�������
	enum { IDD = IDD_ALL_BILL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	void Update(CString bill_of_find);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
