
// MfcSrtpDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MfcSrtp.h"
#include "MfcSrtpDlg.h"
#include "afxdialogex.h"
#include "CTip1.h"
#include "CSkManageDlg.h"
#include "CInstall.h"
#include "CQuantity.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include<fstream>
#include <string>
using namespace std;

// 从路径提取名字要用的两个函数
void string_replace(string& strBig, const string& strsrc, const string& strdst)
{
	string::size_type pos = 0;
	string::size_type srclen = strsrc.size();
	string::size_type dstlen = strdst.size();

	while ((pos = strBig.find(strsrc, pos)) != string::npos)
	{
		strBig.replace(pos, srclen, strdst);
		pos += dstlen;
	}
}

string GetPathOrURLShortName(string strFullName)
{
	if (strFullName.empty()) {
		return "";
	}
	string_replace(strFullName, "/", "\\");
	string::size_type iPos = strFullName.find_last_of('\\') + 1;
	return strFullName.substr(iPos, strFullName.length() - iPos);
}


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
	ON_BN_CLICKED(IDC_BUTTON2, &CMfcSrtpDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMfcSrtpDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMfcSrtpDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMfcSrtpDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMfcSrtpDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMfcSrtpDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMfcSrtpDlg::OnBnClickedButton8)
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
	CTip1 SetDlg;
	SetDlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}

// 颜色替换的按钮
void CMfcSrtpDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	trans(filePath, filePathNew, colorPath, cx, cy, val);
}

void CMfcSrtpDlg::trans(const CString filePath, CString filePathNew, CString colorPath, int picx, int picy, int val) {
	// 读取色卡rgb数组
	// 定义用于存放rgb数据的矩阵
	int color[999][4] = { 0 };
	int colorNew[999][3] = { };
	ifstream infile;
	//定义读取文件流，相对于程序来说是in
	infile.open(colorPath);
	// 打开文件
	int* ptr = &color[0][0];
	// 循环
	while (!infile.eof()) {
		infile >> *ptr;//这个是把文档里面的数对应在ptr位置的数值上
		ptr++;
	}
	// 读取完成之后关闭文件
	infile.close();

	// 用来计数得到的rgb数组有多少个数字，/3就是它的行数，便于循环
	int allNum = 0;


	// 将得到的rgb数组存放在文件夹里
	// 将cstring转换为string
	string fileNamePath;
	// 将路径转化为string格式
	fileNamePath = CT2A(filePath.GetString());
	// 从路径中获取选择的图片的名字
	string filePathName = GetPathOrURLShortName(fileNamePath);
	int k = filePathName.length() - 1;
	while (TRUE)
	{
		if (filePathName[k] == '.') {
			filePathName.erase(k);
			break;
		}
		filePathName.erase(k);
		k--;
	}
	// string->char*
	char filePathNameChar[100];
	int i;
	int size = filePathName.length();
	for (i = 0; i < size; i++) filePathNameChar[i] = filePathName[i];
	filePathNameChar[i] = '\0';
	// 将获取到的图片的名字加入进将要存放的路径字符串中
	sprintf_s(filePathNewStrArrange, "C:\\Users\\anyi\\Documents\\mfc\\%s.txt", filePathNameChar);
	// 把字符数组转换为string
	string filePathNewStr = filePathNewStrArrange;
	// string转换为cstring
	filePathNew = CA2T(filePathNewStr.c_str());

	// 存储得到的rgb文件
	ofstream outfile(filePathNewStr);
	outfile.open(filePathNewStr, ios::out | ios::app);
	if (!outfile.is_open())    return;
	// 如果创建成功
	for (int i = 0; i < allNum / 3; i++) {
		for (int j = 0; j < 3; j++) {
			outfile << colorNew[i][j] << " ";
		}
		outfile << endl;
	}
	outfile.close();
}

// 效果显示的按钮
void CMfcSrtpDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}

// 修改效果图的按钮
void CMfcSrtpDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
}

// 马赛克用量的按钮
void CMfcSrtpDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码

	//弹出马赛克用量表窗口
	CQuantity Dlg;
	Dlg.DoModal();
}

// 安装马赛克的按钮
void CMfcSrtpDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码

	//弹出 安装马赛克 窗口
	CInstall dlg;
	dlg.DoModal();

}

// 色卡管理的按钮
void CMfcSrtpDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CSkManageDlg dlg;
	dlg.DoModal();
}

// 系统退出的按钮
void CMfcSrtpDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}
