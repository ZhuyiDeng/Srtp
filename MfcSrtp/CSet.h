#pragma once


// CSet 对话框

class CSet : public CDialogEx
{
	DECLARE_DYNAMIC(CSet)

public:
	CSet(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSet();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CStatic m_ShowName;
	virtual BOOL OnInitDialog();
	CStatic m_title;
	CListCtrl m_list;
	afx_msg void OnBnClickedReserve();
};
