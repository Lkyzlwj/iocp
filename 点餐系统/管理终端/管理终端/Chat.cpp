// Chat.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�����ն�.h"
#include "Chat.h"
#include "afxdialogex.h"
#include <afxdb.h>


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
	DDX_Control(pDX, IDC_LIST1, m_list1);
}


BEGIN_MESSAGE_MAP(CChat, CDialogEx)
	ON_MESSAGE(WM_RECVDATA,OnRecvData)
	ON_BN_CLICKED(IDC_BUTTON2, &CChat::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CChat::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CChat::OnBnClickedButton3)
END_MESSAGE_MAP()


// CChat ��Ϣ�������
static bool isfirst;//����Ի����ʱ��txt�ĵ��ж�ȡ��¼,��Ϊ���β���˻��з�,Ϊ����Ի����ڵ�һ�ν�������ʱ
                    //�ظ���ӻ��з�,����˱������ж�
extern CString tableindex;
extern CString bill_id;
extern bool is_subit[25];
BOOL CChat::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//=============================================================================================
	//==============================��ȡ�ı��ĵ��е������¼=======================================
	isfirst=true;//�տ�ʼ�򿪶Ի�����Ϊtrue
	FILE *pFile;
	long curpos,length;
	char *ch;
	fopen_s(&pFile,tableindex+".txt","rb");
	curpos=ftell(pFile);
	fseek(pFile,0L,SEEK_END);
	length=ftell(pFile);
	fseek(pFile,curpos,SEEK_SET);
	ch=new char[length+1];
	fread(ch,1,length,pFile);
	ch[length]=0;
	fclose(pFile);
	SetDlgItemText(IDC_RECV,ch);
	delete [] ch;
	//=============================================================================================
	//=================================��������ͨ�ŵ��׽���========================================
	sockClient = socket(AF_INET, SOCK_STREAM, 0);  
	if(sockClient == INVALID_SOCKET) {     
		MessageBox("�׽��ִ���ʧ�ܣ�");
		WSACleanup();   
		return false;   
	} 
	SOCKADDR_IN addrTo;
	addrTo.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	//addrTo.sin_addr.S_un.S_addr=inet_addr("192.168.137.5");
	addrTo.sin_family=AF_INET;
	addrTo.sin_port=htons(6000);
	if(SOCKET_ERROR == connect(sockClient, (SOCKADDR*)&addrTo, sizeof(SOCKADDR))){  
		MessageBox("���ӷ�����ʧ�ܣ�");
		return false;  
	}
	int tableindex2=_ttoi(tableindex);
	tableindex2=tableindex2+75;
	CString tableindex3;
	tableindex3.Format("%d", tableindex2);
	
	send(sockClient,tableindex3,3,0);//��֪�������˹�������촰�ڵ��׽������
	//�������������߳�
	RECVPARAM1 *pRecvParam=new RECVPARAM1;
	pRecvParam->hwnd=this->m_hWnd;
	pRecvParam->socket=sockClient;
	HANDLE receiveThread = CreateThread(NULL, 0, ReceiveMessageThread,(LPVOID)pRecvParam, 0, NULL);
    CloseHandle(receiveThread);
	GetDlgItem(IDC_STATIC)->SetWindowTextA(tableindex);
	GetDlgItem(IDC_STATIC1)->SetWindowTextA(bill_id);

	//===========================================================================================
	//=================================��ʼ���ͻ��˵���==========================================
	m_list1.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_list1.InsertColumn(0,_T("�˵���"),LVCFMT_LEFT,80);
	m_list1.InsertColumn(1,_T("�˺�"),LVCFMT_LEFT,80);
	m_list1.InsertColumn(2,_T("����"),LVCFMT_LEFT,100);
	m_list1.InsertColumn(3,_T("����"),LVCFMT_LEFT,80);
	m_list1.InsertColumn(4,_T("�۸�"),LVCFMT_LEFT,80);

	//===========================================================================================
	//=================================��ʾ��Ӧ�ͻ��˵�==========================================
	CString is_subit_index;
	GetDlgItemText(IDC_STATIC,is_subit_index);
	int subit_index=_ttoi(is_subit_index);
	if(is_subit[subit_index]==true)//˵���ͻ��Ѿ�����ȷ�ϵ�Ͱ�ť����ʱ������ʾ���˵�
		update();
	//===========================================================================================
	return TRUE;  // return TRUE unless you set the focus to a control
}

DWORD WINAPI CChat::ReceiveMessageThread(LPVOID IpParameter)  
{ 
	static int rcv=0;
	SOCKET socket=((RECVPARAM1*)IpParameter)->socket;
	HWND hwnd=((RECVPARAM1*)IpParameter)->hwnd;
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
	CString strTemp;
	CString temp;
	int length_of_str=str.GetLength();
	FILE *pFile1;
	temp=str.Mid(0,2);
	int index=_ttoi(temp);
	int index1=index;
	if(index>=26&&index<=50)//��ʾ������Ϣ���ɿͻ�������
		index=index-25;//��ԭ��������ԭ������Ա��ҵ���Ӧ�ļ�¼�ĵ�����д��
	str=str.Mid(2,length_of_str);
	if(index<10)
	{
		temp.Format("%d", index);
		temp="0"+temp;
	}
	else
		temp.Format("%d", index);
	if(index1>=26&&index1<=50)//˵��������Ϣ���ɿͻ�������,���ö�Ӧ�ĳ�ν
		str=temp+":"+str;
	if(index>=1&&index1<=25)//˵��������Ϣ���ɹ���˷��ظ��Լ���,���ö�Ӧ�ĳ�ν
		str="�����:"+str;
	str+="\r\n";
	fopen_s(&pFile1,temp+".txt","a+");
	fwrite(str,1,strlen(str),pFile1);
	fclose(pFile1);

	GetDlgItemText(IDC_RECV,strTemp);
	str=strTemp+str;
	SetDlgItemText(IDC_RECV,str);
	return true;
}



void CChat::PostNcDestroy()
{
	// TODO: �ڴ����ר�ô����/����û���
	delete this;
	CDialogEx::PostNcDestroy();
}


void CChat::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tableindexnow;
	
	GetDlgItem(IDC_STATIC)->GetWindowTextA(tableindexnow);
	int inttableindex=_ttoi(tableindexnow);
	inttableindex=inttableindex+75;
	tableindexnow.Format("%d", inttableindex);
	send(sockClient, tableindexnow+"#", 4, 0);//�ر����촰�ڵı�ʾ�ĳ�#
	CDialog::OnOK();
}


void CChat::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tableindexnow;
	GetDlgItem(IDC_STATIC)->GetWindowTextA(tableindexnow);
	int len;//����CString���ַ�����Ŀ
	WSABUF wsabuf;
	CString getstr;
	//CString strTemp2;//��ȡ����
	GetDlgItemText(IDC_SEND,getstr);
	getstr=tableindexnow+getstr;
	//getstr=tableindex+getstr;//------------------------------------------
	//getstr=strTemp2+"\r\n"+getstr;
	len=getstr.GetLength();
	wsabuf.buf=(CHAR*)getstr.GetBuffer(len);
	wsabuf.len=len+1;
	send(sockClient, getstr, 200, 0);
	SetDlgItemText(IDC_SEND,TEXT(""));
}


void CChat::update(void)
{
	CDatabase db;
    CRecordset rs(&db);
	CString Bill_ID;
	GetDlgItem(IDC_STATIC1)->GetWindowTextA(Bill_ID);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT Bill_ID,Dishes_ID,Dishes_Name,Quantity,Price FROM Bill"));
	CDBVariant varValue;
	short nFields = rs.GetODBCFieldCount( );
	int k=0;
	short index1=0;
	while( !rs.IsEOF( ) )
	{
		rs.GetFieldValue( index1, varValue );
		CString s;
		s=*varValue.m_pstring ;
		s.TrimRight (" ");
		if(s!=Bill_ID)
		{
			rs.MoveNext( );
			continue;
		}
		m_list1.InsertItem(k,s,k);
		for( short index = 1; index < nFields; index++ )
		{
			rs.GetFieldValue( index, varValue );
			CString s;
			if(index==3)
			{
				int age=varValue.m_iVal ;
				s.Format("%d",age);
				s=s+"��";
			}
			else if(index==4)
			{
				int age=varValue.m_iVal ;
				s.Format("%d",age);
				s=s+"Ԫ";
			}
			else
				s=*varValue.m_pstring ;
			s.TrimRight (" ");
			m_list1.SetItemText(k,index,s);
		}
		rs.MoveNext( );
		k++;
	}
	rs.Close();
	db.Close ();
}


void CChat::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedButton1();
}
