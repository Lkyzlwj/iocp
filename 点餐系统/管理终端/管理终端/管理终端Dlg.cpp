
// �����ն�Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�����ն�.h"
#include "�����ն�Dlg.h"
#include "afxdialogex.h"
#include "WorkPlatform.h"
#include "Purchase.h"
#include "Goods.h"
#include <afxdb.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C�����ն�Dlg �Ի���



C�����ն�Dlg::C�����ն�Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�����ն�Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�����ն�Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C�����ն�Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C�����ն�Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C�����ն�Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// C�����ն�Dlg ��Ϣ�������

BOOL C�����ն�Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�����ն�Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C�����ն�Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�����ն�Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C�����ն�Dlg::OnBnClickedButton1()
{
	CString str1=_T("");//�˺�
	CString str2=_T("");//����
	GetDlgItemText(IDC_EDIT1,str1);
	if(str1=="")
	{
		MessageBox("�����빤�ţ�");
		return;
	}
	GetDlgItemText(IDC_EDIT2,str2);
	CDatabase db;
	db.OpenEx (_T("DSN=user_message;UID=sa;PWD=xxx"));//������ĳ����sa�����,ע�ᴰ������Ҳ�к����ݿ����������,Ҳ��һ��
	CRecordset rs(&db);
	rs.Open( 1,_T( "SELECT Employee_ID,Employee_Password,Department_ID FROM Employee"));

	CDBVariant varValue;
	short nFields = rs.GetODBCFieldCount( );
	while( !rs.IsEOF( ) )
	{
		rs.GetFieldValue( short(0), varValue );
		CString s1;
		CString s2;
		s1=*varValue.m_pstring ;
		s1.TrimRight (" ");
		if(s1==str1){
			rs.GetFieldValue( short(1), varValue );
			s2=*varValue.m_pstring ;
			s2.TrimRight (" ");
			if(s2==str2){
				CString s22;
				rs.GetFieldValue( short(2), varValue );
				s22=*varValue.m_pstring ;
				s22.TrimRight (" ");
				if(s22=="001"){
					CGoods dlg;
					CDialog::OnOK();
					dlg.DoModal();
				}
				if(s22=="002"){
					CWorkPlatform dlg;
					CDialog::OnOK();
					dlg.DoModal();
				}
				if(s22=="003"){
					CPurchase dlg;
					CDialog::OnOK();
					dlg.DoModal();
				}
			}
			else
				MessageBox("���Ż��������");
		}
		rs.MoveNext();
	}
	rs.Close();
	db.Close();
}


void C�����ն�Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedButton1();
}
