// Tip2.cpp: 实现文件
//

#include "stdafx.h"
#include "MfcSrtp.h"
#include "Tip2.h"
#include "afxdialogex.h"


// Tip2 对话框

IMPLEMENT_DYNAMIC(Tip2, CDialogEx)

Tip2::Tip2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Tip2, pParent)
{

}

Tip2::~Tip2()
{
}

void Tip2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Tip2, CDialogEx)
END_MESSAGE_MAP()


// Tip2 消息处理程序
