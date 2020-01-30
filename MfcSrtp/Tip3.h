#pragma once


// Tip3 对话框

class Tip3 : public CDialogEx
{
	DECLARE_DYNAMIC(Tip3)

public:
	Tip3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Tip3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Tip3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
