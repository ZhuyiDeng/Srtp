// CTip1.cpp: 实现文件
//

#include "stdafx.h"
#include "MfcSrtp.h"
#include "CTip1.h"
#include "afxdialogex.h"


// CTip1 对话框

IMPLEMENT_DYNAMIC(CTip1, CDialogEx)

CTip1::CTip1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TIP1, pParent)
	, m_pwidth(0)
	, m_pheight(0)
{

}

CTip1::~CTip1()
{
}

void CTip1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_SHOWPHOTO, m_showphoto);
	DDX_Text(pDX, IDC_EDIT1_PWIDTH, m_pwidth);
	DDX_Text(pDX, IDC_EDIT1_PHEIGHT, m_pheight);
	DDX_Control(pDX, IDC_COMBO1_SIZE, m_msk_size);
	DDX_Control(pDX, IDC_COMBO1, m_msk_choose);
}


BEGIN_MESSAGE_MAP(CTip1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTip1::OnBnClickedButton1)
	ON_STN_CLICKED(IDC_STATIC_NAME, &CTip1::OnStnClickedStaticName)
	ON_STN_CLICKED(IDC_STATIC_SHOWPHOTO, &CTip1::OnStnClickedStaticShowphoto)
	ON_BN_CLICKED(IDC_BUTTON2, &CTip1::OnBnClickedButton2)
	ON_EN_KILLFOCUS(IDC_EDIT1_PWIDTH, &CTip1::OnEnKillfocusEdit1Pwidth)
	ON_EN_KILLFOCUS(IDC_EDIT1_PHEIGHT, &CTip1::OnEnKillfocusEdit1Pheight)
//	ON_EN_CHANGE(IDC_EDIT1_PWIDTH, &CTip1::OnEnChangeEdit1Pwidth)
END_MESSAGE_MAP()


// CTip1 消息处理程序

extern CString filePath;
void CTip1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString defaultPath = _T("E:\\拼图解压\\原图");
	CFileDialog Dlg(TRUE,defaultPath);
	Dlg.GetOFN().lpstrInitialDir = _T("E:\\拼图解压\\原图");
	if (Dlg.DoModal() == IDOK)
	{
		m_flag = 1;
		filePath = Dlg.GetPathName();
		SetDlgItemText(IDC_STATIC_NAME, filePath);
		ShowImage(filePath);
	}
}


void CTip1::OnStnClickedStaticName()
{
	// TODO: 在此添加控件通知处理程序代码
}
extern float portion;
void CTip1::ShowImage(CString strImgFilePath)
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
	portion = (float)cx / (float)cy;
	//获取Picture Control控件的大小
	GetDlgItem(IDC_STATIC_SHOWPHOTO)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	GetDlgItem(IDC_STATIC_SHOWPHOTO)->MoveWindow(rect.left, rect.top,rect.Width(),rect.Height(), TRUE);
	CWnd *pWnd = NULL;///使用这种方法获取控件句柄，可以动态获取不同控件的句柄，尤其在批量控件设置时很方便
	pWnd = GetDlgItem(IDC_STATIC_SHOWPHOTO);
	pWnd->GetClientRect(&rect);//获取句柄指向控件区域的大小
	CDC *pDC = NULL;
	pDC = pWnd->GetDC();//获取picture的DC
	pDC->SetStretchBltMode(HALFTONE);
	image.Draw(pDC->m_hDC, rect);//将图片绘制到picture表示的区域内
	ReleaseDC(pDC);
}


void CTip1::OnStnClickedStaticShowphoto()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CTip1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	CenterWindow();//设置窗口居中显示
	SetDlgItemInt(IDC_EDIT1_PWIDTH,0);
	SetDlgItemInt(IDC_EDIT1_PHEIGHT, 0);
	m_msk_size.InsertString(0,_T("8 x 8"));
	m_msk_size.InsertString(1,_T("10 x 10"));
	m_msk_size.InsertString(2,_T("12 x 12"));
	m_msk_size.SetCurSel(0);
	m_flag = 0;

	m_msk_choose.SetCurSel(0);//设置控件默认值

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CString skPath;
void CTip1::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog Dlg(TRUE);
	if (Dlg.DoModal() == IDOK)
	{
		skPath = Dlg.GetPathName();
		SetDlgItemText(IDC_STATIC_SK_PATH, skPath);
		ShowImage(filePath);
	}
}

extern int width;
extern int height;
void CTip1::OnEnKillfocusEdit1Pwidth()
{
	// TODO: 在此添加控件通知处理程序代码
	width = GetDlgItemInt(IDC_EDIT1_PWIDTH);
	if (height == 0 || m_flag == 1)
	{
        height = width / portion;
		m_flag = 0;
	}
	SetDlgItemInt(IDC_EDIT1_PHEIGHT, height);
}


void CTip1::OnEnKillfocusEdit1Pheight()
{
	// TODO: 在此添加控件通知处理程序代码
	height = GetDlgItemInt(IDC_EDIT1_PHEIGHT);
	if (width == 0 || m_flag == 1)
	{
        width = height * portion;
		m_flag = 0;
	}
	SetDlgItemInt(IDC_EDIT1_PWIDTH, width);
}


//void CTip1::OnEnChangeEdit1Pwidth()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//	// TODO:  在此添加控件通知处理程序代码
//}
