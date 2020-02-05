// CSkManageDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MfcSrtp.h"
#include "CSkManageDlg.h"
#include "afxdialogex.h"
#include "CSet.h"
#include <locale>


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
	DDX_Control(pDX, IDC_LIST_RGB, m_rgb_list);
}


BEGIN_MESSAGE_MAP(CSkManageDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_PICK_SKP, &CSkManageDlg::OnBnClickedButtonPickSkp)
	ON_BN_CLICKED(IDC_BUTTON1, &CSkManageDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON1_SHOW_SKB, &CSkManageDlg::OnBnClickedButton1ShowSkb)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON_CREATE_B, &CSkManageDlg::OnBnClickedButtonCreateB)
	ON_BN_CLICKED(IDCANCEL, &CSkManageDlg::OnBnClickedCancel)
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


//在同一个马赛克块中点击不同的几个点，再点击 生成马赛克块RGB值 按钮
//即可生成该马赛克块的RGB值（选取的几个点的RGB值的平均值）
//重复上述过程即可生成所有马赛克块的RGB值

int r, g, b;
int j = 0;

void CSkManageDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetDlgItem(IDC_STATIC_SKP)->GetWindowRect(rect);
	if ((point.x >= rect.left&&point.x <= rect.right) && (point.y >= rect.top&&point.y <= rect.bottom))
	{
		point.x -= rect.left;
		point.y -= rect.top;

		CClientDC dc(this);
		COLORREF color = dc.GetPixel(point);
		int R = GetRValue(color);
		int G = GetGValue(color);
		int B = GetBValue(color);
		CString rgb, str;
		str.Format(_T("%d"), R);
		rgb += _T("R: ") + str + _T("  ");
		str.Format(_T("%d"), G);
		rgb += _T("G: ") + str + _T("  ");
		str.Format(_T("%d"), B);
		rgb += _T("B: ") + str + _T("\n");
		SetDlgItemText(IDC_STATIC_SHOW_RGB, rgb);

		//选取五个点计算该色卡的RGB值
		j++;
		r += R;
		g += G;
		b += B;

		CDialogEx::OnLButtonDown(nFlags, point);
	}
}

int k = 0;
//点击 生成马赛克块RGB值 按钮
void CSkManageDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//MessageBox(_T("请从右图中点击对应色块"));

	//计算几个点的RGB平均值
	r /= j;
	g /= j;
	b /= j;
	CString rr,gg,bb;
	rr.Format(_T("%d"), r);
	gg.Format(_T("%d"), g);
	bb.Format(_T("%d"), b);

	//设置 RGB表 正文
	//类型转换
	CString index;
	index.Format(_T("%d"), k + 1);

	//设置 序号 列
	m_rgb_list.InsertItem(k, index);

	//设置 R G B 列
	m_rgb_list.SetItemText(k, 1, rr);
	m_rgb_list.SetItemText(k, 2, gg);
	m_rgb_list.SetItemText(k, 3, bb);

	k++;

	//恢复初始值
	j = 0;
	r = 0;
	g = 0;
	b = 0;
}


//点击 保存色卡RGB表 按钮
void CSkManageDlg::OnBnClickedButton1ShowSkb()
{
	// TODO: 在此添加控件通知处理程序代码

	CFileDialog fDlg(FALSE, _T(".txt"), _T("RGB表"), OFN_OVERWRITEPROMPT, _T("文本文档(*.txt)|*.txt|保存的数据(*.dat)|*.dat|所有文件(*.*)|*.*||"), NULL);

	//使中文数据可以写入文件
	CFileException pError;
	setlocale(LC_CTYPE, ("chs"));

	if (fDlg.DoModal() == IDOK) {//保证点击了确定按钮，获取到正确的文件路径

		//创建文件对象
		CString sPath = fDlg.GetPathName();
		CStdioFile file(sPath, CFile::modeWrite | CFile::modeCreate);
		CString cs;
		cs = "序号\tR\tG\tB\n";

		file.WriteString(cs);

		for (int j = 0; j < m_rgb_list.GetItemCount(); j++) {
			cs = m_rgb_list.GetItemText(j, 0) + _T("\t");
			cs += m_rgb_list.GetItemText(j, 1) + _T("\t");
			cs += m_rgb_list.GetItemText(j, 2) + _T("\t");
			cs += m_rgb_list.GetItemText(j, 3) + _T("\n");

			file.WriteString(cs);
		}

		//关闭文件
		file.Close();

	}
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


//点击 创建色号序号对照表 按钮
void CSkManageDlg::OnBnClickedButtonCreateB()
{
	// TODO: 在此添加控件通知处理程序代码

	//点击该按钮 弹出 创建色号序号对照表 窗口
	CSet dlg;
	dlg.DoModal();
}


//点击 返回 按钮
void CSkManageDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL CSkManageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	//设置默认标题
	CString cs;
	cs = _T("RGB表\n\n");
	SetDlgItemText(IDC_STATIC_RGB, cs);

	//设置表头
	m_rgb_list.InsertColumn(0, TEXT("序号"), LVCFMT_LEFT, 60);
	m_rgb_list.InsertColumn(1, TEXT("B"), LVCFMT_LEFT, 85);
	m_rgb_list.InsertColumn(1, TEXT("G"), LVCFMT_LEFT, 85);
	m_rgb_list.InsertColumn(1, TEXT("R"), LVCFMT_LEFT, 85);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
