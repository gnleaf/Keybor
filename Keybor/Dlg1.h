

#pragma once

#include "Dlg2.h"
#include "HyperLink.h"
#include "Link.h"
#include "SetDlg.h"
#include "PPDlg.h"
#include "MyVolumeCtrl.h"

// CDlg1 对话框

class CDlg1 : public CDialog
{
	DECLARE_DYNAMIC(CDlg1)

public:
	CDlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg1();
	virtual BOOL OnInitDialog();
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:    
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg void OnOK();
	afx_msg void OnCancel();
//	afx_msg void OnDestroy();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo11();
    afx_msg void OnCbnSelchangeCombo12();
	afx_msg void OnCbnSelchangeCombo13();
	afx_msg void OnCbnSelchangeCombo14();
	afx_msg void OnCbnSelchangeCombo20();
    afx_msg LRESULT OnHotKey(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnStnClickedStaticset();
	DECLARE_MESSAGE_MAP()
public:	
	CString m_bo11;
	CString m_bo12;
	CString m_bo13;
	CString m_bo14;
	CString m_bo15;
	CString m_bo16;
	CHyperLink m_hello;
	CLink m_set;
	CPPDlg* m_pDlg;
	CProgressCtrl* m_pProgress;
	CMyVolumeCtrl  m_VControl;
    //CMuteControl   m_mmv;

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
};
#pragma once


// CDlg1 对话框

