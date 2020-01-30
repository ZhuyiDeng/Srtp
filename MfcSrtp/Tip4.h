#pragma once


// Tip4 对话框

class Tip4 : public CDialogEx
{
	DECLARE_DYNAMIC(Tip4)

public:
	Tip4(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Tip4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Tip4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
