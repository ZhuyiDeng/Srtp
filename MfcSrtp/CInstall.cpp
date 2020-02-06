// CInstall.cpp: 实现文件
//

#include "pch.h"
#include "MfcSrtp.h"
#include "CInstall.h"
#include "afxdialogex.h"
#include "stdafx.h"
#include "CInstall1.h"


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
}


BEGIN_MESSAGE_MAP(CInstall, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CInstall::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CInstall::OnBnClickedButton1)
END_MESSAGE_MAP()


// CInstall 消息处理程序


BOOL CInstall::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//设置默认提示内容
	m_install_tip1.SetWindowTextW(_T("请将栅格板放在黑色安装区域位置"));
	m_install_tip2.SetWindowTextW(_T("请将栅格板放在黑色安装区域位置"));


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
