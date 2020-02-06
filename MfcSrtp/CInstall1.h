#pragma once


// CInstall1 对话框

class CInstall1 : public CDialogEx
{
	DECLARE_DYNAMIC(CInstall1)

public:
	CInstall1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CInstall1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSTALL1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
	CStatic m_tip;
	afx_msg void OnBnClickedButton1();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
