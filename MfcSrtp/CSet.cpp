// CSet.cpp: 实现文件
//

#include "pch.h"
#include "MfcSrtp.h"
#include "CSet.h"
#include "afxdialogex.h"
#include "stdafx.h"
#include "CSet1.h"
#include <locale>


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
	DDX_Control(pDX, IDC_TITLE, m_title);
	DDX_Control(pDX, IDC_LIST6, m_list);
}


BEGIN_MESSAGE_MAP(CSet, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSet::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RESERVE, &CSet::OnBnClickedReserve)
END_MESSAGE_MAP()


// CSet 消息处理程序

//引入变量
extern CString skPath;//文件位置
extern CString skName;//文件名称
extern int count = 0;//行数
extern int i;
extern CString text;//创建对照表中编辑框内容


//点击 选择色卡文件 按钮
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

			//更新标题名称
			CString title;
			title.Format(_T("色号序号对照表（共 %d 种颜色）"), count);
			m_title.SetWindowTextW(title);

			//设置 色号序号对照表 正文
			i = 0;
			while (i < count) {
				//类型转换
				CString list;
				list.Format(_T("%d"), i + 1);

				//设置 序号 列
				m_list.InsertItem(i, list);

				//弹出 设置 色号 列 窗口
				CSet1 Dlg;
				Dlg.DoModal();

				//设置色号列
				m_list.SetItemText(i, 1, text);


				i++;
			}
			
		}
	}
}



BOOL CSet::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	//设置默认标题
	m_title.SetWindowTextW(_T("色号序号对照表"));

	//设置表头
	m_list.InsertColumn(0, TEXT("序号"),LVCFMT_LEFT,100);
	//m_list.InsertColumn(1, TEXT("色号"), LVCFMT_LEFT, GetSystemMetrics(SM_CXSCREEN) - 100);
	m_list.InsertColumn(1, TEXT("色号"),LVCFMT_LEFT,350);
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


//点击保存按钮
void CSet::OnBnClickedReserve()
{
	// TODO: 在此添加控件通知处理程序代码

	CFileDialog fDlg(FALSE, _T(".txt"), skName, OFN_OVERWRITEPROMPT, _T("文本文档(*.txt)|*.txt|保存的数据(*.dat)|*.dat|所有文件(*.*)|*.*||"), NULL);

	//使中文数据可以写入文件
	CFileException pError;
	setlocale(LC_CTYPE, ("chs"));
	
	if (fDlg.DoModal() == IDOK) {//保证点击了确定按钮，获取到正确的文件路径
			
		//创建文件对象
		CString sPath = fDlg.GetPathName();
		CStdioFile file(sPath, CFile::modeWrite | CFile::modeCreate);
		CString cs;
		cs = "序号         色号\n";

		file.WriteString(cs);

		for (int j = 0; j < count; j++) {
			cs = m_list.GetItemText(j, 0)+_T("              ");
			cs += m_list.GetItemText(j, 1)+_T("\n");

			file.WriteString(cs);
		}

		//关闭文件
		file.Close();

	}

}

