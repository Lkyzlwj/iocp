#pragma once
#include "afxcmn.h"


// CChat �Ի���
#define WM_RECVDATA		WM_USER+1
class CChat : public CDialogEx
{
	DECLARE_DYNAMIC(CChat)

public:
	CChat(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChat();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg LRESULT OnRecvData(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	static DWORD WINAPI ReceiveMessageThread(LPVOID IpParameter);
	afx_msg void OnBnClickedButton2();
	SOCKET sockClient;
	afx_msg void OnBnClickedButton1();
	CListCtrl m_list1;
	void update(void);
	afx_msg void OnBnClickedButton3();
};
struct RECVPARAM1
{
	SOCKET socket;
	HWND hwnd;
};
