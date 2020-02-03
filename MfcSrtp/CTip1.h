#pragma once


// CTip1 对话框

class CTip1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTip1)

public:
	CTip1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTip1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIP1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnStnClickedStaticName();
	CStatic m_showphoto;
	void ShowImage(CString);
	afx_msg void OnStnClickedStaticShowphoto();
	int m_pwidth;
	int m_pheight;
	int m_flag;
	CComboBox m_msk_size;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnKillfocusEdit1Pwidth();
	afx_msg void OnEnKillfocusEdit1Pheight();
//	afx_msg void OnEnChangeEdit1Pwidth();
};
