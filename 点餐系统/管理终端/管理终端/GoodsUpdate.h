#pragma once


// CGoodsUpdate �Ի���

class CGoodsUpdate : public CDialogEx
{
	DECLARE_DYNAMIC(CGoodsUpdate)

public:
	CGoodsUpdate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGoodsUpdate();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
