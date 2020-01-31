// CSkManageDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MfcSrtp.h"
#include "CSkManageDlg.h"
#include "afxdialogex.h"


// CSkManageDlg 对话框

IMPLEMENT_DYNAMIC(CSkManageDlg, CDialogEx)

CSkManageDlg::CSkManageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SK_MANAGE, pParent)
{

}

CSkManageDlg::~CSkManageDlg()
{
}

void CSkManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSkManageDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_PICK_SKP, &CSkManageDlg::OnBnClickedButtonPickSkp)
	ON_BN_CLICKED(IDC_BUTTON1, &CSkManageDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON1_SHOW_SKB, &CSkManageDlg::OnBnClickedButton1ShowSkb)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CSkManageDlg 消息处理程序

void CSkManageDlg::ShowImage(CString strImgFilePath)
{
	int cx, cy;
	CImage  image;
	CRect   rect;
	if (!PathFileExists(strImgFilePath))  //判断此路径是否存在 
		return;

	//根据路径载入图片
	image.Load(strImgFilePath);
	//获取图片的宽 高度
	cx = image.GetWidth();
	cy = image.GetHeight();
	
	//获取Picture Control控件的大小
	GetDlgItem(IDC_STATIC_SKP)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	GetDlgItem(IDC_STATIC_SKP)->MoveWindow(rect.left, rect.top, rect.Width(), rect.Height(), TRUE);
	CWnd *pWnd = NULL;///使用这种方法获取控件句柄，可以动态获取不同控件的句柄，尤其在批量控件设置时很方便
	pWnd = GetDlgItem(IDC_STATIC_SKP);
	pWnd->GetClientRect(&rect);//获取句柄指向控件区域的大小
	CDC *pDC = NULL;
	pDC = pWnd->GetDC();//获取picture的DC
	pDC->SetStretchBltMode(HALFTONE);
	image.Draw(pDC->m_hDC, rect);//将图片绘制到picture表示的区域内
	ReleaseDC(pDC);
}
extern CString mskPath;
void CSkManageDlg::OnBnClickedButtonPickSkp()
{
	// TODO: 在此添加控件通知处理程序代码
	CString defaultPath = _T("E:\\拼图解压\\色卡");
	CFileDialog Dlg(TRUE,defaultPath);
	Dlg.GetOFN().lpstrInitialDir = _T("E:\\拼图解压\\色卡");
	if (Dlg.DoModal() == IDOK)
	{
		mskPath = Dlg.GetPathName();
		SetDlgItemText(IDC_STATIC_SKP, mskPath);
		ShowImage(mskPath);
	}
}


void CSkManageDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("请从右图中点击对应色块"));
}


void CSkManageDlg::OnBnClickedButton1ShowSkb()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CSkManageDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetDlgItem(IDC_STATIC_SKP)->GetWindowRect(rect);
	if ((point.x >= rect.left&&point.x <= rect.right) && (point.y >= rect.top&&point.y <= rect.bottom))
	{
		point.x -= rect.left;
		point.y -= rect.top;
	}
	CClientDC dc(this);
	COLORREF color = dc.GetPixel(point);
	int R = GetRValue(color); 
	int G = GetGValue(color);
	int B = GetBValue(color);
	CString rgb,str;
	str.Format(_T("%d"), R);
	rgb +=_T("R: ")+str+_T("  ");
	str.Format(_T("%d"), G);
	rgb += _T("G: ") + str + _T("  ");
	str.Format(_T("%d"), B);
	rgb += _T("B: ") + str+_T("\n");
	SetDlgItemText(IDC_STATIC_SHOW_RGB, rgb);
	CDialogEx::OnLButtonDown(nFlags, point);
}


BOOL CSkManageDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_LBUTTONDOWN )
	{
		OnLButtonDown(MK_LBUTTON, pMsg->pt);
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
