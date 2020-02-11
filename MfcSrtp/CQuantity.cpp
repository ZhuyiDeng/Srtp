// CQuantity.cpp: 实现文件
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
END_MESSAGE_MAP()


// CQuantity 消息处理程序
