// CInstall.cpp: 实现文件
//安装马赛克界面
//分为左右两边，安装两个栅格板
//

#include "pch.h"
#include "MfcSrtp.h"
#include "CInstall.h"
#include "afxdialogex.h"
#include "stdafx.h"
#include "CInstall1.h"

//右边安装控件标记
#define HTTOPLEFT1  100
#define HTTOPRIGHT1  200
#define HTBOTTOMLEFT1  300
#define HTBOTTOMRIGHT1  400
#define HTLEFT1  500
#define HTRIGHT1  600
#define HTTOP1  700
#define HTBOTTOM1  800

//定义全局变量，以便能够在其他类中引用该变量
//实现在其他类中对该窗口内容进行更改等操作
CInstall* pDlg;

// CInstall 对话框

IMPLEMENT_DYNAMIC(CInstall, CDialogEx)

CInstall::CInstall(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSTALL, pParent)
{

}

CInstall::~CInstall()
{
}

void CInstall::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INSTALL_TIP1, m_install_tip1);
	DDX_Control(pDX, IDC_INSTALL_TIP2, m_install_tip2);
	DDX_Control(pDX, IDC_EDIT_A1, m_text_a1);
	DDX_Control(pDX, IDC_PIC, m_pic);
	DDX_Control(pDX, IDC_PIC1, m_pic1);
}


BEGIN_MESSAGE_MAP(CInstall, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CInstall::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CInstall::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CONTINUE1, &CInstall::OnBnClickedContinue1)
	ON_BN_CLICKED(IDC_CONTINUE2, &CInstall::OnBnClickedContinue2)
	ON_WM_PAINT()
	ON_WM_NCHITTEST()
	ON_WM_SETCURSOR()
	ON_WM_NCLBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON2, &CInstall::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CInstall::OnBnClickedButton4)
END_MESSAGE_MAP()


// CInstall 消息处理程序


BOOL CInstall::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//设置默认提示内容
	m_install_tip1.SetWindowTextW(_T("请将栅格板放在黑色安装区域位置"));
	m_install_tip2.SetWindowTextW(_T("请将栅格板放在黑色安装区域位置"));

//	pDlg = this;//初始化该全局变量

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


//点击 返回  按钮
void CInstall::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	//关闭当前窗口
	CDialog::OnCancel();
}


//点击 开始安装 按钮
void CInstall::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//弹出 安装马赛克 窗口
	CInstall1 Dlg;
	Dlg.DoModal();
}


//点击左边的 继续 按钮
void CInstall::OnBnClickedContinue1()
{
	// TODO: 在此添加控件通知处理程序代码

	//更改上方提示信息：现在安装第i号马赛克，安装完点击"继续"

	//显示联号
//	pDlg->SetDlgItemTextW(IDC_EDIT_A1, _T("(1,1)"));//例子

	//显示色号

	//显示颜色

	//显示数量

	//需要马赛克块处增亮处理

	CBrush newBrush;   // 用于创建新画刷
	CBrush* pOldBrush; // 用于存放旧画刷
	CClientDC pDC(this);

	CRect rectPicture;  // 左边图片控件的矩形区域坐标
	// 获取图片控件矩形区域的屏幕坐标
	m_pic.GetWindowRect(&rectPicture);
	// 将图片控件矩形区域的屏幕坐标转换为其父窗口即对话框的客户区坐标
	ScreenToClient(&rectPicture);

	//左边
	int x = rectPicture.Width();
	int y = rectPicture.Height();

	//示例

	// 创建黄色新画刷
	newBrush.CreateSolidBrush(RGB(255, 255, 0));
	// 选择新画刷，并保存旧画刷的指针到pOldBrush   
	pOldBrush = pDC.SelectObject(&newBrush);

	// 以新画刷为图片控件填充颜色   
	pDC.Rectangle(rectPicture.left, rectPicture.top, rectPicture.left + (x / 12), rectPicture.top + (y / 12));

	// 恢复旧画刷   
	pDC.SelectObject(pOldBrush);
	// 删除新画刷   
	newBrush.DeleteObject();
}


//点击右边的 继续 按钮
void CInstall::OnBnClickedContinue2()
{
	// TODO: 在此添加控件通知处理程序代码

	//更改上方提示信息：现在安装第i号马赛克，安装完点击"继续"

	//显示联号
//	pDlg->SetDlgItemTextW(IDC_EDIT_A1, _T("(1,2)"));//例子

	//显示色号

	//显示颜色

	//显示数量

	//需要马赛克块处增亮处理

	CBrush newBrush;   // 用于创建新画刷
	CBrush* pOldBrush; // 用于存放旧画刷
	CClientDC pDC(this);

	CRect rectPicture1;  // 右边图片控件的矩形区域坐标
	// 获取图片控件矩形区域的屏幕坐标
	m_pic1.GetWindowRect(&rectPicture1);
	// 将图片控件矩形区域的屏幕坐标转换为其父窗口即对话框的客户区坐标
	ScreenToClient(&rectPicture1);

	//左边
	int x1 = rectPicture1.Width();
	int y1 = rectPicture1.Height();

	//示例

	// 创建黄色新画刷
	newBrush.CreateSolidBrush(RGB(255, 255, 0));
	// 选择新画刷，并保存旧画刷的指针到pOldBrush   
	pOldBrush = pDC.SelectObject(&newBrush);

	// 以新画刷为图片控件填充颜色   
	pDC.Rectangle(rectPicture1.left + (x1 / 12) * 4, rectPicture1.top + (y1 / 12) * 6, rectPicture1.left + (x1 / 12) * 5, rectPicture1.top + (y1 / 12) * 7);

	// 恢复旧画刷   
	pDC.SelectObject(pOldBrush);
	// 删除新画刷   
	newBrush.DeleteObject();
}


LRESULT CInstall::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CPoint p;
	//先获取鼠标相对于屏幕的坐标
	GetCursorPos(&p);
	//最后把当前鼠标的坐标转化为相对于rect的坐标
	ScreenToClient(&p);

	int SIZE = 3;

	//左边
	CRect rect;
	GetDlgItem(IDC_PIC)->GetWindowRect(&rect);
	ScreenToClient(&rect);

	//右边
	CRect rect1;
	GetDlgItem(IDC_PIC1)->GetWindowRect(&rect1);
	ScreenToClient(&rect1);

	// 最好将四个角的判断放在前面
	//左边
	//左上角
	if (p.x <= rect.left + SIZE && p.x >= rect.left - SIZE && p.y <= rect.top + SIZE && p.y >= rect.top - SIZE)
		return HTTOPLEFT;
	//右上角
	else if (p.x <= rect.right + SIZE && p.x >= rect.right - SIZE && p.y <= rect.top + SIZE && p.y >= rect.top - SIZE)
		return HTTOPRIGHT;
	//左下角
	else if (p.x <= rect.left + SIZE && p.x >= rect.left - SIZE && p.y <= rect.bottom + SIZE && p.y >= rect.bottom - SIZE)
		return HTBOTTOMLEFT;
	//右下角
	else if (p.x <= rect.right + SIZE && p.x >= rect.right - SIZE && p.y <= rect.bottom + SIZE && p.y >= rect.bottom - SIZE)
		return HTBOTTOMRIGHT;
	//左边
	else if (p.x <= rect.left + SIZE && p.x >= rect.left - SIZE && p.y <= rect.bottom && p.y >= rect.top)
		return HTLEFT;
	//右边
	else if (p.x <= rect.right + SIZE && p.x >= rect.right - SIZE && p.y <= rect.bottom && p.y >= rect.top)
		return HTRIGHT;
	//上边
	else if (p.x <= rect.right && p.x >= rect.left && p.y <= rect.top + SIZE && p.y >= rect.top - SIZE)
		return HTTOP;
	//下边
	else if (p.x <= rect.right && p.x >= rect.left && p.y <= rect.bottom + SIZE && p.y >= rect.bottom - SIZE)
		return HTBOTTOM;


	//右边
	//左上角
	else if (p.x <= rect1.left + SIZE && p.x >= rect1.left - SIZE && p.y <= rect1.top + SIZE && p.y >= rect1.top - SIZE)
		return HTTOPLEFT1;
	//右上角
	else if (p.x <= rect1.right + SIZE && p.x >= rect1.right - SIZE && p.y <= rect1.top + SIZE && p.y >= rect1.top - SIZE)
		return HTTOPRIGHT1;
	//左下角
	else if (p.x <= rect1.left + SIZE && p.x >= rect1.left - SIZE && p.y <= rect1.bottom + SIZE && p.y >= rect1.bottom - SIZE)
		return HTBOTTOMLEFT1;
	//右下角
	else if (p.x <= rect1.right + SIZE && p.x >= rect1.right - SIZE && p.y <= rect1.bottom + SIZE && p.y >= rect1.bottom - SIZE)
		return HTBOTTOMRIGHT1;
	//左边
	else if (p.x <= rect1.left + SIZE && p.x >= rect1.left - SIZE && p.y <= rect1.bottom && p.y >= rect1.top)
		return HTLEFT1;
	//右边
	else if (p.x <= rect1.right + SIZE && p.x >= rect1.right - SIZE && p.y <= rect1.bottom && p.y >= rect1.top)
		return HTRIGHT1;
	//上边
	else if (p.x <= rect1.right && p.x >= rect1.left && p.y <= rect1.top + SIZE && p.y >= rect1.top - SIZE)
		return HTTOP1;
	//下边
	else if (p.x <= rect1.right && p.x >= rect1.left && p.y <= rect1.bottom + SIZE && p.y >= rect1.bottom - SIZE)
		return HTBOTTOM1;
}


BOOL CInstall::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	switch (nHitTest)
	{
		//鼠标光标在上下边一定范围内改变鼠标形状为南北方向的箭头
	case HTTOP:
	case HTTOP1:
	case HTBOTTOM:
	case HTBOTTOM1:
		SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENS)));
		return TRUE;
		//鼠标光标在左右边一定范围内改变鼠标形状为东西方向的箭头
	case HTLEFT:
	case HTLEFT1:
	case HTRIGHT:
	case HTRIGHT1:
		SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZEWE)));
		return TRUE;
		//鼠标光标在左上和右下角改变鼠标形状为西北东南方向的箭头
	case HTTOPLEFT:
	case HTTOPLEFT1:
	case HTBOTTOMRIGHT:
	case HTBOTTOMRIGHT1:
		SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENWSE)));
		return TRUE;
		//鼠标光标在右上和左下角改变鼠标形状为东北西南方向的箭头
	case HTTOPRIGHT:
	case HTTOPRIGHT1:
	case HTBOTTOMLEFT:
	case HTBOTTOMLEFT1:
		SetCursor(LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENESW)));
		return TRUE;
	default:
		return __super::OnSetCursor(pWnd, nHitTest, message);
	}
}


void CInstall::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//左边
	HWND hWnd;
	hWnd = GetDlgItem(IDC_PIC)->GetSafeHwnd();

	//右边
	HWND hWnd1;
	hWnd1 = GetDlgItem(IDC_PIC1)->GetSafeHwnd();

	switch (nHitTest)
	{
	//左边
	case HTTOP:
		::SendMessage(hWnd, WM_SYSCOMMAND, SC_SIZE | WMSZ_TOP, MAKELPARAM(point.x, point.y));
		break;
	case HTBOTTOM:
		::SendMessage(hWnd, WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOM, MAKELPARAM(point.x, point.y));
		break;
	case HTLEFT:
		::SendMessage(hWnd, WM_SYSCOMMAND, SC_SIZE | WMSZ_LEFT, MAKELPARAM(point.x, point.y));
		break;
	case HTRIGHT:
		::SendMessage(hWnd, WM_SYSCOMMAND, SC_SIZE | WMSZ_RIGHT, MAKELPARAM(point.x, point.y));
		break;
	case HTTOPLEFT:
		::SendMessage(hWnd, WM_SYSCOMMAND, SC_SIZE | WMSZ_TOPLEFT, MAKELPARAM(point.x, point.y));
		break;
	case HTTOPRIGHT:
		::SendMessage(hWnd, WM_SYSCOMMAND, SC_SIZE | WMSZ_TOPRIGHT, MAKELPARAM(point.x, point.y));
		break;
	case HTBOTTOMLEFT:
		::SendMessage(hWnd, WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOMLEFT, MAKELPARAM(point.x, point.y));
		break;
	case HTBOTTOMRIGHT:
		::SendMessage(hWnd, WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOMRIGHT, MAKELPARAM(point.x, point.y));
		break;

	//右边交换
	case HTTOP1:
		::SendMessage(hWnd1, WM_SYSCOMMAND, SC_SIZE | WMSZ_TOP, MAKELPARAM(point.x, point.y));
		break;
	case HTBOTTOM1:
		::SendMessage(hWnd1, WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOM, MAKELPARAM(point.x, point.y));
		break;
	case HTLEFT1:
		::SendMessage(hWnd1, WM_SYSCOMMAND, SC_SIZE | WMSZ_LEFT, MAKELPARAM(point.x, point.y));
		break;
	case HTRIGHT1:
		::SendMessage(hWnd1, WM_SYSCOMMAND, SC_SIZE | WMSZ_RIGHT, MAKELPARAM(point.x, point.y));
		break;
	case HTTOPLEFT1:
		::SendMessage(hWnd1, WM_SYSCOMMAND, SC_SIZE | WMSZ_TOPLEFT, MAKELPARAM(point.x, point.y));
		break;
	case HTTOPRIGHT1:
		::SendMessage(hWnd1, WM_SYSCOMMAND, SC_SIZE | WMSZ_TOPRIGHT, MAKELPARAM(point.x, point.y));
		break;
	case HTBOTTOMLEFT1:
		::SendMessage(hWnd1, WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOMLEFT, MAKELPARAM(point.x, point.y));
		break;
	case HTBOTTOMRIGHT1:
		::SendMessage(hWnd1, WM_SYSCOMMAND, SC_SIZE | WMSZ_BOTTOMRIGHT, MAKELPARAM(point.x, point.y));
		break;
	default:
		__super::OnNcLButtonDown(nHitTest, point);
	}
}


//点击调整左边大小按钮
void CInstall::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	CPen newPen;       // 用于创建新画笔
	CPen* pOldPen;     // 用于存放旧画笔
	CBrush newBrush;   // 用于创建新画刷
	CBrush* pOldBrush; // 用于存放旧画刷
	CClientDC pDC(this);

	CRect rectPicture;  // 左边图片控件的矩形区域坐标
	// 获取图片控件矩形区域的屏幕坐标
	m_pic.GetWindowRect(&rectPicture);
	// 将图片控件矩形区域的屏幕坐标转换为其父窗口即对话框的客户区坐标
	ScreenToClient(&rectPicture);

	//填充黑色背景

	// 创建黑色新画刷
	newBrush.CreateSolidBrush(RGB(0, 0, 0));
	// 选择新画刷，并将旧画刷的指针保存到pOldBrush
	pOldBrush = pDC.SelectObject(&newBrush);
	// 以黑色画刷为绘图控件填充黑色，形成黑色背景
	pDC.Rectangle(rectPicture);
	// 恢复旧画刷
	pDC.SelectObject(pOldBrush);
	// 删除新画刷
	newBrush.DeleteObject();

	//画白色网格线

	// 创建实心画笔，粗度为1，颜色为绿色
	newPen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	// 选择新画笔，并将旧画笔的指针保存到pOldPen
	pOldPen = pDC.SelectObject(&newPen);

	//左边
	int x = rectPicture.Width();
	int y = rectPicture.Height();

	for (int i = 1; i <= 12; i++) {
		pDC.MoveTo(rectPicture.left, i * (y / 12) + rectPicture.top);
		pDC.LineTo(x + rectPicture.left, i * (y / 12) + rectPicture.top);

		pDC.MoveTo(i * (x / 12) + rectPicture.left, rectPicture.top);
		pDC.LineTo(i * (x / 12) + rectPicture.left, y + rectPicture.top);
	}

	// 恢复旧画笔
	pDC.SelectObject(pOldPen);
	// 删除新画笔
	newPen.DeleteObject();
}


//点击调整右边大小按钮
void CInstall::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码

	CPen newPen;       // 用于创建新画笔
	CPen* pOldPen;     // 用于存放旧画笔
	CBrush newBrush;   // 用于创建新画刷
	CBrush* pOldBrush; // 用于存放旧画刷
	CClientDC pDC(this);

	CRect rectPicture1;  // 右边图片控件的矩形区域坐标
	// 获取图片控件矩形区域的屏幕坐标
	m_pic1.GetWindowRect(&rectPicture1);
	// 将图片控件矩形区域的屏幕坐标转换为其父窗口即对话框的客户区坐标
	ScreenToClient(&rectPicture1);

	//填充黑色背景

	// 创建黑色新画刷
	newBrush.CreateSolidBrush(RGB(0, 0, 0));
	// 选择新画刷，并将旧画刷的指针保存到pOldBrush
	pOldBrush = pDC.SelectObject(&newBrush);
	// 以黑色画刷为绘图控件填充黑色，形成黑色背景
	pDC.Rectangle(rectPicture1);
	// 恢复旧画刷
	pDC.SelectObject(pOldBrush);
	// 删除新画刷
	newBrush.DeleteObject();

	//画白色网格线

	// 创建实心画笔，粗度为1，颜色为绿色
	newPen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	// 选择新画笔，并将旧画笔的指针保存到pOldPen
	pOldPen = pDC.SelectObject(&newPen);

	//右边
	int x1 = rectPicture1.Width();
	int y1 = rectPicture1.Height();

	for (int i = 1; i <= 12; i++) {
		pDC.MoveTo(rectPicture1.left, i * (y1 / 12) + rectPicture1.top);
		pDC.LineTo(x1 + rectPicture1.left, i * (y1 / 12) + rectPicture1.top);

		pDC.MoveTo(i * (x1 / 12) + rectPicture1.left, rectPicture1.top);
		pDC.LineTo(i * (x1 / 12) + rectPicture1.left, y1 + rectPicture1.top);
	}

	// 恢复旧画笔
	pDC.SelectObject(pOldPen);
	// 删除新画笔
	newPen.DeleteObject();
}
