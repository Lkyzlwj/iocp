// DinnerMenu.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ͻ��ն�.h"
#include "DinnerMenu.h"
#include "afxdialogex.h"
#include <afxdb.h>
#include "MyMenu.h"


// CDinnerMenu �Ի���

IMPLEMENT_DYNAMIC(CDinnerMenu, CDialogEx)

CDinnerMenu::CDinnerMenu(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDinnerMenu::IDD, pParent)
{

}

CDinnerMenu::~CDinnerMenu()
{
}

void CDinnerMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_STATIC1, m_pic);
}


BEGIN_MESSAGE_MAP(CDinnerMenu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDinnerMenu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDinnerMenu::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDinnerMenu::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDinnerMenu::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDinnerMenu::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDinnerMenu::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDinnerMenu::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDinnerMenu::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CDinnerMenu::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CDinnerMenu::OnBnClickedButton10)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CDinnerMenu::OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON11, &CDinnerMenu::OnBnClickedButton11)
END_MESSAGE_MAP()


// CDinnerMenu ��Ϣ�������

extern CString bill_id;
extern CString client_id;
BOOL CDinnerMenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,_T("�˺�"),LVCFMT_LEFT,67);
	m_list.InsertColumn(1,_T("����"),LVCFMT_LEFT,67);
	m_list.InsertColumn(2,_T("�۸�"),LVCFMT_LEFT,67);

	CDatabase db;
    CRecordset rs(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT Dishes_ID ,Dishes_Name ,Dishes_Price  FROM Dishes_List"));
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
		m_list.InsertItem(k,s,k);
		for( short index = 1; index < nFields; index++ )
		{
			rs.GetFieldValue( index, varValue );
			CString s;
			if(index==2)
			{
				int temp=varValue.m_iVal ;
				s.Format("%d",temp);
			}
			else
				s=*varValue.m_pstring ;
			s.TrimRight (" ");
			m_list.SetItemText(k,index,s);

		}
		rs.MoveNext( );
		k++;
	}
	rs.Close();
	db.Close ();
	return TRUE;  // return TRUE unless you set the focus to a control
}


void CDinnerMenu::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDatabase db;
    CRecordset rs(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT Bill_ID ,Client_ID ,Dishes_ID ,Dishes_Name,Quantity,Price  FROM Bill"));
	CDBVariant varValue;
	int num=-1;
	num=m_list.GetSelectionMark();
	//CString s1=bill_id;
	CString s1=client_id;
	CString s2=client_id;
	CString s3=m_list.GetItemText(num,0);//�˺�
	CString s4=m_list.GetItemText(num,1);//����
	CString s5="1";                      //����
	CString s6=m_list.GetItemText(num,2);//�۸�
	short index=1;
	short index1=2;
	short index2=4;
	while( !rs.IsEOF( ) )
	{
		rs.GetFieldValue( index, varValue );
		CString s;
		CString ss;
		s=*varValue.m_pstring ;
		s.TrimRight (" ");//�ͻ�id
		rs.GetFieldValue( index1, varValue );
		ss=*varValue.m_pstring ;
		ss.TrimRight (" ");//�˺�
		if((s==s2)&&(ss==s3))
		{
			rs.GetFieldValue( index2, varValue );
			int n=1+varValue.m_iVal;//ȡ��ԭ������������һ
			char buf[100];
			sprintf_s(buf,"update Bill set Quantity=%d where Dishes_ID="+s3,n);
			CString sql=(char*)buf;
			db.ExecuteSQL (sql);
			rs.Close();
			db.Close ();
			return;
		}
		rs.MoveNext( );
	}
	//������ִ��˵�����ǹ˿͵�һ�ε������
	CString sql="insert into Bill values('"+s1+"','"+s2+"','"+s3+"','"+s4+"','"+s5+"','"+s6+"')";
	db.ExecuteSQL (sql);
	rs.Close();
	db.Close ();
}


void CDinnerMenu::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	send(sockClient,"01*",4,0);
}


void CDinnerMenu::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMyMenu dlg;
	dlg.DoModal();
}

void CDinnerMenu::Update(char s)
{
	m_list.DeleteAllItems();
	CDatabase db;
    CRecordset rs(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT Dishes_ID ,Dishes_Name ,Dishes_Price,Dishes_Classification  FROM Dishes_List"));
	CDBVariant varValue;
	short nFields = rs.GetODBCFieldCount( );
	int k=0;
	short index1=0;
	while( !rs.IsEOF( ) )
	{
		rs.GetFieldValue( index1, varValue );
		CString str;
		str=*varValue.m_pstring ;
		str.TrimRight (" ");
		if(str[0]!=s)
		{
			rs.MoveNext( );
			continue;
		}
		m_list.InsertItem(k,str,k);
		for( short index = 1; index < nFields-1; index++ )
		{
			rs.GetFieldValue( index, varValue );
			CString ss;
			if(index==2)
			{
				int temp=varValue.m_iVal ;
				ss.Format("%d",temp);
			}
			else
				ss=*varValue.m_pstring ;
			ss.TrimRight (" ");
			m_list.SetItemText(k,index,ss);

		}
		rs.MoveNext( );
		k++;
	}
	rs.Close();
	db.Close ();
}

void CDinnerMenu::OnBnClickedButton4()
{
	Update('1');
}


void CDinnerMenu::OnBnClickedButton5()
{
	Update('2');
}


void CDinnerMenu::OnBnClickedButton6()
{
	Update('3');
}


void CDinnerMenu::OnBnClickedButton7()
{
	Update('4');
}


void CDinnerMenu::OnBnClickedButton8()
{
	Update('5');
}


void CDinnerMenu::OnBnClickedButton9()
{
	Update('6');
}


void CDinnerMenu::OnBnClickedButton10()
{
	Update('7');
}


void CDinnerMenu::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	*pResult = 0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str="E:/����ͼ/";
	int num=m_list.GetSelectionMark();
	CString s1=m_list.GetItemText(num,0);//��ò˺�
	HBITMAP  hBmp; 
	hBmp=(HBITMAP)LoadImage(AfxGetInstanceHandle(),str+s1+".bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	m_pic.SetBitmap(hBmp);
	*pResult = 0;
}


void CDinnerMenu::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}
