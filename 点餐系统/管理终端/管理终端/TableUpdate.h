#pragma once


// CTableUpdate �Ի���

class CTableUpdate : public CDialogEx
{
	DECLARE_DYNAMIC(CTableUpdate)

public:
	CTableUpdate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTableUpdate();

// �Ի�������
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
