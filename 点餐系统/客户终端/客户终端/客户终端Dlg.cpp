
// �ͻ��ն�Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ͻ��ն�.h"
#include "�ͻ��ն�Dlg.h"
#include "afxdialogex.h"
#include "Service.h"
#include "ServiceVip.h"
#include <afxdb.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C�ͻ��ն�Dlg �Ի���



C�ͻ��ն�Dlg::C�ͻ��ն�Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�ͻ��ն�Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�ͻ��ն�Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C�ͻ��ն�Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C�ͻ��ն�Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &C�ͻ��ն�Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// C�ͻ��ն�Dlg ��Ϣ�������

BOOL C�ͻ��ն�Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�ͻ��ն�Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C�ͻ��ն�Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�ͻ��ն�Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


SOCKET sockClient;
CString bill_id;
CString client_id;
void C�ͻ��ն�Dlg::OnBnClickedButton1()
{
	/*CDatabase db;
    CRecordset rs(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT count(distinct Bill_ID) FROM Bill"));
	//rs.Open( 1,_T( "Bill_ID FROM Bill"));
	CDBVariant varValue;
	short index = 0;
	rs.GetFieldValue(index, varValue );
	int num=1+varValue.m_iVal ;
	CString num_str;
	num_str.Format("%d",num);
	num_str="00000"+num_str;
	int length_of_num_str=num_str.GetLength();
	num_str=num_str.Mid(length_of_num_str-6,length_of_num_str);
	rs.Close();
	db.Close ();*/
	CDatabase db1;
    CRecordset rs1(&db1);
	db1.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs1.Open( 1,_T( "SELECT count(distinct Client_ID) FROM Client"));
	CDBVariant varValue1;
	short index1 = 0;
	rs1.GetFieldValue(index1, varValue1 );
	int num1=1+varValue1.m_iVal ;
	CString num_client;
	num_client.Format("%d",num1);
	num_client="00000"+num_client;
	int length_of_num_client = num_client.GetLength();
	num_client=num_client.Mid(length_of_num_client-6,length_of_num_client);
	rs1.Close();
	db1.Close ();
	client_id=num_client;
	//��ʱnum_client�ﱣ���������˿͵�id
	sockClient = socket(AF_INET, SOCK_STREAM, 0);  
	if(sockClient == INVALID_SOCKET) {     
		MessageBox("�׽��ִ���ʧ�ܣ�");
		WSACleanup();   
		return;   
	} 
	SOCKADDR_IN addrTo;
	addrTo.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	//addrTo.sin_addr.S_un.S_addr=inet_addr("192.168.23.4");
	addrTo.sin_family=AF_INET;
	addrTo.sin_port=htons(6000);
	if(SOCKET_ERROR == connect(sockClient, (SOCKADDR*)&addrTo, sizeof(SOCKADDR))){  
		MessageBox("���ӷ�����ʧ�ܣ�");
		return;  
	}
	send(sockClient,"01"+num_client+"@",10,0);//num_str�˹˿͵��˵�ID
	bill_id=num_client;

	

	CString Table_ID="001";
	CString Client_Message="";
	CDatabase db2;
    CRecordset rs2(&db2);
	db2.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs2.Open( 1,_T( "SELECT Client_ID,Table_ID,Client_Message  FROM Client"));
	CString sql="insert into Client values('"+num_client+"','"+Table_ID+"','"+Client_Message+"')";
	db2.ExecuteSQL(sql);
	rs2.Close();
	db2.Close ();
	CService dlg;
	CDialog::OnOK();
	if(IDOK==dlg.DoModal())
	{
		send(sockClient,"01l",4,0);
		CDialog::OnOK();
	}
}


void C�ͻ��ն�Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	send(sockClient,"01l",4,0);
	CDialog::OnOK();
}
