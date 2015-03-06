// ServiceVip.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ͻ��ն�.h"
#include "ServiceVip.h"
#include "afxdialogex.h"
#include "Chat.h"
#include <afxdb.h>

// CServiceVip �Ի���

IMPLEMENT_DYNAMIC(CServiceVip, CDialogEx)

CServiceVip::CServiceVip(CWnd* pParent /*=NULL*/)
	: CDialogEx(CServiceVip::IDD, pParent)
{

}

CServiceVip::~CServiceVip()
{
}

void CServiceVip::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CServiceVip, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON6, &CServiceVip::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON4, &CServiceVip::OnBnClickedButton4)
END_MESSAGE_MAP()


// CServiceVip ��Ϣ�������


void CServiceVip::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}

void CServiceVip::OnBnClickedButton4()
{
	CChat dlg;
	dlg.DoModal();
}

extern CString client_id;
BOOL CServiceVip::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,_T("�˵���"),LVCFMT_LEFT,80);
	m_list.InsertColumn(1,_T("�˺�"),LVCFMT_LEFT,80);
	m_list.InsertColumn(2,_T("����"),LVCFMT_LEFT,100);
	m_list.InsertColumn(3,_T("����"),LVCFMT_LEFT,80);
	m_list.InsertColumn(4,_T("����"),LVCFMT_LEFT,80);
	m_list.InsertColumn(5,_T("�ܼ�"),LVCFMT_LEFT,80);
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
		m_list.InsertItem(k,s,k);
		int quantaty;
		for( short index = 1; index < nFields; index++ )
		{
			rs.GetFieldValue( index, varValue );
			CString s;
			int price;
			if(index==3)
			{
				quantaty=varValue.m_iVal ;
				s.Format("%d",quantaty);
				s=s+"��";
			}
			else if(index==4)
			{
				price=varValue.m_iVal ;
				s.Format("%d",price);
				s=s+"Ԫ";
			}
			else
				s=*varValue.m_pstring ;
			s.TrimRight (" ");
			m_list.SetItemText(k,index,s);
			if(index==4)
			{
				int sum_price=quantaty*price;
				s.Format("%d",sum_price);
				s=s+"Ԫ";
				s.TrimRight (" ");
				m_list.SetItemText(k,index+1,s);
				break;
			}
		}
		rs.MoveNext( );
		k++;
	}
	rs.Close();
	db.Close ();
	return TRUE;  // return TRUE unless you set the focus to a control
}
