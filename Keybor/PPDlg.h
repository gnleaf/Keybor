#pragma once



// CPPDlg 对话框

class CPPDlg : public CDialog
{
	DECLARE_DYNAMIC(CPPDlg)

public:
	CPPDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPPDlg();
	virtual BOOL OnInitDialog();
// 对话框数据
	enum { IDD = IDD_VOL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_p;
	afx_msg void OnPaint();
};
