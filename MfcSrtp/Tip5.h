#pragma once


// Tip5 对话框

class Tip5 : public CDialogEx
{
	DECLARE_DYNAMIC(Tip5)

public:
	Tip5(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Tip5();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Tip5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
