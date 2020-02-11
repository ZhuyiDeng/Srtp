// CQuantity.cpp: 实现文件
//显示并保存整个产品马赛克用量表
//

#include "pch.h"
#include "MfcSrtp.h"
#include "CQuantity.h"
#include "afxdialogex.h"
#include "stdafx.h"


// CQuantity 对话框

IMPLEMENT_DYNAMIC(CQuantity, CDialogEx)

CQuantity::CQuantity(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QUANTITY, pParent)
{

}

CQuantity::~CQuantity()
{
}

void CQuantity::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CQuantity, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &CQuantity::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CQuantity::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CQuantity::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CQuantity::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CQuantity::OnBnClickedButton1)
END_MESSAGE_MAP()


// CQuantity 消息处理程序


//点击返回按钮
void CQuantity::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码

	//关闭当前窗口
	CDialog::OnCancel();
}


//extern CString skName;

//点击显示产品属性按钮
void CQuantity::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

//	CEdit* cstring;
//	cstring = (CEdit*)GetDlgItem(IDC_EDIT1);
//	cstring->SetWindowText(skName);//将文件名称显示在控件中
}


//点击显示马赛克用量表按钮
void CQuantity::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码


}


//点击保存马赛克用量表按钮
void CQuantity::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码


}


//点击显示效果图按钮
void CQuantity::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码


}
