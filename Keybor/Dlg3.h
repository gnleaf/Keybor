#pragma once
#include "HyperLink.h"

// CDlg3 对话框

class CDlg3 : public CDialog
{
	DECLARE_DYNAMIC(CDlg3)

public:
	CDlg3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg3();
	virtual BOOL OnInitDialog();
// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg void OnBnClickedButton1();
	DECLARE_MESSAGE_MAP()
public:
    CHyperLink m_here;
	BOOL CreateLink(LPSTR   szPath, LPSTR   szLink);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
