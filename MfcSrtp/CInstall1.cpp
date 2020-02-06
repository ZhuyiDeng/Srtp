// CInstall1.cpp: 实现文件
//

#include "pch.h"
#include "MfcSrtp.h"
#include "CInstall1.h"
#include "afxdialogex.h"
#include "stdafx.h"
#include "CInstallTip.h"


// CInstall1 对话框

IMPLEMENT_DYNAMIC(CInstall1, CDialogEx)

CInstall1::CInstall1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSTALL1, pParent)
{

}

CInstall1::~CInstall1()
{
}

void CInstall1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TIP, m_tip);
}


BEGIN_MESSAGE_MAP(CInstall1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CInstall1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CInstall1::OnBnClickedButton1)
END_MESSAGE_MAP()


// CInstall1 消息处理程序


//点击 取消 按钮
void CInstall1::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	//关闭当前窗口
	CDialog::OnCancel();
}


BOOL CInstall1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//设置提示内容
	m_tip.SetWindowTextW(_T("请输入效果图版本号"));



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


//点击 确定 按钮
void CInstall1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//弹出 准备马赛克！ 窗口
	CInstallTip Dlg;
	Dlg.DoModal();

	//关闭当前窗口
	CDialog::OnCancel();
	
}


//使得按下确定键和按下回车键效果一样
BOOL CInstall1::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	if (pMsg->message == WM_KEYDOWN) {
		if (pMsg->wParam == VK_RETURN) {//当按下键为回车键时
			OnBnClickedButton1();//调用按钮函数
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
