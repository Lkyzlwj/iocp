// GoodsAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�����ն�.h"
#include "GoodsAdd.h"
#include "afxdialogex.h"
#include <afxdb.h>


// CGoodsAdd �Ի���

IMPLEMENT_DYNAMIC(CGoodsAdd, CDialogEx)

CGoodsAdd::CGoodsAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGoodsAdd::IDD, pParent)
{

}

CGoodsAdd::~CGoodsAdd()
{
}

void CGoodsAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGoodsAdd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CGoodsAdd::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CGoodsAdd::OnBnClickedButton3)
END_MESSAGE_MAP()


// CGoodsAdd ��Ϣ�������


BOOL CGoodsAdd::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("��");
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString("Ů");
	return TRUE;  // return TRUE unless you set the focus to a control
}


void CGoodsAdd::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s1,s2,s3,s4,s5,s6;
	int index;
	GetDlgItemText(IDC_EDIT1,s1);//Ա����
	GetDlgItemText(IDC_EDIT2,s2);//����
	GetDlgItemText(IDC_EDIT3,s3);//����
	GetDlgItemText(IDC_EDIT4,s4);//����
	GetDlgItemText(IDC_EDIT5,s5);//����
	index=((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	((CComboBox*)GetDlgItem(IDC_COMBO1))->GetLBText(index,s6);//�Ա�
	CDatabase db;
    CRecordset rs(&db);
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));
	rs.Open( 1,_T( "SELECT Employee_ID,Employee_Password,Employee_Name,Employee_Sex,Department_ID,Employee_Style FROM Employee"));
	CDBVariant varValue;
	CString sql="insert into Employee values('"+s1+"','"+s2+"','"+s3+"', '"+s6+"','"+s4+"','"+s5+"')";
	db.ExecuteSQL (sql);
	rs.Close();
	db.Close ();
	CDialog::OnOK();

}


void CGoodsAdd::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnCancel();
}
