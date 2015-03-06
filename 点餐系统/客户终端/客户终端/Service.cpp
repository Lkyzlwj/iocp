// Service.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ͻ��ն�.h"
#include "Service.h"
#include "afxdialogex.h"
#include "Chat.h"
#include "DinnerMenu.h"
#include "ServiceVip.h"


// CService �Ի���

IMPLEMENT_DYNAMIC(CService, CDialogEx)

CService::CService(CWnd* pParent /*=NULL*/)
	: CDialogEx(CService::IDD, pParent)
{

}

CService::~CService()
{
}

void CService::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CService, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &CService::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CService::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CService::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &CService::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CService::OnBnClickedButton2)
END_MESSAGE_MAP()


// CService ��Ϣ�������


void CService::OnBnClickedButton4()
{
	CChat dlg;
	dlg.DoModal();
}


void CService::OnBnClickedButton3()
{
	static int num=1;//��¼�߲˴���
	CString str="";
	//����ǵ�һ�δ߲ˣ���Ҫ�����ӷ�����
	sockClient = socket(AF_INET, SOCK_STREAM, 0);  
	if(sockClient == INVALID_SOCKET) {     
		MessageBox("�׽��ִ���ʧ�ܣ�");
		WSACleanup();   
		return;   
	} 
	SOCKADDR_IN addrTo;
	addrTo.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	//addrTo.sin_addr.S_un.S_addr=inet_addr("192.168.137.5");
	addrTo.sin_family=AF_INET;
	addrTo.sin_port=htons(6000);
	if(SOCKET_ERROR == connect(sockClient, (SOCKADDR*)&addrTo, sizeof(SOCKADDR))){  
		MessageBox("���ӷ�����ʧ�ܣ�");
		return;  
	}
	send(sockClient,"51",3,0);
	Sleep(500);
	str.Format("%d", num);
	str="51"+str;
	int len=str.GetLength();
	send(sockClient,str,len,0);
	num++;
}


void CService::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//send(sockClient,"01$",4,0);
	CDialog::OnOK();
}


void CService::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDinnerMenu dlg;
	dlg.DoModal();
}


void CService::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CServiceVip dlg;
	if(IDOK==dlg.DoModal())
	{
		SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);  
		if(sockClient == INVALID_SOCKET) {     
			MessageBox("�׽��ִ���ʧ�ܣ�");
			WSACleanup();   
			return;   
		} 
		SOCKADDR_IN addrTo;
		addrTo.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
		addrTo.sin_family=AF_INET;
		addrTo.sin_port=htons(6000);
		if(SOCKET_ERROR == connect(sockClient, (SOCKADDR*)&addrTo, sizeof(SOCKADDR))){  
			MessageBox("���ӷ�����ʧ�ܣ�");
			return;  
		}
		send(sockClient,"01$",4,0);
	}
}
