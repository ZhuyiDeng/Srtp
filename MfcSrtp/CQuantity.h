#pragma once


// CQuantity 对话框

class CQuantity : public CDialogEx
{
	DECLARE_DYNAMIC(CQuantity)

public:
	CQuantity(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CQuantity();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUANTITY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton1();
};
