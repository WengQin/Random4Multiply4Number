
// 043_Random4Multiply4NumberDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "043_Random4Multiply4Number.h"
#include "043_Random4Multiply4NumberDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMy043_Random4Multiply4NumberDlg 对话框



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


// CMy043_Random4Multiply4NumberDlg 消息处理程序

BOOL CMy043_Random4Multiply4NumberDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetWindowPos(&wndTop, 200, 200, 300, 300, SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON1)->SetWindowPos(NULL, 100, 25, 100, 50, SWP_NOZORDER);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy043_Random4Multiply4NumberDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy043_Random4Multiply4NumberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy043_Random4Multiply4NumberDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//把1-8的值每个值2次赋值到A[16]的数组里
	int i, j;
	for (i = 0; i<16; i++)	//将数组初始化，全-1
		A[i] = -1;


	for (j = 1; j <= 8; j++)	//将数字1-8分配给16个控件对应的数组元素，每个数字两次
	{
		i = rand() % 16;//0-15的数值

		//确认随机A[i]未被赋值
		while (A[i] != -1)
			i = rand() % 16;

		//把j的循环值随机赋值给数组A[i]
		A[i] = j;

		i = rand() % 16;

		while (A[i] != -1)
			i = rand() % 16;
		//把j的循环值第2次赋值给数组A[i]（不重复的数组位）
		A[i] = j;
	}

	MessageBox(_T("随机数组产生完毕！"));

	for (int i = 0; i < 16; i++)
	{
		GetDlgItem(1001 + i)->ShowWindow(true);
		GetDlgItem(1001 + i)->SetWindowPos(NULL, 100 + 32 * (i % 4), 100 + 32 * (i / 4), 32, 32, SWP_NOZORDER);
		hicon = AfxGetApp()->LoadIcon(129-1+A[i]);
		tu[i].SetIcon(hicon);
	}
}
