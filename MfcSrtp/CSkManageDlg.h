#pragma once


// CSkManageDlg 对话框

class CSkManageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSkManageDlg)

public:
	CSkManageDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSkManageDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SK_MANAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonPickSkp();
	void ShowImage(CString path);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton1ShowSkb();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonCreateB();
};
