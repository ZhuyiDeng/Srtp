// CSet1.cpp: 实现文件
//

#include "pch.h"
#include "MfcSrtp.h"
#include "CSet1.h"
#include "afxdialogex.h"
#include "stdafx.h"
#include "CSet.h"


// CSet1 对话框

IMPLEMENT_DYNAMIC(CSet1, CDialogEx)

CSet1::CSet1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SET1, pParent)
{

}

CSet1::~CSet1()
{
}

void CSet1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TIP, m_tip);
	DDX_Control(pDX, IDC_TEXT, m_text);
}


BEGIN_MESSAGE_MAP(CSet1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSet1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSet1::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSet1 消息处理程序

extern int count;//行数
extern int i;
extern CString text;//创建对照表中编辑框内容

BOOL CSet1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//设置提示内容

	CString tip;
	tip.Format(_T("请输入序号 %d 对应的色号"), i+1);
	m_tip.SetWindowTextW(tip);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


//点击确定按钮
void CSet1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取编辑框中内容
	m_text.GetWindowText(text);

	//关闭当前窗口
	CDialog::OnCancel();
}


//点击取消按钮
void CSet1::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	//点击取消按钮关闭当前窗口 并退出循环
	i = count;
	CDialog::OnCancel();
}


//使得按下确定键和按下回车键效果一样
BOOL CSet1::PreTranslateMessage(MSG* pMsg)
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



