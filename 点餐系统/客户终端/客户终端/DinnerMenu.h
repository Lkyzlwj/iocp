#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CDinnerMenu �Ի���

class CDinnerMenu : public CDialogEx
{
	DECLARE_DYNAMIC(CDinnerMenu)

public:
	CDinnerMenu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDinnerMenu();

// �Ի�������
	enum { IDD = IDD_DINNER_MENU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
//	void Update(CString s);
	void Update(char s);
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	CStatic m_pic;
	afx_msg void OnBnClickedButton11();
};
