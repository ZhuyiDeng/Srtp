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

	/*

	DWORD   dwStyle;
	dwStyle = m_install_list1.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_install_list1.SetExtendedStyle(dwStyle);

	m_install_list1.InsertColumn(0, L" ", LVCFMT_LEFT, 20);
	m_install_list1.InsertColumn(1, L" ", LVCFMT_LEFT, 20);
	m_install_list1.InsertColumn(2, L" ", LVCFMT_LEFT, 20);
	m_install_list1.InsertItem(0, L" ");
	m_install_list1.SetItemText(0, 1, L" ");
	m_install_list1.SetItemText(0, 2, L" ");
	m_install_list1.InsertItem(1, L" ");
	m_install_list1.SetItemText(1, 1, L" ");
	m_install_list1.SetItemText(1, 2, L" ");
	
	m_install_list1.SetTextBkColor(RGB(255, 255, 0));
	m_install_list1.SetBkColor(RGB(0, 0, 0));

	*/



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


}


//点击右边的 继续 按钮
void CInstall::OnBnClickedContinue2()
{
	// TODO: 在此添加控件通知处理程序代码


}


void CInstall::OnPaint()
{
	CPen newPen;       // 鐢ㄤ簬鍒涘缓鏂扮敾绗?  
	CPen* pOldPen;     // 鐢ㄤ簬瀛樻斁鏃х敾绗?  
	CBrush newBrush;   // 鐢ㄤ簬鍒涘缓鏂扮敾鍒?  
	CBrush* pOldBrush; // 鐢ㄤ簬瀛樻斁鏃х敾鍒?  

	CRect rectPicture;  // 鍥剧墖鎺т欢鐨勭煩褰㈠尯鍩熷潗鏍?
	// 鑾峰彇鍥剧墖鎺т欢鐭╁舰鍖哄煙鐨勫睆骞曞潗鏍?  
	m_pic.GetWindowRect(&rectPicture);
	// 灏嗗浘鐗囨帶浠剁煩褰㈠尯鍩熺殑灞忓箷鍧愭爣杞崲涓哄叾鐖剁獥鍙ｅ嵆瀵硅瘽妗嗙殑瀹㈡埛鍖哄潗鏍?  
	ScreenToClient(&rectPicture);

	// 鍒涘缓榛戣壊鏂扮敾鍒?  
	newBrush.CreateSolidBrush(RGB(0, 0, 0));
	CPaintDC pDC(this); // 鐢ㄤ簬缁樺埗鐨勮澶囦笂涓嬫枃
	// 閫夋嫨鏂扮敾鍒凤紝骞跺皢鏃х敾鍒风殑鎸囬拡淇濆瓨鍒皃OldBrush   
	pOldBrush = pDC.SelectObject(&newBrush);
	// 浠ラ粦鑹茬敾鍒蜂负缁樺浘鎺т欢濉厖榛戣壊锛屽舰鎴愰粦鑹茶儗鏅?  
	pDC.Rectangle(rectPicture);
	// 鎭㈠鏃х敾鍒?  
	pDC.SelectObject(pOldBrush);
	// 鍒犻櫎鏂扮敾鍒?  
	newBrush.DeleteObject();

	// 鍒涘缓瀹炲績鐢荤瑪锛岀矖搴︿负1锛岄鑹蹭负缁胯壊   
	newPen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	// 閫夋嫨鏂扮敾绗旓紝骞跺皢鏃х敾绗旂殑鎸囬拡淇濆瓨鍒皃OldPen   
	pOldPen = pDC.SelectObject(&newPen);


	int x = rectPicture.Width();
	int y = rectPicture.Height();

	for (int i = 1; i <= 12; i++) {
		pDC.MoveTo(rectPicture.left, i * (y / 12) + rectPicture.top);
		pDC.LineTo(x + rectPicture.left, i * (y / 12) + rectPicture.top);

		pDC.MoveTo(i * (x / 12) + rectPicture.left, rectPicture.top);
		pDC.LineTo(i * (x / 12) + rectPicture.left, y + rectPicture.top);
	}
	// 鎭㈠鏃х敾绗?  
	pDC.SelectObject(pOldPen);
	// 鍒犻櫎鏂扮敾绗?  
	newPen.DeleteObject();

	// 鍒涘缓榛勮壊鏂扮敾鍒?  
	newBrush.CreateSolidBrush(RGB(255, 255, 0));
	// 閫夋嫨鏂扮敾鍒凤紝骞跺皢鏃х敾鍒风殑鎸囬拡淇濆瓨鍒皃OldBrush   
	pOldBrush = pDC.SelectObject(&newBrush);

	pDC.Rectangle(rectPicture.left, rectPicture.left, rectPicture.left + (x / 12), rectPicture.top + (y / 12));

	// 鎭㈠鏃х敾鍒?  
	pDC.SelectObject(pOldBrush);
	// 鍒犻櫎鏂扮敾鍒?  
	newBrush.DeleteObject();
}
