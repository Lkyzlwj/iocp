#pragma once


// CDishesUpdate �Ի���

class CDishesUpdate : public CDialogEx
{
	DECLARE_DYNAMIC(CDishesUpdate)

public:
	CDishesUpdate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDishesUpdate();

// �Ի�������
	enum { IDD = IDD_DIALOG8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
