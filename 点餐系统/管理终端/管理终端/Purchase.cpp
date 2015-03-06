// Purchase.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�����ն�.h"
#include "Purchase.h"
#include "afxdialogex.h"
#include "�����ն�Dlg.h"
#include <afxdb.h>


// CPurchase �Ի���

IMPLEMENT_DYNAMIC(CPurchase, CDialogEx)

CPurchase::CPurchase(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPurchase::IDD, pParent)
{

}

CPurchase::~CPurchase()
{
}

void CPurchase::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CPurchase, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CPurchase::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPurchase::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CPurchase::OnBnClickedButton3)
END_MESSAGE_MAP()


// CPurchase ��Ϣ�������


BOOL CPurchase::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString("��Ʒ��");
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString("Ա��ID");
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString("��������");

	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,_T("��Ʒ��"),LVCFMT_LEFT,80);
	m_list.InsertColumn(1,_T("Ա��ID"),LVCFMT_LEFT,80);
	m_list.InsertColumn(2,_T("��Ʒ��"),LVCFMT_LEFT,80);
	m_list.InsertColumn(3,_T("��������"),LVCFMT_LEFT,100);
	m_list.InsertColumn(4,_T("��������"),LVCFMT_LEFT,80);

	CDatabase db;
    CRecordset rs(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT Goods_ID,Employee_ID,Goods_Name,Goods_Quantity,Purchase_Date  FROM Purchase"));
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


void CPurchase::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str1;
	CString str2;
	GetDlgItemText(IDC_COMBO2,str1);
	GetDlgItemText(IDC_EDIT1,str2);
	if(str1=="")
	{
		MessageBox("��ѡ���ѯ���!");
		return;
	}
	if(str2=="")
	{
		MessageBox("������Ҫ���ҵĹؼ���!");
		return;
	}
	else
	{
		if(str1=="��Ʒ��")
			Update1(str2);
		else if(str1=="Ա��ID")
			Update2(str2);
		else
			Update3(str2);
	}
}

void CPurchase::Update1(CString str)
{
	m_list.DeleteAllItems();
	CDatabase db;
    CRecordset rs(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT Goods_ID,Employee_ID,Goods_Name,Goods_Quantity,Purchase_Date  FROM Purchase"));
	CDBVariant varValue;
	short nFields = rs.GetODBCFieldCount( );
	int k=0;
	short index1=0;
	while( !rs.IsEOF( ) )
	{
		rs.GetFieldValue( index1, varValue );
		CString str1;
		str1=*varValue.m_pstring ;
		str1.TrimRight (" ");
		if(str1!=str)
		{
			rs.MoveNext( );
			continue;
		}
		m_list.InsertItem(k,str1,k);
		for( short index = 1; index < nFields; index++ )
		{
			rs.GetFieldValue( index, varValue );
			CString ss;
			if(index==3)
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



void CPurchase::Update2(CString str)
{
	m_list.DeleteAllItems();
	CDatabase db;
    CRecordset rs(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT Goods_ID,Employee_ID,Goods_Name,Goods_Quantity,Purchase_Date  FROM Purchase where Employee_ID="+str));
	CDBVariant varValue;
	short nFields = rs.GetODBCFieldCount( );
	int k=0;
	while( !rs.IsEOF( ) )
	{
		CString str1;
		rs.GetFieldValue( short(0), varValue );
		str1=*varValue.m_pstring ;
		str1.TrimRight (" ");
		m_list.InsertItem(k,str1,k);
		for( short index = 1; index < nFields; index++ )
		{
			rs.GetFieldValue( index, varValue );
			CString ss;
			if(index==3)
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


void CPurchase::Update3(CString str)
{
	m_list.DeleteAllItems();
	CDatabase db;
    CRecordset rs(&db);
	CRecordset rs2(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT Goods_ID,Employee_ID,Goods_Name,Goods_Quantity,Purchase_Date  FROM Purchase"));
	rs2.Open( 1,_T( "SELECT Goods_ID,Employee_ID,Goods_Name,Goods_Quantity,Purchase_Date  FROM Purchase"));
	CDBVariant varValue;
	short nFields = rs.GetODBCFieldCount( );
	int k=0;
	while( !rs.IsEOF( ) )
	{
		CString str1;
		rs2.GetFieldValue( short(4), varValue );
		
		str1=*varValue.m_pstring ;
		str1.TrimRight (" ");
		if(str1!=str)
		{
			rs2.MoveNext( );
			rs.MoveNext( );
			return;
		}
		rs.GetFieldValue( short(0), varValue );
		str1=*varValue.m_pstring ;
		str1.TrimRight (" ");
		m_list.InsertItem(k,str1,k);
		for( short index = 1; index < nFields; index++ )
		{
			rs.GetFieldValue( index, varValue );
			CString ss;
			if(index==3)
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
	rs2.Close();
	db.Close ();
}


void CPurchase::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedButton1();
}


void CPurchase::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	C�����ն�Dlg dlg;
	CDialog::OnOK();
	dlg.DoModal();
}
