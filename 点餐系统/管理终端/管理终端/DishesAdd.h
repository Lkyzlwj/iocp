#pragma once


// CDishesAdd �Ի���

class CDishesAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CDishesAdd)

public:
	CDishesAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDishesAdd();

// �Ի�������
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
