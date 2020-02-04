#pragma once


// CSet1 对话框

class CSet1 : public CDialogEx
{
	DECLARE_DYNAMIC(CSet1)

public:
	CSet1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSet1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SET1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CStatic m_tip;
	CEdit m_text;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
