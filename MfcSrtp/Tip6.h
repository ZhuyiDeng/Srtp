#pragma once


// Tip6 对话框

class Tip6 : public CDialogEx
{
	DECLARE_DYNAMIC(Tip6)

public:
	Tip6(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Tip6();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Tip6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
