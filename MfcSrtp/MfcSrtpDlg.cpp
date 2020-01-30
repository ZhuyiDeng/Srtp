
// MfcSrtpDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MfcSrtp.h"
#include "MfcSrtpDlg.h"
#include "afxdialogex.h"
#include "Tip1.h"
#include "Tip2.h"
#include "Tip3.h"
#include "Tip4.h"
#include "Tip5.h"
#include "Tip6.h"

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


// CMfcSrtpDlg 对话框



CMfcSrtpDlg::CMfcSrtpDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSRTP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcSrtpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMfcSrtpDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMfcSrtpDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMfcSrtpDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMfcSrtpDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMfcSrtpDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMfcSrtpDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMfcSrtpDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CMfcSrtpDlg 消息处理程序

BOOL CMfcSrtpDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMfcSrtpDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMfcSrtpDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMfcSrtpDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
 

// 参数设置的按钮
void CMfcSrtpDlg::OnBnClickedButton1()
{
	//点击按钮弹出参数设置的对话框
	Tip1 tip1;
	tip1.DoModal();
}

// 效果显示的按钮
void CMfcSrtpDlg::OnBnClickedButton3()
{
	//点击按钮弹出效果显示的对话框
	Tip3 tip3;
	tip3.DoModal();
}

// 修改效果图的按钮
void CMfcSrtpDlg::OnBnClickedButton4()
{
	//点击按钮弹出修改效果图的对话框
	Tip4 tip4;
	tip4.DoModal();
}

// 马赛克用量的按钮
void CMfcSrtpDlg::OnBnClickedButton5()
{
	//点击按钮弹出马赛克用量的对话框
	Tip5 tip5;
	tip5.DoModal();
}

// 安装马赛克的按钮
void CMfcSrtpDlg::OnBnClickedButton6()
{
	//点击按钮弹出安装马赛克的对话框
	
}

// 色卡管理的按钮
void CMfcSrtpDlg::OnBnClickedButton7()
{
	//点击按钮弹出色卡管理的对话框
	Tip6 tip6;
	tip6.DoModal();
}


HBRUSH CMfcSrtpDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO: Change any attributes of the DC here
	HBRUSH hb = CreateSolidBrush(RGB(250, 255, 240));

	// TODO: Return a different brush if the default is not desired
	return hb;
}


