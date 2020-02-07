
// MfcSrtpDlg.h: 头文件
//
#include <string>

#pragma once


// CMfcSrtpDlg 对话框
class CMfcSrtpDlg : public CDialogEx
{
// 构造
public:
	CMfcSrtpDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSRTP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();

public:
	// filePath 原图路径 filePathNew 生成rgb路径 colorPath 色卡路径
	// picx 产品宽度尺寸 picy 产品高度尺寸 val 马赛克块尺寸
	void trans(const CString filePath, CString filePathNew, CString colorPath, int picx, int picy, int val);
	
	// 这里是需要更改的：
	const CString filePath = _T("C:\\Users\\anyi\\Documents\\mfc\\test.jpg");
	CString colorPath = _T("C:\\Users\\anyi\\Documents\\mfc\\testTxt.txt");
	char filePathNewStrArrange[100];
	CString filePathNew = _T("C:\\Users\\anyi\\Documents\\mfc\\%s.txt");
	int cx = 500;
	int cy = 510;
	// 马赛克块的大小
	int val = 8;
};
