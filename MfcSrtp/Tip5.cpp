// Tip5.cpp: 实现文件
//

#include "stdafx.h"
#include "MfcSrtp.h"
#include "Tip5.h"
#include "afxdialogex.h"


// Tip5 对话框

IMPLEMENT_DYNAMIC(Tip5, CDialogEx)

Tip5::Tip5(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Tip5, pParent)
{

}

Tip5::~Tip5()
{
}

void Tip5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Tip5, CDialogEx)
END_MESSAGE_MAP()


// Tip5 消息处理程序
