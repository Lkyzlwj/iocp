#pragma once
#include "afxcmn.h"


// CWorkPlatform �Ի���
#define WM_RECVDATA		WM_USER+1
class CWorkPlatform : public CDialogEx
{
	DECLARE_DYNAMIC(CWorkPlatform)

public:
	CWorkPlatform(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CWorkPlatform();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg LRESULT OnRecvData(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	CToolTipCtrl m_tooltip;
	afx_msg void OnClickList3(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	static DWORD WINAPI ReceiveMessageThread(LPVOID IpParameter);
private:
	SOCKET sockClient;
public:
	bool InitSocket(void);
	afx_msg void OnDblclkList3(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_list1;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
struct RECVPARAM
{
	SOCKET socket;
	HWND hwnd;
};
