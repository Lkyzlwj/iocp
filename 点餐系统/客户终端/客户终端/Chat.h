#pragma once


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
private:
	SOCKET sockClient;
public:
	bool InitSocket(void);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	static DWORD WINAPI ReceiveMessageThread(LPVOID IpParameter);
	afx_msg void OnBnClickedButton2();
};
struct RECVPARAM
{
	SOCKET socket;
	HWND hwnd;
};