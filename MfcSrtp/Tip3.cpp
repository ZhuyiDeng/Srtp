// Tip3.cpp: 实现文件
//

#include "stdafx.h"
#include "MfcSrtp.h"
#include "Tip3.h"
#include "afxdialogex.h"


// Tip3 对话框

IMPLEMENT_DYNAMIC(Tip3, CDialogEx)

Tip3::Tip3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Tip3, pParent)
{

}

Tip3::~Tip3()
{
}

void Tip3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Tip3, CDialogEx)
END_MESSAGE_MAP()


// Tip3 消息处理程序
