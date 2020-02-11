#pragma once


// CAlter 对话框

class CAlter : public CDialogEx
{
	DECLARE_DYNAMIC(CAlter)

public:
	CAlter(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAlter();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ALTER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
