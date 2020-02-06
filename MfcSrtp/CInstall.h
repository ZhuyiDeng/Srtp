﻿#pragma once


// CInstall 对话框

class CInstall : public CDialogEx
{
	DECLARE_DYNAMIC(CInstall)

public:
	CInstall(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CInstall();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSTALL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CStatic m_install_tip1;
	CStatic m_install_tip2;
};