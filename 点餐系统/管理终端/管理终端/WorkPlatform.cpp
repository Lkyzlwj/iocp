// WorkPlatform.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�����ն�.h"
#include "WorkPlatform.h"
#include "afxdialogex.h"
#include "Chat.h"
#include "AllBill.h"
#include "�����ն�Dlg.h"
#include <afxdb.h>

// CWorkPlatform �Ի���

IMPLEMENT_DYNAMIC(CWorkPlatform, CDialogEx)

CWorkPlatform::CWorkPlatform(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWorkPlatform::IDD, pParent)
{

}

CWorkPlatform::~CWorkPlatform()
{
}

void CWorkPlatform::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_list);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}


BEGIN_MESSAGE_MAP(CWorkPlatform, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST3, &CWorkPlatform::OnClickList3)
	ON_MESSAGE(WM_RECVDATA,OnRecvData)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST3, &CWorkPlatform::OnDblclkList3)
	ON_BN_CLICKED(IDC_BUTTON1, &CWorkPlatform::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CWorkPlatform::OnBnClickedButton2)
END_MESSAGE_MAP()


// CWorkPlatform ��Ϣ�������

CString table_message[25];
BOOL CWorkPlatform::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CImageList * pImagelist;
	pImagelist=new CImageList();
	pImagelist->Create(32,32,ILC_COLOR32|ILC_MASK,10,0);
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	pImagelist->Add(&bmp,RGB(0,0,0));
	bmp.DeleteObject();

	bmp.LoadBitmap(IDB_BITMAP2);
	pImagelist->Add(&bmp,RGB(0,0,0));
	bmp.DeleteObject();

	bmp.LoadBitmap(IDB_BITMAP3);
	pImagelist->Add(&bmp,RGB(0,0,0));
	bmp.DeleteObject();

	CDatabase db1;
    CRecordset rs1(&db1);
	db1.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs1.Open( 1,_T( "SELECT count(distinct Table_ID) FROM Dinner_Table"));
	CDBVariant varValue1;
	short index1 = 0;
	rs1.GetFieldValue(index1, varValue1 );
	int num1=varValue1.m_iVal ;
	rs1.Close();
	db1.Close ();

	m_list.SetImageList(pImagelist,LVSIL_NORMAL);
	for(int i=0;i<num1;i++)
	{
		CString str;
		if(i+1<10)
		{
			str.Format("%d����",(i+1));
			str="0"+str;
		}
		else
			str.Format("%d����",(i+1));
		m_list.InsertItem(i,str,2);//m_list
	}
	m_tooltip.Create(this);
	InitSocket();
	//��ʼ����Ϣ�б�
	m_list1.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_list1.InsertColumn(0,_T("������"),LVCFMT_LEFT,70);
	m_list1.InsertColumn(1,_T("�߲˴���"),LVCFMT_LEFT,70);
	m_list1.InsertColumn(2,_T("�˵���"),LVCFMT_LEFT,70);
	table_message[1]="1�������������룬��λ����10";
	table_message[2]="2���������ߵ�����λ����8";
	table_message[3]="3��������������λ����8";
	table_message[4]="4�������������룬��λ����10";
	table_message[5]="5���������ߵ�����λ����8";
	table_message[6]="6��������������λ��:8";
	table_message[7]="7�������������룬��λ����10";
	table_message[8]="8������ˮ���ԣ���λ����8";
	table_message[9]="9��������ǧ�Σ���λ��:4";
	table_message[10]="10������ˮ���ԣ���λ��:8";
	table_message[11]="11�������������룬��λ��10";
	table_message[12]="12��������ǧ�Σ���λ��:4";
	table_message[13]="13������ˮ���ԣ���λ��:8";
	table_message[14]="14�������������룬��λ��:8";
	table_message[15]="15��������������λ��:8";
	table_message[16]="16�������������룬��λ��10";
	table_message[17]="17������ˮ���ԣ���λ��:8";
	table_message[18]="18��������ǧ�Σ���λ��:4";
	table_message[19]="19��������ǧ�Σ���λ����4";
	table_message[20]="20��������������λ����8";
	return TRUE;  // return TRUE unless you set the focus to a control
}


void CWorkPlatform::OnClickList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	*pResult = 0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos=m_list.GetFirstSelectedItemPosition();
	if(pos==NULL)
	{
		//MessageBox("�û�˫��λ�ô���");
	}
	else
	{
		CString str;
		int nItem=m_list.GetNextSelectedItem(pos);
		int index=nItem;
		str=m_list.GetItemText(nItem,0);
		int index_of_table_message=_ttoi(str);
	//	m_tt.Create(this);
		m_tooltip.AddTool(GetDlgItem(IDC_LIST3), table_message[index_of_table_message]);
		m_tooltip.SetMaxTipWidth(123);
		m_tooltip.Activate(TRUE);
	}
	*pResult = 0;
}


BOOL CWorkPlatform::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	ASSERT(pMsg != NULL);
	if (pMsg->message == WM_MOUSEMOVE || pMsg->message == WM_LBUTTONDOWN || pMsg->message == WM_LBUTTONUP)
		m_tooltip.RelayEvent(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}


bool CWorkPlatform::InitSocket(void)
{
	sockClient = socket(AF_INET, SOCK_STREAM, 0);  
     if(sockClient == INVALID_SOCKET) {     
		 MessageBox("�׽��ִ���ʧ�ܣ�");
        WSACleanup();   
        return false;   
      } 
	SOCKADDR_IN addrTo;
	addrTo.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	addrTo.sin_family=AF_INET;
	addrTo.sin_port=htons(6000);
	if(SOCKET_ERROR == connect(sockClient, (SOCKADDR*)&addrTo, sizeof(SOCKADDR))){  
		MessageBox("���ӷ�����ʧ�ܣ�");
		return false;  
	}
	send(sockClient,"00",3,0);
	RECVPARAM *pRecvParam=new RECVPARAM;
	pRecvParam->hwnd=this->m_hWnd;
	pRecvParam->socket=sockClient;
	HANDLE receiveThread = CreateThread(NULL, 0, ReceiveMessageThread,(LPVOID)pRecvParam, 0, NULL);
    CloseHandle(receiveThread);
	return TRUE;
}

DWORD WINAPI CWorkPlatform::ReceiveMessageThread(LPVOID IpParameter)  
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
bool isconnect[100];//�����жϹ����ն���ͼ���Ӧ�µķ����Ƿ��Ѿ����ӣ���û����������˫����Ϣ��Ӧ������
                   //���ܴ����Ӧ�ͻ��˵����촰��
CString bill_id;//�˵�id��������ʾ�˵���Ϣ�Ƕ����ݽ��й���
bool is_subit[25];//�����ж϶�Ӧ�Ĳ����Ŀ����Ƿ��Ѿ�����ȷ�ϵ��
LRESULT CWorkPlatform::OnRecvData(WPARAM wParam,LPARAM lParam)
{
	
	FILE *pFile1;
	CString str=(char*)lParam;
	if(str.GetLength()==9&&str.Mid(0,2)!="00"&&str[8]=='@')//������Ϊ9,�����һ���ַ�Ϊ@,���ǲ�����������Ϣ���м���λΪ�˵�id
	{
		CString str_index=str.Mid(0,2);
		int index=_ttoi(str_index);
		if(index<=25)//�Է����ε�½���׽��֣����ö�Ӧ��ͼ��Ϊ�Ѿ�����
		{
			m_list.DeleteItem(index-1);
			m_list.InsertItem(index-1,str_index+"����",0);
			isconnect[index]=true;//�ͻ����Ѿ����ӣ���ʱ���Դ򿪶�Ӧ�ĶԻ�����
			fopen_s(&pFile1,str_index+".txt","a+");//�����ļ�
			fclose(pFile1);

			int i=m_list1.GetItemCount();
			int length_of_str=str.GetLength();
			bill_id=str.Mid(2,length_of_str-3);
		    m_list1.InsertItem(i,str_index);     //�����Item��i����λ��,��Ȼ��¼������i��,�����һ������λ��Ϊi-1
		    m_list1.SetItemText(i, 1, "0");  //�߲˴���
		    m_list1.SetItemText(i, 2, bill_id); //�˵�id

			return true;
		}
		return true;
	}
	if(str.GetLength()==2)
	{
		int index=_ttoi(str);
		if(index>=26&&index<=50)return true;
	}
	if(str.GetLength()==3)
	{
		CString strindex=str.Mid(0,2);
		int index=_ttoi(strindex);
		if(index<=25&&str[2]=='*')//С�ڵ���25������ֵ����������趨��ȷ�ϵ��ʱ���͵ı�ʾ��*,˵����ȷ�ϵ��
		{
			is_subit[index]=true;
			return true;
		}
		if(index<=25&&str[2]=='$')//С�ڵ���25������ֵ����������趨��ȷ�ϸ���ʱ���͵ı�ʾ��$,˵����ȷ�ϸ���
		{
			m_list.DeleteItem(index-1);
			m_list.InsertItem(index-1,strindex+"����",1);//���ö�Ӧ��ͼ������ʾ����˹˿�ϣ��������
			return true;
		}
		if(index<=25&&str[2]=='l')//С�ڵ���25������ֵ����������趨�Ĺرմ���ʱ���͵ı�ʾ��l,˵���ǲ�����̨
		{
			is_subit[index]=false;//�ͻ���̨����Ӧ�����ж����Ƿ��Ѿ�����ȷ�ϵ�͵İ�ť��bool����ֵ��λ

			m_list.DeleteItem(index-1);
			m_list.InsertItem(index-1,strindex+"����",2);
			isconnect[index]=false;//�ͻ����Ѿ��˳�����ʱ���ܴ򿪶�Ӧ�ĶԻ���
			DeleteFile(strindex+".txt");
			int i=m_list1.GetItemCount();
			CString tempindex=str.Mid(0,2);
			CString strtemp;
			for(int j=0;j<i;j++)
			{
				strtemp=m_list1.GetItemText(j,0);
				if(strtemp==tempindex)
				{
					m_list1.DeleteItem(j);//�ͻ�����̨,ɾ����Ӧ����Ϣ
					break;
				}
			}
			return true;
		}
	}
	CString index2=str.Mid(0,2);;//�����ж������Ժ���������׽���
	int index3=_ttoi(index2);
	if(index3>=51&&index3<=75)//˵�������Ϣ���Ǵ߲���Ϣ
	{
		index3=index3-50;
		CString tempindex;
		if(index3<10)
		{
			tempindex.Format("%d", index3);
			tempindex="0"+tempindex;
		}
		else
			tempindex.Format("%d", index3);
		if(str.GetLength()>=3)//��С��3��˵���Ǵ߲��׽��ֵ�һ�η��������Խ������ӵ�,���ͨ�Ų������߲˴���
		{
			int length_of_str=str.GetLength();
			CString str2=str.Mid(2,length_of_str);
			/*if(str2=="1")
			{
				int i=m_list1.GetItemCount();
				m_list1.InsertItem(i,tempindex);     //�����Item��i����λ��,��Ȼ��¼������i��,�����һ������λ��Ϊi-1
				m_list1.SetItemText(i, 1, str2);
			}
			else
			{*/
				int i=m_list1.GetItemCount();
				CString strtemp;
				for(int j=0;j<i;j++)
				{
					strtemp=m_list1.GetItemText(j,0);
					if(strtemp==tempindex)
					{
						CString str3=m_list1.GetItemText(j,2);
						m_list1.DeleteItem(j);
						m_list1.InsertItem(j,tempindex);
						m_list1.SetItemText(j, 1, str2);
						m_list1.SetItemText(j, 2, str3);
						break;
					}
				}
			//}
		}
	}
	//////////����ΪΪ�������ϵĿͻ��������������¼���ĵ�,�Լ����ݿͻ��������˳�״̬���ö�Ӧ��ͼ��
	//////////����Ϊ�ڹ���˻�û�д����촰��ʱ�ɴ˸����ڽ������¼���浽��¼�ĵ�
	CString temp;//������������д���ĵ��ĳ�ν,���ڴ˸�����,�ʹ�������촰��û�д�,���������յ�����Ϣһ���ǿͻ�������
	temp=str.Mid(0,2);
	int index=_ttoi(temp);
	index=index-25;
	if(index<10)
	{
		temp.Format("%d", index);
		temp="0"+temp;
	}
	else
		temp.Format("%d", index);

	int length_of_str=str.GetLength();
	str=str.Mid(2,length_of_str);
	str=temp+":"+str;
	str=str+"\r\n";
	fopen_s(&pFile1,temp+".txt","a+");
	fwrite(str,1,strlen(str),pFile1);
	fclose(pFile1);
	return true;
}

CString tableindex;
void CWorkPlatform::OnDblclkList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	*pResult = 0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos=m_list.GetFirstSelectedItemPosition();
	if(pos==NULL)
	{
		//MessageBox("�û�˫��λ�ô���");
	}
	else
	{
		CString str;
		int nItem=m_list.GetNextSelectedItem(pos);
		int index=nItem;
		str=m_list.GetItemText(nItem,0);
		tableindex=str.Mid(0,2);
		int i=m_list1.GetItemCount();
		CString strtemp;
		for(int j=0;j<i;j++)
		{
			strtemp=m_list1.GetItemText(j,0);
			if(strtemp==tableindex)
			{
				bill_id=m_list1.GetItemText(j,2);//��ʱbill�����˴�ʱʹ�ô�̨���Ĺ˿�����Ӧ�Ķ�����
				break;
			}
		}
	}
	int index=_ttoi(tableindex);
	if(isconnect[index]==true)
	{
		CChat *dlg=new CChat;
		dlg->Create(IDD_DIALOG2,this);
		dlg->ShowWindow(SW_SHOW);
	}
	*pResult = 0;
}


void CWorkPlatform::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAllBill dlg;
	dlg.DoModal();
}


void CWorkPlatform::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	C�����ն�Dlg dlg;
	CDialog::OnOK();
	dlg.DoModal();
}
