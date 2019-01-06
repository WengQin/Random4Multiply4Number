
// 043_Random4Multiply4NumberDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "043_Random4Multiply4Number.h"
#include "043_Random4Multiply4NumberDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy043_Random4Multiply4NumberDlg �Ի���



CMy043_Random4Multiply4NumberDlg::CMy043_Random4Multiply4NumberDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MY043_RANDOM4MULTIPLY4NUMBER_DIALOG, pParent)
{
	srand(time(NULL));
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy043_Random4Multiply4NumberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	for (int i = 0; i < 16; i++)
	{
		DDX_Control(pDX, 1001+i, tu[i]);
	}
	
}

BEGIN_MESSAGE_MAP(CMy043_Random4Multiply4NumberDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy043_Random4Multiply4NumberDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMy043_Random4Multiply4NumberDlg ��Ϣ�������

BOOL CMy043_Random4Multiply4NumberDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetWindowPos(&wndTop, 200, 200, 300, 300, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON1)->SetWindowPos(NULL, 100, 25, 100, 50, SWP_NOZORDER);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy043_Random4Multiply4NumberDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy043_Random4Multiply4NumberDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy043_Random4Multiply4NumberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy043_Random4Multiply4NumberDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��1-8��ֵÿ��ֵ2�θ�ֵ��A[16]��������
	int i, j;
	for (i = 0; i<16; i++)	//�������ʼ����ȫ-1
		A[i] = -1;


	for (j = 1; j <= 8; j++)	//������1-8�����16���ؼ���Ӧ������Ԫ�أ�ÿ����������
	{
		i = rand() % 16;//0-15����ֵ

		//ȷ�����A[i]δ����ֵ
		while (A[i] != -1)
			i = rand() % 16;

		//��j��ѭ��ֵ�����ֵ������A[i]
		A[i] = j;

		i = rand() % 16;

		while (A[i] != -1)
			i = rand() % 16;
		//��j��ѭ��ֵ��2�θ�ֵ������A[i]�����ظ�������λ��
		A[i] = j;
	}

	MessageBox(_T("������������ϣ�"));

	for (int i = 0; i < 16; i++)
	{
		GetDlgItem(1001 + i)->ShowWindow(true);
		GetDlgItem(1001 + i)->SetWindowPos(NULL, 100 + 32 * (i % 4), 100 + 32 * (i / 4), 32, 32, SWP_NOZORDER);
		hicon = AfxGetApp()->LoadIcon(129-1+A[i]);
		tu[i].SetIcon(hicon);
	}
}
