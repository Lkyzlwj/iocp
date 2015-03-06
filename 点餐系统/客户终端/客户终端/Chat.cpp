// Chat.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ͻ��ն�.h"
#include "Chat.h"
#include "afxdialogex.h"


// CChat �Ի���

IMPLEMENT_DYNAMIC(CChat, CDialogEx)

CChat::CChat(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChat::IDD, pParent)
{

}

CChat::~CChat()
{
}

void CChat::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChat, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CChat::OnBnClickedButton1)
	ON_MESSAGE(WM_RECVDATA,OnRecvData)
	ON_BN_CLICKED(IDC_BUTTON2, &CChat::OnBnClickedButton2)
END_MESSAGE_MAP()


// CChat ��Ϣ�������


bool CChat::InitSocket(void)
{
	sockClient = socket(AF_INET, SOCK_STREAM, 0);  
     if(sockClient == INVALID_SOCKET) {     
		 MessageBox("�׽��ִ���ʧ�ܣ�");
        WSACleanup();   
        return false;   
      } 
	SOCKADDR_IN addrTo;
	addrTo.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	//addrTo.sin_addr.S_un.S_addr=inet_addr("192.168.23.4");
	addrTo.sin_family=AF_INET;
	addrTo.sin_port=htons(6000);
	if(SOCKET_ERROR == connect(sockClient, (SOCKADDR*)&addrTo, sizeof(SOCKADDR))){  
		MessageBox("���ӷ�����ʧ�ܣ�");
		return false;  
	}
	send(sockClient,"26",3,0);//�����׽��ֱ��ʹ������������Ӧ�׽���
	RECVPARAM *pRecvParam=new RECVPARAM;
	pRecvParam->hwnd=this->m_hWnd;
	pRecvParam->socket=sockClient;
	HANDLE receiveThread = CreateThread(NULL, 0, ReceiveMessageThread,(LPVOID)pRecvParam, 0, NULL);
    CloseHandle(receiveThread);
	return TRUE;
}

DWORD WINAPI CChat::ReceiveMessageThread(LPVOID IpParameter)  
{ 
	static int rcv=0;
	SOCKET socket=((RECVPARAM*)IpParameter)->socket;
	HWND hwnd=((RECVPARAM*)IpParameter)->hwnd;
	delete IpParameter;
	char recvBuf[1200]; 
	while(1){     
		recv(socket, recvBuf, 1024, 0);
		::PostMessage(hwnd,WM_RECVDATA,0,(LPARAM)recvBuf);
	} 
	return 0;
}
LRESULT CChat::OnRecvData(WPARAM wParam,LPARAM lParam)
{
	CString str=(char*)lParam;
	CString str1=str.Mid(0,2);
	CString temp;//������ʱ��¼�ͻ��˶��׽�������Ա㻹ԭ�ɶ�Ӧ�Ĳ�����
	int index=_ttoi(str1);
	CString strTemp;
	int length_of_str=str.GetLength();
	str=str.Mid(2,length_of_str);
	if(index>=1&&index<=25)//�ɹ���˷�������Ϣ
	{
		str="�����:"+str;
	}
	if(index>=26&&index<=50)//�ɿͻ��˷��ظ��Լ���
	{
		index=index-25;
		if(index<10)
		{
			temp.Format("%d", index);
			temp="0"+temp;
		}
		else
			temp.Format("%d", index);
		str=temp+":"+str;
	}
	str+="\r\n";
	GetDlgItemText(IDC_EDIT_RECV,strTemp);
	
	str=strTemp+str;
	SetDlgItemText(IDC_EDIT_RECV,str);
	return true;
}





BOOL CChat::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	InitSocket();
	return TRUE;  // return TRUE unless you set the focus to a control
}





void CChat::OnBnClickedButton1()
{
	int len;//����CString���ַ�����Ŀ
	WSABUF wsabuf;
	CString getstr;
	//CString strTemp2;//��ȡ����
	GetDlgItemText(IDC_EDIT_SEND,getstr);
	getstr="26"+getstr;
	//getstr=strTemp2+"\r\n"+getstr;
	len=getstr.GetLength();
	wsabuf.buf=(CHAR*)getstr.GetBuffer(len);
	wsabuf.len=len+1;
	send(sockClient, getstr, 200, 0);
	SetDlgItemText(IDC_EDIT_SEND,TEXT(""));
}


void CChat::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedButton1();
}
