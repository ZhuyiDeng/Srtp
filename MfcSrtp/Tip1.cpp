// Tip1.cpp: 实现文件
//

#include "stdafx.h"
#include "MfcSrtp.h"
#include "Tip1.h"
#include "afxdialogex.h"


// Tip1 对话框

IMPLEMENT_DYNAMIC(Tip1, CDialogEx)

Tip1::Tip1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TIP1, pParent)
{

}

Tip1::~Tip1()
{
}

void Tip1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Tip1, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO2, &Tip1::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Tip1::OnCbnSelchangeCombo1)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON3, &Tip1::OnBnClickedButton3)
END_MESSAGE_MAP()




// Tip1 消息处理程序

void Tip1::OnCbnSelchangeCombo1()
{
	
}

void Tip1::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}

void Tip1::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
}


void Tip1::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog fileDlg(TRUE);
	CString path;
	if (fileDlg.DoModal() == IDOK)
	{
		path = fileDlg.GetPathName();
		CImage image;
		CRect rect;
		image.Load(path);
		CWnd* pWnd = NULL;
		pWnd = GetDlgItem(IDC_STATIC_ORI_PIC);
		pWnd->GetClientRect(&rect);
		CDC* pDc = NULL;
		pDc = pWnd->GetDC();
		image.Draw(pDc->m_hDC, rect);
		ReleaseDC(pDc);
	}
}
