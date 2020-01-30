// Tip4.cpp: 实现文件
//

#include "stdafx.h"
#include "MfcSrtp.h"
#include "Tip4.h"
#include "afxdialogex.h"


// Tip4 对话框

IMPLEMENT_DYNAMIC(Tip4, CDialogEx)

Tip4::Tip4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Tip4, pParent)
{

}

Tip4::~Tip4()
{
}

void Tip4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Tip4, CDialogEx)
END_MESSAGE_MAP()


// Tip4 消息处理程序
