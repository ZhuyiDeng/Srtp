// CInstallTip.cpp: 实现文件
//确认准备好了所需的马赛克块的提示窗口
//第一次点击是，将(1,1)联数据显示在左边安装界面
//第二次点击是，将(1,2)联数据显示在右边安装界面
//然后关闭该窗口，回到Install窗口
//

#include "pch.h"
#include "MfcSrtp.h"
#include "CInstallTip.h"
#include "afxdialogex.h"
#include "stdafx.h"
#include"CInstall.h"


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
	m_install_tip.SetWindowTextW(_T("(1,1) 联马赛克准备好了吗？\n准备好了请按回车键或'是'继续"));

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
int tip_index = 0;//区分左边和右边的安装界面
extern CInstall* pDlg;

void CInstallTip::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	tip_index++;

	if (tip_index == 1) {//第一次按

		//显示联号
		pDlg->SetDlgItemTextW(IDC_EDIT_A1, _T("(1,1)"));

		//显示色号

		//显示颜色

		//显示数量

		//需要马赛克块处增亮处理

		//更改提示信息
		m_install_tip.SetWindowTextW(_T("(1,2) 联马赛克准备好了吗？\n准备好了请按回车键或'是'继续"));

	}
	else if (tip_index == 2) {//第二次按

		//显示联号
		pDlg->SetDlgItemTextW(IDC_EDIT_B1, _T("(1,2)"));

		//显示色号

		//显示颜色

		//显示数量

		//需要马赛克块处增亮处理

		//关闭当前窗口
		CDialog::OnCancel();
	}
}
