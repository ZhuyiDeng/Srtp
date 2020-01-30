#pragma once


// Tip1 对话框

class Tip1 : public CDialogEx
{
	DECLARE_DYNAMIC(Tip1)

public:
	Tip1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Tip1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIP1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedButton3();
};
