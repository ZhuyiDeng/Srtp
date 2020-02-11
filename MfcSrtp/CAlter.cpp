// CAlter.cpp: 实现文件
//

#include "pch.h"
#include "MfcSrtp.h"
#include "CAlter.h"
#include "afxdialogex.h"
#include "stdafx.h"


// CAlter 对话框

IMPLEMENT_DYNAMIC(CAlter, CDialogEx)

CAlter::CAlter(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ALTER, pParent)
{

}

CAlter::~CAlter()
{
}

void CAlter::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAlter, CDialogEx)
END_MESSAGE_MAP()


// CAlter 消息处理程序
