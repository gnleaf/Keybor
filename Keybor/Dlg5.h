#pragma once


// CDlg5 对话框


#include "BtnST.h"
#include "WinXPButtonST.h"
#include "Link.h"

class CDlg5 : public CDialog
{
	DECLARE_DYNAMIC(CDlg5)
private:
	CSocket m_socket;
	CWinXPButtonST m_bt1;
	CWinXPButtonST m_bt2;
	CWinXPButtonST m_bt3;
	CWinXPButtonST m_bt4;
	CWinXPButtonST m_bt5;
	CWinXPButtonST m_bt6;
	CWinXPButtonST m_bt7;
	CWinXPButtonST m_bt8;
	CLink m_set;
	CLink m_set2;
public:
	CDlg5(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg5();
	virtual BOOL OnInitDialog();
	void PcStart();
	void HideMainWnd();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnStnClickedSet();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnStnClickedSet2();
	afx_msg void OnPaint();
};
