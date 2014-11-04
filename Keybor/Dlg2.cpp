// Dlg2.cpp : 实现文件
//

#include "stdafx.h"
#include "Keybor.h"
#include "Dlg2.h"
#include "Afx.h"


// CDlg2 对话框

IMPLEMENT_DYNAMIC(CDlg2, CDialog)

CDlg2::CDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg2::IDD, pParent)
	, m_edit1(_T(""))
	, m_edit2(_T(""))
	, m_edit3(_T(""))
	, m_edit4(_T(""))
	, m_edit5(_T(""))
	, m_edit6(_T(""))
	, m_edit7(_T(""))
	, m_edit8(_T(""))
	, m_edit9(_T(""))
	, m_edit10(_T(""))
	, m_bo1(_T(""))
	, m_bo2(_T(""))
	, m_bo3(_T(""))
	, m_bo4(_T(""))
	, m_bo5(_T(""))
	, m_bo6(_T(""))
	, m_bo7(_T(""))
	, m_bo8(_T(""))
	, m_bo9(_T(""))
	, m_bo10(_T(""))
{

}

CDlg2::~CDlg2()
{
}

void CDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDX_Text(pDX, IDC_EDIT4, m_edit4);
	DDX_Text(pDX, IDC_EDIT5, m_edit5);
	DDX_Text(pDX, IDC_EDIT6, m_edit6);
	DDX_Text(pDX, IDC_EDIT7, m_edit7);
	DDX_Text(pDX, IDC_EDIT8, m_edit8);
	DDX_Text(pDX, IDC_EDIT9, m_edit9);
	DDX_Text(pDX, IDC_EDIT10, m_edit10);
	DDX_CBString(pDX, IDC_COMBO1, m_bo1);
	DDX_CBString(pDX, IDC_COMBO2, m_bo2);
	DDX_CBString(pDX, IDC_COMBO3, m_bo3);
	DDX_CBString(pDX, IDC_COMBO4, m_bo4);
	DDX_CBString(pDX, IDC_COMBO5, m_bo5);
	DDX_CBString(pDX, IDC_COMBO6, m_bo6);
	DDX_CBString(pDX, IDC_COMBO7, m_bo7);
	DDX_CBString(pDX, IDC_COMBO8, m_bo8);
	DDX_CBString(pDX, IDC_COMBO9, m_bo9);
	DDX_CBString(pDX, IDC_COMBO10, m_bo10);
}


BEGIN_MESSAGE_MAP(CDlg2, CDialog)
	ON_MESSAGE(WM_HOTKEY,OnHotKey)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlg2::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlg2::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlg2::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDlg2::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDlg2::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDlg2::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDlg2::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CDlg2::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CDlg2::OnBnClickedButton10)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDlg2::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CDlg2::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CDlg2::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CDlg2::OnCbnSelchangeCombo4)
	ON_CBN_SELCHANGE(IDC_COMBO5, &CDlg2::OnCbnSelchangeCombo5)
	ON_CBN_SELCHANGE(IDC_COMBO6, &CDlg2::OnCbnSelchangeCombo6)
	ON_CBN_SELCHANGE(IDC_COMBO7, &CDlg2::OnCbnSelchangeCombo7)
	ON_CBN_SELCHANGE(IDC_COMBO8, &CDlg2::OnCbnSelchangeCombo8)
	ON_CBN_SELCHANGE(IDC_COMBO9, &CDlg2::OnCbnSelchangeCombo9)
	ON_CBN_SELCHANGE(IDC_COMBO10, &CDlg2::OnCbnSelchangeCombo10)
	ON_WM_CTLCOLOR()
	ON_EN_CHANGE(IDC_EDIT1, &CDlg2::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CDlg2::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CDlg2::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CDlg2::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CDlg2::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &CDlg2::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT7, &CDlg2::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT8, &CDlg2::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT9, &CDlg2::OnEnChangeEdit9)
	ON_EN_CHANGE(IDC_EDIT10, &CDlg2::OnEnChangeEdit10)
END_MESSAGE_MAP()

BOOL CDlg2::OnInitDialog()
{
         CDialog::OnInitDialog();

		 CAfx::hwnd2=GetSafeHwnd();   ////句柄保存为全局

	     GetPrivateProfileString("Hotkeys","hk1","",m_bo1.GetBuffer(10),10,CAfx::filepath);
         GetPrivateProfileString("Hotkeys","hk2","",m_bo2.GetBuffer(10),10,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","hk3","",m_bo3.GetBuffer(10),10,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","hk4","",m_bo4.GetBuffer(10),10,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","hk5","",m_bo5.GetBuffer(10),10,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","hk6","",m_bo6.GetBuffer(10),10,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","hk7","",m_bo7.GetBuffer(10),10,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","hk8","",m_bo8.GetBuffer(10),10,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","hk9","",m_bo9.GetBuffer(10),10,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","hk10","",m_bo10.GetBuffer(10),10,CAfx::filepath);
         //路径编辑框初始化       
		 GetPrivateProfileString("Hotkeys","path1","",m_edit1.GetBuffer(255),225,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","path2","",m_edit2.GetBuffer(255),225,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","path3","",m_edit3.GetBuffer(255),225,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","path4","",m_edit4.GetBuffer(255),255,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","path5","",m_edit5.GetBuffer(255),255,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","path6","",m_edit6.GetBuffer(255),255,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","path7","",m_edit7.GetBuffer(255),255,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","path8","",m_edit8.GetBuffer(255),255,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","path9","",m_edit9.GetBuffer(255),255,CAfx::filepath);
		 GetPrivateProfileString("Hotkeys","path10","",m_edit10.GetBuffer(255),255,CAfx::filepath);

		 CAfx::m_bo1=m_bo1;
		 CAfx::m_bo2=m_bo2;
		 CAfx::m_bo3=m_bo3;
		 CAfx::m_bo4=m_bo4;
		 CAfx::m_bo5=m_bo5;
		 CAfx::m_bo6=m_bo6;
		 CAfx::m_bo7=m_bo7;
		 CAfx::m_bo8=m_bo8;
		 CAfx::m_bo9=m_bo9;
		 CAfx::m_bo10=m_bo10;

        CAfx::Register();  //////初始化注册
	    UpdateData(false);

        return TRUE;
	}


// CDlg2 消息处理程序

 LRESULT CDlg2::OnHotKey(WPARAM wParam, LPARAM lParam)
{
         if(wParam>=1001&&wParam<=1010)
                   {
					    CWnd::SetForegroundWindow();
						CString m_edit[10]={m_edit1,m_edit2,m_edit3,m_edit4,m_edit5,m_edit6,m_edit7,m_edit8,m_edit9,m_edit10};
                        int wp=wParam-1000;
						if(m_edit[wp-1]!="")
                                 ShellExecute(NULL,   "open",  m_edit[wp-1],   NULL,   NULL,   SW_SHOWNORMAL); 
                   }
        return 0;
}

 void CDlg2::PathButton(CString *p,CString path)
 {	
	 CFileDialog dlg(true);
	 dlg.m_ofn.lpstrFilter="程序(*.exe)\0*.exe\0所有文件(*.*)\0*.*\0\0";   
     if(dlg.DoModal()==IDOK)
	         {   	
				 *p=dlg.GetPathName();		
				 WritePrivateProfileString("Hotkeys",path,*p,CAfx::filepath);
				  UpdateData(false);
	         }      
 }

void CDlg2::OnBnClickedButton1()
{
      PathButton(&m_edit1,"path1");

}


void CDlg2::OnBnClickedButton2()
{
        PathButton(&m_edit2,"path2");
}

void CDlg2::OnBnClickedButton3()
{
        PathButton(&m_edit3,"path3");
}

void CDlg2::OnBnClickedButton4()
{
        PathButton(&m_edit4,"path4");
}

void CDlg2::OnBnClickedButton5()
{
         PathButton(&m_edit5,"path5");
}

void CDlg2::OnBnClickedButton6()
{
      PathButton(&m_edit6,"path6");
}

void CDlg2::OnBnClickedButton7()
{
      PathButton(&m_edit7,"path7");
}

void CDlg2::OnBnClickedButton8()
{
      PathButton(&m_edit8,"path8");
}

void CDlg2::OnBnClickedButton9()
{
      PathButton(&m_edit9,"path9");
}

void CDlg2::OnBnClickedButton10()
{
      PathButton(&m_edit10,"path10");
}

void CDlg2::OnCbnSelchangeCombo1()
{
	CString a=m_bo1;
	UpdateData(true);
	CAfx::m_bo1=m_bo1;
	if(1==CAfx::Refesh(CAfx::hwnd2,m_bo1,1001))
	{
			WritePrivateProfileString("Hotkeys","hk1",m_bo1,CAfx::filepath);
	}
	else  
	{
		   //GetPrivateProfileString("Hotkeys","hk1","",m_bo1.GetBuffer(15),15,CAfx::filepath);
		   CAfx::m_bo1=m_bo1=a;
		   MessageBox("热键注册失败，请重新选择！");
	}

	UpdateData(false);
}
void CDlg2::OnCbnSelchangeCombo2()
{
	CString a=m_bo2;
	UpdateData(true);
	CAfx::m_bo2=m_bo2;
	if(1==CAfx::Refesh(CAfx::hwnd2,m_bo2,1002))
	{
		WritePrivateProfileString("Hotkeys","hk2",m_bo2,CAfx::filepath);

	}
	else  
	{
		CAfx::m_bo2=m_bo2=a;
		MessageBox("热键注册失败，请重新选择！");
	}
	UpdateData(false);
}

void CDlg2::OnCbnSelchangeCombo3()
{
	CString a=m_bo3;	
	UpdateData(true);
	CAfx::m_bo3=m_bo3;
	if(1==CAfx::Refesh(CAfx::hwnd2,m_bo3,1003))
	{
		WritePrivateProfileString("Hotkeys","hk3",m_bo3,CAfx::filepath);

	}
	else  
	{
		CAfx::m_bo3=m_bo3=a;
		MessageBox("热键注册失败，请重新选择！");
	}
	UpdateData(false);
}

void CDlg2::OnCbnSelchangeCombo4()
{
	CString a=m_bo4;	
	UpdateData(true);
	CAfx::m_bo4=m_bo4;
	if(1==CAfx::Refesh(CAfx::hwnd2,m_bo4,1004))
	{
		WritePrivateProfileString("Hotkeys","hk4",m_bo4,CAfx::filepath);

	}
	else  
	{
		CAfx::m_bo4=m_bo4=a;
		MessageBox("热键注册失败，请重新选择！");
	}
	UpdateData(false);
}

void CDlg2::OnCbnSelchangeCombo5()
{
	CString a=m_bo5;	
	UpdateData(true);
		CAfx::m_bo5=m_bo5;
	if(1==CAfx::Refesh(CAfx::hwnd2,m_bo5,1005))
	{
		WritePrivateProfileString("Hotkeys","hk5",m_bo5,CAfx::filepath);
	}
	else  
	{
		CAfx::m_bo5=m_bo5=a;
		MessageBox("热键注册失败，请重新选择！");
	}
	UpdateData(false);
}

void CDlg2::OnCbnSelchangeCombo6()
{
	CString a=m_bo6;	
	UpdateData(true);
	CAfx::m_bo6=m_bo6;
	if(1==CAfx::Refesh(CAfx::hwnd2,m_bo6,1006))
	{
		WritePrivateProfileString("Hotkeys","hk6",m_bo6,CAfx::filepath);
	}
	else  
	{
		CAfx::m_bo6=m_bo6=a;
		MessageBox("热键注册失败，请重新选择！");
	}
	UpdateData(false);
}

void CDlg2::OnCbnSelchangeCombo7()
{
	CString a=m_bo7;	
	UpdateData(true);
	CAfx::m_bo7=m_bo7;
	if(1==CAfx::Refesh(CAfx::hwnd2,m_bo7,1007))
	{
		WritePrivateProfileString("Hotkeys","hk7",m_bo7,CAfx::filepath);
	}
	else  
	{
		CAfx::m_bo7=m_bo7=a;
		MessageBox("热键注册失败，请重新选择！");
	}
	UpdateData(false);
}

void CDlg2::OnCbnSelchangeCombo8()
{
	CString a=m_bo8;	
	UpdateData(true);
		CAfx::m_bo8=m_bo8;
	if(1==CAfx::Refesh(CAfx::hwnd2,m_bo8,1008))
	{
		WritePrivateProfileString("Hotkeys","hk8",m_bo8,CAfx::filepath);
	}
	else  
	{
		CAfx::m_bo8=m_bo8=a;
		MessageBox("热键注册失败，请重新选择！");
	}
	UpdateData(false);
}

void CDlg2::OnCbnSelchangeCombo9()
{
	CString a=m_bo9;	
	UpdateData(true);
		CAfx::m_bo9=m_bo9;
	if(1==CAfx::Refesh(CAfx::hwnd2,m_bo9,1009))
	{
		WritePrivateProfileString("Hotkeys","hk9",m_bo9,CAfx::filepath);
	}
	else  
	{
		CAfx::m_bo9=m_bo9=a;
		MessageBox("热键注册失败，请重新选择！");
	}
	UpdateData(false);
}

void CDlg2::OnCbnSelchangeCombo10()
{
	CString a=m_bo10;	
	UpdateData(true);	
	CAfx::m_bo10=m_bo10;
	if(1==CAfx::Refesh(CAfx::hwnd2,m_bo10,1010))
	{
		WritePrivateProfileString("Hotkeys","hk10",m_bo10,CAfx::filepath);
	}
	else  
	{
		CAfx::m_bo10=m_bo10=a;
		MessageBox("热键注册失败，请重新选择！");
	}
	UpdateData(false);
}


void CDlg2::OnOK()
{

}

void CDlg2::OnCancel()
{

}

HBRUSH CDlg2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if(nCtlColor == CTLCOLOR_DLG || CTLCOLOR_STATIC)
	{
		//pDC->SetTextColor(RGB(0,0,255));//字体色
		pDC->SetBkColor(RGB(245,245,255));//字体背景色******
		HBRUSH B = CreateSolidBrush(RGB(245,245,255)); //背景色
		return B;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDlg2::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	WritePrivateProfileStringA(_T("Hotkeys"), _T("path1"), m_edit1, CAfx::filepath);	
}


void CDlg2::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	WritePrivateProfileStringA(_T("Hotkeys"), _T("path2"), m_edit2, CAfx::filepath);
}


void CDlg2::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	WritePrivateProfileStringA(_T("Hotkeys"), _T("path3"), m_edit3, CAfx::filepath);
}


void CDlg2::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	WritePrivateProfileStringA(_T("Hotkeys"), _T("path4"), m_edit4, CAfx::filepath);
}


void CDlg2::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	WritePrivateProfileStringA(_T("Hotkeys"), _T("path5"), m_edit5, CAfx::filepath);
}


void CDlg2::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	WritePrivateProfileStringA(_T("Hotkeys"), _T("path6"), m_edit6, CAfx::filepath);
}


void CDlg2::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	WritePrivateProfileStringA(_T("Hotkeys"), _T("path7"), m_edit7, CAfx::filepath);
}


void CDlg2::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	WritePrivateProfileStringA(_T("Hotkeys"), _T("path8"), m_edit8, CAfx::filepath);
}


void CDlg2::OnEnChangeEdit9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	WritePrivateProfileStringA(_T("Hotkeys"), _T("path9"), m_edit9, CAfx::filepath);
}


void CDlg2::OnEnChangeEdit10()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	WritePrivateProfileStringA(_T("Hotkeys"), _T("path10"), m_edit10, CAfx::filepath);
}
