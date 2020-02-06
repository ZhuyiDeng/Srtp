#pragma once


// CInstallTip 对话框

class CInstallTip : public CDialogEx
{
	DECLARE_DYNAMIC(CInstallTip)

public:
	CInstallTip(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CInstallTip();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSTALL_TIP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButton1();
	CStatic m_install_tip;
};
