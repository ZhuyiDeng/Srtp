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
END_MESSAGE_MAP()


// CInstall 消息处理程序


BOOL CInstall::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//设置默认提示内容
	m_install_tip1.SetWindowTextW(_T("请将栅格板放在黑色安装区域位置"));
	m_install_tip2.SetWindowTextW(_T("请将栅格板放在黑色安装区域位置"));

	pDlg = this;//初始化该全局变量

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


void CInstall::OnPaint()
{
	CPen newPen;       // 用于创建新画笔
	CPen* pOldPen;     // 用于存放旧画笔
	CBrush newBrush;   // 用于创建新画刷
	CBrush* pOldBrush; // 用于存放旧画刷

	CRect rectPicture;  // 左边图片控件的矩形区域坐标
	CRect rectPicture1;  // 右边图片控件的矩形区域坐标
	// 获取图片控件矩形区域的屏幕坐标
	m_pic.GetWindowRect(&rectPicture);
	m_pic1.GetWindowRect(&rectPicture1);
	// 将图片控件矩形区域的屏幕坐标转换为其父窗口即对话框的客户区坐标
	ScreenToClient(&rectPicture);
	ScreenToClient(&rectPicture1);

	//填充黑色背景

	// 创建黑色新画刷
	newBrush.CreateSolidBrush(RGB(0, 0, 0));
	CPaintDC pDC(this); // 用于绘制的设备上下文
	// 选择新画刷，并将旧画刷的指针保存到pOldBrush
	pOldBrush = pDC.SelectObject(&newBrush);
	// 以黑色画刷为绘图控件填充黑色，形成黑色背景
	pDC.Rectangle(rectPicture);
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

	//左边
	int x = rectPicture.Width();
	int y = rectPicture.Height();

	for (int i = 1; i <= 12; i++) {
		pDC.MoveTo(rectPicture.left, i * (y / 12) + rectPicture.top);
		pDC.LineTo(x + rectPicture.left, i * (y / 12) + rectPicture.top);

		pDC.MoveTo(i * (x / 12) + rectPicture.left, rectPicture.top);
		pDC.LineTo(i * (x / 12) + rectPicture.left, y + rectPicture.top);
	}

	//右边
	int x1 = rectPicture1.Width();
	int y1 = rectPicture1.Height();

	for (int i = 1; i <= 12; i++) {
		pDC.MoveTo(rectPicture1.left, i * (y / 12) + rectPicture1.top);
		pDC.LineTo(x + rectPicture1.left, i * (y / 12) + rectPicture1.top);

		pDC.MoveTo(i * (x / 12) + rectPicture1.left, rectPicture1.top);
		pDC.LineTo(i * (x / 12) + rectPicture1.left, y + rectPicture1.top);
	}

	// 恢复旧画笔
	pDC.SelectObject(pOldPen);
	// 删除新画笔
	newPen.DeleteObject();
}

//点击左边的 继续 按钮
void CInstall::OnBnClickedContinue1()
{
	// TODO: 在此添加控件通知处理程序代码

	//示例
	CRect rectPicture;       // 图片控件的矩形区域坐标   
	CBrush newBrush;         // 创建的新画刷   
	CBrush* pOldBrush;       // 旧画刷的指针   
	CClientDC pDC(this); // 构造客户区的设备上下文对象   

	// 创建黄色新画刷
	newBrush.CreateSolidBrush(RGB(255, 255, 0));

	// 获取图片控件矩形区域的屏幕坐标   
	m_pic.GetWindowRect(&rectPicture);
	// 将图片控件矩形区域的屏幕坐标转换为其父窗口即对话框的客户区坐标   
	ScreenToClient(&rectPicture);

	// 选择新画刷，并保存旧画刷的指针到pOldBrush   
	pOldBrush = pDC.SelectObject(&newBrush);

	// 以新画刷为图片控件填充颜色   

	int x = rectPicture.Width();
	int y = rectPicture.Height();
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

	//示例
	CRect rectPicture1;       // 图片控件的矩形区域坐标   
	CBrush newBrush;         // 创建的新画刷   
	CBrush* pOldBrush;       // 旧画刷的指针   
	CClientDC pDC(this); // 构造客户区的设备上下文对象   

	// 创建黄色新画刷
	newBrush.CreateSolidBrush(RGB(255, 255, 0));

	// 获取图片控件矩形区域的屏幕坐标   
	m_pic1.GetWindowRect(&rectPicture1);
	// 将图片控件矩形区域的屏幕坐标转换为其父窗口即对话框的客户区坐标   
	ScreenToClient(&rectPicture1);

	// 选择新画刷，并保存旧画刷的指针到pOldBrush   
	pOldBrush = pDC.SelectObject(&newBrush);

	// 以新画刷为图片控件填充颜色   

	int x = rectPicture1.Width();
	int y = rectPicture1.Height();
	pDC.Rectangle(rectPicture1.left + (x / 12) * 4, rectPicture1.top + (y / 12) * 6, rectPicture1.left + (x / 12) * 5, rectPicture1.top + (y / 12) * 7);

	// 恢复旧画刷   
	pDC.SelectObject(pOldBrush);
	// 删除新画刷   
	newBrush.DeleteObject();


}
