#pragma once


// CDeptUpdte �Ի���

class CDeptUpdte : public CDialogEx
{
	DECLARE_DYNAMIC(CDeptUpdte)

public:
	CDeptUpdte(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeptUpdte();

// �Ի�������
	enum { IDD = IDD_DIALOG10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
};
