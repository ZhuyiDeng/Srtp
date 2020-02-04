// CSet.cpp: 实现文件
//

#include "pch.h"
#include "MfcSrtp.h"
#include "CSet.h"
#include "afxdialogex.h"
#include "stdafx.h"


// CSet 对话框

IMPLEMENT_DYNAMIC(CSet, CDialogEx)

CSet::CSet(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SET, pParent)
{

}

CSet::~CSet()
{
}

void CSet::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_SHOW, m_ShowName);
}


BEGIN_MESSAGE_MAP(CSet, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSet::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSet 消息处理程序


//选择色卡文件
extern CString skPath;//文件位置
extern CString skName;//文件名称
void CSet::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	CFileDialog Dlg(TRUE);
	if (Dlg.DoModal() == IDOK)
	{
		skPath = Dlg.GetPathName();//获取文件路径
		SetDlgItemText(IDC_STATIC_SK_PATH, skPath);
		skName = Dlg.GetFileName();//获取文件名称
		m_ShowName.SetWindowTextW(skName);//将文件名称显示在控件中

		//统计TXT文件中数据的行数
		{
			CStdioFile file;
			CString content;
			DWORD o = 0;
			int count = 0;//行数
			file.Open(skPath, CFile::modeRead);
			o = file.GetPosition();
			file.Seek(o, 0);
			while (file.ReadString(content))
			{
				count++;
			}
			//类型转换 int -> CString
			CString line_count;
			line_count.Format(L"%d", count);
			MessageBox(line_count);
		}
	}
}

