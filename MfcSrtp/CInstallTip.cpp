// CInstallTip.cpp: 实现文件
//

#include "pch.h"
#include "MfcSrtp.h"
#include "CInstallTip.h"
#include "afxdialogex.h"
#include "stdafx.h"
#include "CInstallTip.h"


// CInstallTip 对话框

IMPLEMENT_DYNAMIC(CInstallTip, CDialogEx)

CInstallTip::CInstallTip(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSTALL_TIP, pParent)
{

}

CInstallTip::~CInstallTip()
{
}

void CInstallTip::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TIP, m_install_tip);
}


BEGIN_MESSAGE_MAP(CInstallTip, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CInstallTip::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CInstallTip::OnBnClickedButton1)
END_MESSAGE_MAP()


// CInstallTip 消息处理程序


BOOL CInstallTip::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//设置默认提示内容
	m_install_tip.SetWindowTextW(_T("某一联马赛克准备好了吗？\n准备好了请按回车键或'是'继续"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


//点击 否 按钮
void CInstallTip::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	//点击 否 按钮 则继续弹出当前窗口
	CInstallTip Dlg;
	Dlg.DoModal();
	
}


//使得按下 是 按钮和按下 回车键 效果一样
BOOL CInstallTip::PreTranslateMessage(MSG* pMsg)
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


//按下 是 按钮
void CInstallTip::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码


}
