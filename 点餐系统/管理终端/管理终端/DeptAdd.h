#pragma once


// CDeptAdd �Ի���

class CDeptAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CDeptAdd)

public:
	CDeptAdd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeptAdd();

// �Ի�������
	enum { IDD = IDD_DIALOG9 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
