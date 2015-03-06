// Goods.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�����ն�.h"
#include "Goods.h"
#include "afxdialogex.h"
#include "�����ն�Dlg.h"
#include "GoodsAdd.h"
#include "GoodsUpdate.h"
#include <afxdb.h>
#include "TableAdd.h"
#include "TableUpdate.h"
#include "DishesAdd.h"
#include "DishesUpdate.h"
#include "DeptAdd.h"
#include "DeptUpdte.h"


// CGoods �Ի���

IMPLEMENT_DYNAMIC(CGoods, CDialogEx)

CGoods::CGoods(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGoods::IDD, pParent)
{

}

CGoods::~CGoods()
{
}

void CGoods::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CGoods, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CGoods::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CGoods::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CGoods::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CGoods::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CGoods::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CGoods::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CGoods::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CGoods::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON1, &CGoods::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CGoods::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON11, &CGoods::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CGoods::OnBnClickedButton12)
END_MESSAGE_MAP()


// CGoods ��Ϣ�������

int style=1;//��ʾ��ǰѡ��ʲô��Ϊ��ӣ�ɾ�������²���ʱ���ĸ�����ṩ����Ĭ��Ϊ1����Ա����
BOOL CGoods::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_list.InsertColumn(0,_T("Ա����"),LVCFMT_LEFT,80);
	m_list.InsertColumn(1,_T("Ա������"),LVCFMT_LEFT,80);
	m_list.InsertColumn(2,_T("Ա����"),LVCFMT_LEFT,80);
	m_list.InsertColumn(3,_T("�Ա�"),LVCFMT_LEFT,80);
	m_list.InsertColumn(4,_T("���ű��"),LVCFMT_LEFT,80);
	m_list.InsertColumn(5,_T("����"),LVCFMT_LEFT,80);

	CDatabase db;
    CRecordset rs(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT Employee_ID,Employee_Password,Employee_Name,Employee_Sex,Department_ID,Employee_Style FROM Employee"));
	CDBVariant varValue;
	short nFields = rs.GetODBCFieldCount( );
	int k=0;
	while( !rs.IsEOF( ) )
	{
		rs.GetFieldValue( short(0), varValue );
		CString str;
		str=*varValue.m_pstring ;
		str.TrimRight (" ");
		m_list.InsertItem(k,str,k);
		for( short index = 1; index < nFields; index++ )
		{
			rs.GetFieldValue( index, varValue );
			CString ss;
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


void CGoods::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	style=1;
	Update();
}


void CGoods::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	style=2;
	Update();
}


void CGoods::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	style=3;
	Update();
}


void CGoods::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	style=4;
	Update();
}


void CGoods::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	style=5;
	Update();
}


void CGoods::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	style=6;
	Update();
}


void CGoods::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	style=7;
	Update();
}


void CGoods::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	style=8;
	Update();
}


void CGoods::Update(void)
{
	m_list.DeleteAllItems();
	int n=m_list.GetHeaderCtrl()->GetItemCount();
	for (int i=0;i<n;i++)
	{
		m_list.DeleteColumn(0);
	}
	CDatabase db;
	CRecordset rs(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	if(style==1){
		rs.Open( 1,_T( "SELECT Employee_ID,Employee_Password,Employee_Name,Employee_Sex,Department_ID,Employee_Style FROM Employee"));
		m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
		m_list.InsertColumn(0,_T("Ա����"),LVCFMT_LEFT,80);
		m_list.InsertColumn(1,_T("Ա������"),LVCFMT_LEFT,80);
		m_list.InsertColumn(2,_T("Ա����"),LVCFMT_LEFT,80);
		m_list.InsertColumn(3,_T("�Ա�"),LVCFMT_LEFT,80);
		m_list.InsertColumn(4,_T("���ű��"),LVCFMT_LEFT,80);
		m_list.InsertColumn(5,_T("����"),LVCFMT_LEFT,80);
	}
	else if(style==2){
		rs.Open( 1,_T( "SELECT Table_ID,Seat_Num,Table_Position,Table_Situation FROM Dinner_Table"));
		m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
		m_list.InsertColumn(0,_T("������"),LVCFMT_LEFT,80);
		m_list.InsertColumn(1,_T("��λ��"),LVCFMT_LEFT,80);
		m_list.InsertColumn(2,_T("λ��"),LVCFMT_LEFT,80);
		m_list.InsertColumn(3,_T("ʹ�����"),LVCFMT_LEFT,80);
	}
	else if(style==3){
		rs.Open( 1,_T( "SELECT Client_ID,Table_ID,Client_Message FROM Client"));
		m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
		m_list.InsertColumn(0,_T("�˿ͺ�"),LVCFMT_LEFT,80);
		m_list.InsertColumn(1,_T("������"),LVCFMT_LEFT,80);
		m_list.InsertColumn(2,_T("�˿���Ϣ"),LVCFMT_LEFT,80);
	}
	else if(style==4){
		rs.Open( 1,_T( "SELECT Dishes_ID,Dishes_Name,Dishes_Price,Dishes_Classification FROM Dishes_List"));
		m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
		m_list.InsertColumn(0,_T("�˺�"),LVCFMT_LEFT,80);
		m_list.InsertColumn(1,_T("����"),LVCFMT_LEFT,80);
		m_list.InsertColumn(2,_T("�۸�"),LVCFMT_LEFT,80);
		m_list.InsertColumn(3,_T("����"),LVCFMT_LEFT,80);
	}
	else if(style==5){
		rs.Open( 1,_T( "SELECT Bill_ID,Client_ID,Dishes_ID,Dishes_Name,Quantity,Price FROM Bill"));
		m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
		m_list.InsertColumn(0,_T("�˵���"),LVCFMT_LEFT,80);
		m_list.InsertColumn(1,_T("�˿ͺ�"),LVCFMT_LEFT,80);
		m_list.InsertColumn(2,_T("�˺�"),LVCFMT_LEFT,80);
		m_list.InsertColumn(3,_T("����"),LVCFMT_LEFT,80);
		m_list.InsertColumn(4,_T("����"),LVCFMT_LEFT,80);
		m_list.InsertColumn(5,_T("�۸�"),LVCFMT_LEFT,80);
	}
	else if(style==6){
		rs.Open( 1,_T( "SELECT Department_ID,Department_Name FROM Department"));
		m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
		m_list.InsertColumn(0,_T("���ź�"),LVCFMT_LEFT,80);
		m_list.InsertColumn(1,_T("������"),LVCFMT_LEFT,80);
	}
	else if(style==7){
		rs.Open( 1,_T( "SELECT Goods_ID,Employee_ID,Goods_Name,Goods_Quantity,Purchase_Date FROM Purchase"));
		m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
		m_list.InsertColumn(0,_T("��Ʒ��"),LVCFMT_LEFT,80);
		m_list.InsertColumn(1,_T("Ա����"),LVCFMT_LEFT,80);
		m_list.InsertColumn(2,_T("��Ʒ��"),LVCFMT_LEFT,80);
		m_list.InsertColumn(3,_T("��������"),LVCFMT_LEFT,80);
		m_list.InsertColumn(4,_T("����ʱ��"),LVCFMT_LEFT,80);
	}
	else if(style==8){
		rs.Open( 1,_T( "SELECT Goods_ID,Goods_Name,Goods_Price FROM Goods"));
		m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
		m_list.InsertColumn(0,_T("��Ʒ��"),LVCFMT_LEFT,80);
		m_list.InsertColumn(1,_T("��Ʒ��"),LVCFMT_LEFT,80);
		m_list.InsertColumn(2,_T("�۸�"),LVCFMT_LEFT,80);
		
	}
	if(style==1||style==3||style==6){
		CDBVariant varValue;
		short nFields = rs.GetODBCFieldCount( );
		int k=0;
		while( !rs.IsEOF( ) )
		{
			rs.GetFieldValue( short(0), varValue );
			CString str;
			str=*varValue.m_pstring ;
			str.TrimRight (" ");
			m_list.InsertItem(k,str,k);
			for( short index = 1; index < nFields; index++ )
			{
				rs.GetFieldValue( index, varValue );
				CString ss;
				ss=*varValue.m_pstring ;
				ss.TrimRight (" ");
				m_list.SetItemText(k,index,ss);

			}
			rs.MoveNext( );
			k++;
		}
	}
	else if(style==2){
		CDBVariant varValue;
		short nFields = rs.GetODBCFieldCount( );
		int k=0;
		while( !rs.IsEOF( ) )
		{
			rs.GetFieldValue( short(0), varValue );
			CString str;
			str=*varValue.m_pstring ;
			str.TrimRight (" ");
			m_list.InsertItem(k,str,k);
			for( short index = 1; index < nFields; index++ )
			{
				rs.GetFieldValue( index, varValue );
				CString ss;
				if(index==1)
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
	}
	else if(style==4){
		CDBVariant varValue;
		short nFields = rs.GetODBCFieldCount( );
		int k=0;
		while( !rs.IsEOF( ) )
		{
			rs.GetFieldValue( short(0), varValue );
			CString str;
			str=*varValue.m_pstring ;
			str.TrimRight (" ");
			m_list.InsertItem(k,str,k);
			for( short index = 1; index < nFields; index++ )
			{
				rs.GetFieldValue( index, varValue );
				CString ss;
				if(index==2)
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
	}
	else if(style==5){
		CDBVariant varValue;
		short nFields = rs.GetODBCFieldCount( );
		int k=0;
		while( !rs.IsEOF( ) )
		{
			rs.GetFieldValue( short(0), varValue );
			CString str;
			str=*varValue.m_pstring ;
			str.TrimRight (" ");
			m_list.InsertItem(k,str,k);
			for( short index = 1; index < nFields; index++ )
			{
				rs.GetFieldValue( index, varValue );
				CString ss;
				if(index==4)
				{
					int temp=varValue.m_iVal ;
					ss.Format("%d",temp);
					ss=ss+"��";
				}
				else if(index==5)
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
	}
	else if(style==7){
		CDBVariant varValue;
		short nFields = rs.GetODBCFieldCount( );
		int k=0;
		while( !rs.IsEOF( ) )
		{
			rs.GetFieldValue( short(0), varValue );
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
	}
	else if(style==8){
		CDBVariant varValue;
		short nFields = rs.GetODBCFieldCount( );
		int k=0;
		while( !rs.IsEOF( ) )
		{
			rs.GetFieldValue( short(0), varValue );
			CString str;
			str=*varValue.m_pstring ;
			str.TrimRight (" ");
			m_list.InsertItem(k,str,k);
			for( short index = 1; index < nFields; index++ )
			{
				rs.GetFieldValue( index, varValue );
				CString ss;
				if(index==2)
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
	}
	rs.Close();
	db.Close ();
}

void CGoods::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	C�����ն�Dlg dlg;
	CDialog::OnOK();
	dlg.DoModal();
}


void CGoods::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(style==3||style==5||style==7||style==8)
	{
		MessageBox("�˱�����������!");
		return;
	}
	else if(style==1)
	{
		CGoodsAdd dlg;
		if(IDOK==dlg.DoModal())
		{
			Update();
		}
		return;
	}
	else if(style==2)
	{
		CTableAdd dlg;
		if(IDOK==dlg.DoModal())
		{
			Update();
		}
		return;
	}
	else if(style==4)
	{
		CDishesAdd dlg;
		if(IDOK==dlg.DoModal())
		{
			Update();
		}
		return;
	}
	else if(style==6)
	{
		CDeptAdd dlg;
		if(IDOK==dlg.DoModal())
		{
			Update();
		}
		return;
	}
}


void CGoods::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(style==3||style==5||style==7||style==8)
	{
		MessageBox("�˱����������ɾ��!");
		return;
	}
	CDatabase db;
    CRecordset rs(&db);
	int num=-1;
	num=m_list.GetSelectionMark();
	CString s=m_list.GetItemText(num,0);//i���У�j���С�m_list�Ǹ�list control ����
	if(num>=0)
	{
		if(MessageBox(_T("���Ҫɾ��������"),_T("��ʾ"),MB_YESNO|MB_ICONWARNING)==IDYES)
		{
			CString s=m_list.GetItemText(num,0);
			CString sql;
			db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
			if(style==1)
			{
				rs.Open( 1,_T( "SELECT Employee_ID,Employee_Password,Employee_Name,Employee_Sex,Department_ID,Employee_Style FROM Employee"));
				sql="delete from Employee where Employee_ID="+s ;
			}
			else if(style==2)
			{
				rs.Open( 1,_T( "SELECT Table_ID,Seat_Num,Table_Position,Table_Situation FROM Dinner_Table"));
				sql="delete from Dinner_Table where Table_ID="+s ;
			}
			else if(style==4)
			{
				rs.Open( 1,_T( "SELECT Dishes_ID,Dishes_Name,Dishes_Price,Dishes_Classification FROM Dishes_List"));
				sql="delete from Dishes_List where Dishes_ID="+s ;
			}
			else if(style==6)
			{
				rs.Open( 1,_T( "SELECT Department_ID,Department_Name FROM Department"));
				sql="delete from Department where Department_ID="+s ;
			}
			db.ExecuteSQL (sql);
			rs.Close();
	        db.Close ();
			Update();
		}
	}
	else
		MessageBox(_T("��ѡ��Ҫɾ���ĵ�����"),_T("��ʾ"),MB_OK|MB_ICONWARNING);
	m_list.SetSelectionMark(-1);
}

CString s1;//i���У�j���С�m_list�Ǹ�list control ����
CString s2;
CString s3;
CString s4;
CString s5;
CString s6;
void CGoods::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(style==3||style==5||style==7||style==8)
	{
		MessageBox("�˱�����������޸�!");
		return;
	}
	int num=-1;
	num=m_list.GetSelectionMark();
	if(style==1)
	{
		if(num>=0)
		{
			s1=m_list.GetItemText(num,0);//Ա����
			s2=m_list.GetItemText(num,1);//����
			s3=m_list.GetItemText(num,2);//����
			s4=m_list.GetItemText(num,4);//���ź�
			s5=m_list.GetItemText(num,5);//����
			s6=m_list.GetItemText(num,3);//�Ա�
			CGoodsUpdate dlg;
			if(IDOK==dlg.DoModal())
			{
				Update();
			}

		}
		else
			MessageBox(_T("��ѡ��Ҫ�޸ĵĵ�����"),_T("��ʾ"),MB_OK|MB_ICONWARNING);
		m_list.SetSelectionMark(-1);
	}
	else if(style==2)
	{
		if(num>=0)
		{
			s1=m_list.GetItemText(num,0);
			s2=m_list.GetItemText(num,1);
			s3=m_list.GetItemText(num,2);
			s4=m_list.GetItemText(num,3);
			CTableUpdate dlg;
			if(IDOK==dlg.DoModal())
			{
				Update();
			}

		}
		else
			MessageBox(_T("��ѡ��Ҫ�޸ĵĵ�����"),_T("��ʾ"),MB_OK|MB_ICONWARNING);
		m_list.SetSelectionMark(-1);
	}
	else if(style==4)
	{
		if(num>=0)
		{
			s1=m_list.GetItemText(num,0);
			s2=m_list.GetItemText(num,1);
			s3=m_list.GetItemText(num,2);
			s4=m_list.GetItemText(num,3);
			CDishesUpdate dlg;
			if(IDOK==dlg.DoModal())
			{
				Update();
			}

		}
		else
			MessageBox(_T("��ѡ��Ҫ�޸ĵĵ�����"),_T("��ʾ"),MB_OK|MB_ICONWARNING);
		m_list.SetSelectionMark(-1);
	}
	else if(style==6)
	{
		if(num>=0)
		{
			s1=m_list.GetItemText(num,0);
			s2=m_list.GetItemText(num,1);
			CDeptUpdte dlg;
			if(IDOK==dlg.DoModal())
			{
				Update();
			}

		}
		else
			MessageBox(_T("��ѡ��Ҫ�޸ĵĵ�����"),_T("��ʾ"),MB_OK|MB_ICONWARNING);
		m_list.SetSelectionMark(-1);
	}
}
