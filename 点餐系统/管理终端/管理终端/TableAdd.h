#pragma once


// CTableAdd �Ի���

class CTableAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CTableAdd)

public:
	CTableAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTableAdd();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
