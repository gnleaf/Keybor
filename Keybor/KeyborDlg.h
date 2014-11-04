// KeyborDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "Dlg1.h"
#include "Dlg2.h"
#include "Dlg3.h"
#include "Dlg4.h"
#include "Dlg5.h"
#include "Afx.h"


// CKeyborDlg 对话框
class CKeyborDlg : public CDialog
{

// 构造
public:
	CKeyborDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_KEYBOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
  
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	void OnSysCommand(UINT nID, LPARAM lParam);

	afx_msg void OnPaint();
	afx_msg void OnNcPaint();
	afx_msg HCURSOR OnQueryDragIcon();
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg LRESULT OnNotifyIcon(WPARAM wParam,LPARAM lParam);
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClose();
	afx_msg void OnQuitTime();
	afx_msg LRESULT OnHotKey(WPARAM wParam, LPARAM lParam);
	afx_msg void OnOK();
	afx_msg void OnCancel();
	afx_msg void On32777();
	afx_msg void On32779();
	DECLARE_MESSAGE_MAP()

public:
	NOTIFYICONDATA notifydata;
	CTabCtrl m_tab;

	void OnExit();
	void OnSet();
	BOOL ShowBalloonTip(LPCTSTR szMsg, LPCTSTR szTitle, UINT uTimeout, DWORD dwInfoFlags);
	static void SetszTip(LPCTSTR str);
	afx_msg LRESULT OnNcHitTest(CPoint point);
};
