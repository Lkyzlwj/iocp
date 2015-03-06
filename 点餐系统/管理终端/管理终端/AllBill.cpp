// AllBill.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�����ն�.h"
#include "AllBill.h"
#include "afxdialogex.h"
#include <afxdb.h>

// CAllBill �Ի���

IMPLEMENT_DYNAMIC(CAllBill, CDialogEx)

CAllBill::CAllBill(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAllBill::IDD, pParent)
{

}

CAllBill::~CAllBill()
{
}

void CAllBill::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CAllBill, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAllBill::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAllBill::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAllBill::OnBnClickedButton3)
END_MESSAGE_MAP()


// CAllBill ��Ϣ�������


BOOL CAllBill::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,_T("�˵���"),LVCFMT_LEFT,80);
	m_list.InsertColumn(1,_T("�˺�"),LVCFMT_LEFT,80);
	m_list.InsertColumn(2,_T("����"),LVCFMT_LEFT,100);
	m_list.InsertColumn(3,_T("����"),LVCFMT_LEFT,80);
	m_list.InsertColumn(4,_T("�۸�"),LVCFMT_LEFT,80);

	CDatabase db;
    CRecordset rs(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT Bill_ID,Dishes_ID,Dishes_Name,Quantity,Price FROM Bill"));
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
		m_list.InsertItem(k,str,k);
		for( short index = 1; index < nFields; index++ )
		{
			rs.GetFieldValue( index, varValue );
			CString ss;
			if(index==3)
			{
				int temp=varValue.m_iVal ;
				ss.Format("%d",temp);
				ss=ss+"��";
			}
			else if(index==4)
			{
				int temp=varValue.m_iVal ;
				ss.Format("%d",temp);
				ss=ss+"Ԫ";
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

	return TRUE;  // return TRUE unless you set the focus to a control
}


void CAllBill::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString billid_of_find;
	GetDlgItemText(IDC_EDIT1,billid_of_find);
	if(billid_of_find=="")
		MessageBox("������Ҫ���ҵ��˵�ID��!");
	else
		Update(billid_of_find);
}


void CAllBill::Update(CString bill_of_find)
{
	m_list.DeleteAllItems();
	CDatabase db;
    CRecordset rs(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT Bill_ID,Dishes_ID,Dishes_Name,Quantity,Price FROM Bill"));	
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
		if(str!=bill_of_find)
		{
			rs.MoveNext( );
			continue;
		}
		m_list.InsertItem(k,str,k);
		for( short index = 1; index < nFields; index++ )
		{
			rs.GetFieldValue( index, varValue );
			CString ss;
			if(index==3)
			{
				int temp=varValue.m_iVal ;
				ss.Format("%d",temp);
				ss=ss+"��";
			}
			else if(index==4)
			{
				int temp=varValue.m_iVal ;
				ss.Format("%d",temp);
				ss=ss+"Ԫ";
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


void CAllBill::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}


void CAllBill::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedButton1();
}
