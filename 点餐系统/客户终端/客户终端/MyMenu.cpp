// MyMenu.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ͻ��ն�.h"
#include "MyMenu.h"
#include "afxdialogex.h"
#include <afxdb.h>


// CMyMenu �Ի���

IMPLEMENT_DYNAMIC(CMyMenu, CDialogEx)

CMyMenu::CMyMenu(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyMenu::IDD, pParent)
{

}

CMyMenu::~CMyMenu()
{
}

void CMyMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}


BEGIN_MESSAGE_MAP(CMyMenu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyMenu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyMenu::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyMenu::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMyMenu ��Ϣ�������

extern CString client_id;
BOOL CMyMenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list1.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_list1.InsertColumn(0,_T("�˵���"),LVCFMT_LEFT,80);
	m_list1.InsertColumn(1,_T("�˺�"),LVCFMT_LEFT,80);
	m_list1.InsertColumn(2,_T("����"),LVCFMT_LEFT,100);
	m_list1.InsertColumn(3,_T("����"),LVCFMT_LEFT,80);
	m_list1.InsertColumn(4,_T("�۸�"),LVCFMT_LEFT,80);
	CDatabase db;
    CRecordset rs(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT Client_ID,Dishes_ID,Dishes_Name,Quantity,Price FROM Bill"));
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
		if(s!=client_id)
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

	return TRUE;  // return TRUE unless you set the focus to a control
}


void CMyMenu::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDatabase db;
    CRecordset rs(&db);
	int num=-1;
	num=m_list1.GetSelectionMark();
	CString s1=m_list1.GetItemText(num,0);//i���У�j���С�m_list�Ǹ�list control ����
	CString s2=m_list1.GetItemText(num,1);//i���У�j���С�m_list�Ǹ�list control ����
	if(num>=0)
	{
		if(MessageBox(_T("���Ҫɾ������ˣ�"),_T("��ʾ"),MB_YESNO|MB_ICONWARNING)==IDYES)
		{
			CString s=m_list1.GetItemText(num,0);
			db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
			rs.Open( 1,_T( "SELECT Bill_ID,Client_ID,Dishes_ID,Dishes_Name,Quantity,Price FROM Bill"),CRecordset::none);
			CString sql;//="delete from Bill where Bill_ID="+s ;
			sql.Format("delete from Bill where Bill_ID='%s' and Dishes_ID='%s'",s1,s2);
			db.ExecuteSQL (sql);
			rs.Close();
	        db.Close ();
			m_list1.DeleteItem(num);
		}
	}
	else
		MessageBox(_T("��ѡ��Ҫɾ���Ĳ�Ʒ��"),_T("��ʾ"),MB_OK|MB_ICONWARNING);
	m_list1.SetSelectionMark(-1);
}


void CMyMenu::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}


void CMyMenu::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}
