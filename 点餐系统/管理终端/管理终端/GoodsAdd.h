#pragma once


// CGoodsAdd �Ի���

class CGoodsAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CGoodsAdd)

public:
	CGoodsAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGoodsAdd();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
