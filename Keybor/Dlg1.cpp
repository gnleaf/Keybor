// Dlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "Keybor.h"
#include "KeyborDlg.h"
#include "Dlg1.h"
#include "Afx.h"


//using namespace std;
CSetDlg *pDlg;          //定义设置窗口指针
// CDlg1 对话框

IMPLEMENT_DYNAMIC(CDlg1, CDialog)


CDlg1::CDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg1::IDD, pParent)
	, m_bo11(_T(""))
	, m_bo12(_T(""))
	, m_bo13(_T(""))
	, m_bo14(_T(""))
	, m_bo15(_T(""))
	, m_bo16(_T(""))
{
	m_pDlg=new CPPDlg;
	m_pDlg->Create(IDD_VOL);
	m_pProgress=&m_pDlg->m_p;  //引用PPDlg的进度条

 	m_pProgress->SetRange32(m_VControl.GetMinVol(),m_VControl.GetMaxVol());
	int vl = m_VControl.GetVolume();
 	m_pProgress->SetPos(vl); 
}

CDlg1::~CDlg1()
{
}

void CDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO11, m_bo11);
	DDX_CBString(pDX, IDC_COMBO20, m_bo12);
	DDX_CBString(pDX, IDC_COMBO1, m_bo13);
	DDX_CBString(pDX, IDC_COMBO12, m_bo14);
	DDX_CBString(pDX, IDC_COMBO13, m_bo15);
	DDX_CBString(pDX, IDC_COMBO14, m_bo16);
	DDX_Control(pDX, IDC_STATIC1, m_hello);
	DDX_Control(pDX, IDC_STATICSET, m_set);
}


BEGIN_MESSAGE_MAP(CDlg1, CDialog)
	ON_MESSAGE(WM_HOTKEY,OnHotKey)
	ON_WM_DESTROY()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDlg1::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO11, &CDlg1::OnCbnSelchangeCombo11)
	ON_CBN_SELCHANGE(IDC_COMBO12, &CDlg1::OnCbnSelchangeCombo12)
	ON_CBN_SELCHANGE(IDC_COMBO20, &CDlg1::OnCbnSelchangeCombo20)
	ON_CBN_SELCHANGE(IDC_COMBO13, &CDlg1::OnCbnSelchangeCombo13)
	ON_CBN_SELCHANGE(IDC_COMBO14, &CDlg1::OnCbnSelchangeCombo14)
	ON_STN_CLICKED(IDC_STATICSET, &CDlg1::OnStnClickedStaticset)
	ON_WM_CTLCOLOR()
//	ON_WM_NCHITTEST()
ON_WM_TIMER()
ON_WM_DESTROY()
END_MESSAGE_MAP()

// CDlg1 消息处理程序


BOOL CDlg1::OnInitDialog()
{	
	CDialog::OnInitDialog();

	CAfx::hwnd1=GetSafeHwnd();   ////句柄保存为全局

	CFileFind f;
	if (f.FindFile(CAfx::filepath,0))
	{
		GetPrivateProfileString("System","shortcut","",m_bo11.GetBuffer(10),10,CAfx::filepath);
		GetPrivateProfileString("System","shortcut2","",m_bo12.GetBuffer(10),10,CAfx::filepath);
		GetPrivateProfileString("System","volume_up","",m_bo13.GetBuffer(10),10,CAfx::filepath);
		GetPrivateProfileString("System","volume_dn","",m_bo14.GetBuffer(10),10,CAfx::filepath);
		GetPrivateProfileString("System","mute","",m_bo15.GetBuffer(10),10,CAfx::filepath);
		GetPrivateProfileString("System","recycle","",m_bo16.GetBuffer(10),10,CAfx::filepath);

		UpdateData(false);

		//  m_bo11
		if(m_bo11=="Alt")
		{
			CAfx::mod=MOD_ALT;
			((CComboBox*)GetDlgItem(IDC_COMBO20))->DeleteString(1);
		}
		else if(m_bo11=="Control")
		{
			CAfx::mod=MOD_CONTROL;
			((CComboBox*)GetDlgItem(IDC_COMBO20))->DeleteString(2);
		}
		else if(m_bo11=="Shift")
		{
			CAfx::mod=MOD_SHIFT;
			((CComboBox*)GetDlgItem(IDC_COMBO20))->DeleteString(3);
		}
		else if(m_bo11=="Win")
		{
			CAfx::mod=MOD_WIN;
			((CComboBox*)GetDlgItem(IDC_COMBO20))->DeleteString(4);
		}


		else 
			;

		//   m_bo12
		if(m_bo12=="Alt")
			CAfx::mod2=MOD_ALT;
		else if(m_bo12=="Control")
			CAfx::mod2=MOD_CONTROL;
		else if(m_bo12=="Win")
			CAfx::mod2=MOD_WIN;
		else if(m_bo12=="Shift")
			CAfx::mod2=MOD_SHIFT;
		else if(m_bo12=="None")
			CAfx::mod2=NULL;


		//  volume

	}
	else
	{
		CFile file(CAfx::filepath,CFile::modeCreate | CFile::modeWrite);  ////创建配置文件
		file.Write("[System]\r\nPosX=412\r\nPosY=219\r\nPosW=1\r\nshortcut=Alt\r\nshortcut2=None\r\nm_bstart=1\r\nBalloon=1\r\nHide=1\r\nBeginHide=0\r\nvolume_up=PgUp\r\nvolume_dn=PgDn\r\nmute=End\r\nrecycle=Z\r\n[Hot]\r\nKey1=1\r\nKey2=0\r\nvk1=90\r\nsk1=6\r\nvk2=65\r\nsk2=6\r\n[Hotkeys]\r\nhk1=1\r\npath1=\r\nhk2=2\r\npath2=\r\nhk3=3\r\npath3=\r\nhk4=4\r\npath4=\r\nhk5=5\r\npath5=\r\nhk6=6\r\npath6=\r\nhk7=7\r\npath7=\r\nhk8=8\r\npath8=\r\nhk9=9\r\npath9=\r\nhk10=0\r\npath10=",strlen("[System]\r\nPosX=412\r\nPosY=219\r\nPosW=1\r\nshortcut=Alt\r\nshortcut2=None\r\nm_bstart=1\r\nBalloon=1\r\nHide=1\r\nBeginHide=0\r\nvolume_up=PgUp\r\nvolume_dn=PgDn\r\nmute=End\r\nrecycle=Z\r\n[Hot]\r\nKey1=1\r\nKey2=0\r\nvk1=90\r\nsk1=6\r\nvk2=65\r\nsk2=6\r\n[Hotkeys]\r\nhk1=1\r\npath1=\r\nhk2=2\r\npath2=\r\nhk3=3\r\npath3=\r\nhk4=4\r\npath4=\r\nhk5=5\r\npath5=\r\nhk6=6\r\npath6=\r\nhk7=7\r\npath7=\r\nhk8=8\r\npath8=\r\nhk9=9\r\npath9=\r\nhk10=0\r\npath10="));
		file.Close();

		m_bo11="Alt";m_bo12="None";m_bo13="PgUp";m_bo14="PgDn";m_bo15="End";m_bo16="Z";
		((CComboBox*)GetDlgItem(IDC_COMBO20))->DeleteString(1);
		CAfx::mod=MOD_ALT;
		CString   str;
		LPCH     CurrentPath= (LPCH)new WCHAR[sizeof(WCHAR)*100];//程序当前路径
		HKEY   hRegKey;             //注册key
		BOOL   bResult;              //打开注册表返回值
		str=_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run");//注册表
		GetModuleFileName(NULL,CurrentPath,MAX_PATH); //获得运用程序路径
		if(bResult=RegOpenKeyA(HKEY_LOCAL_MACHINE, str, &hRegKey)  !=   ERROR_SUCCESS)//打开注册表     
		{   
			delete[] CurrentPath;
			return TRUE;   
		}

		RegSetValueExA(hRegKey,_T("Keybor"),0,REG_SZ, (const unsigned char *)CurrentPath, MAX_PATH);//打开成功写信息到注册表
		RegCloseKey(hRegKey);   
		delete[] CurrentPath; 
		UpdateData(false);

	}
	CAfx::m_bo13=m_bo13;
	CAfx::m_bo14=m_bo14;
	CAfx::m_bo15=m_bo15;
	CAfx::m_bo16=m_bo16;

    //////创建非模式对话框（初始化），不显示
	
	pDlg=new CSetDlg;
	pDlg->Create(IDD_SETDLG,this); 
	pDlg->CenterWindow();

	m_hello.SetURL("http://hi.baidu.com/hysyyelei", "我的博客，精彩尽在手中");
	m_set.SetToolTipText("点击设置");

	return TRUE;
}


void CDlg1::OnCbnSelchangeCombo1()
{
		   CString a=m_bo13;
		   UpdateData(true);
		   CAfx::m_bo13=m_bo13;
		   if(1==CAfx::Refesh(CAfx::hwnd1,m_bo13,1011))
		   {
		       WritePrivateProfileString("System","volume_up",m_bo13,CAfx::filepath);
		   }
		   else
		   {
			   CAfx::m_bo13=m_bo13=a;
			   MessageBox("热键注册失败，请重新选择！");
		   }
		   UpdateData(false);
}

void CDlg1::OnCbnSelchangeCombo12()
{
	// TODO: 在此添加控件通知处理程序代码

	CString a=m_bo14;
	UpdateData(true);
	CAfx::m_bo14=m_bo14;
	if(1==CAfx::Refesh(CAfx::hwnd1,m_bo14,1012))
	{
		WritePrivateProfileString("System","volume_dn",m_bo14,CAfx::filepath);
	}
	else  
	{
		CAfx::m_bo14=m_bo14=a;
		MessageBox("热键注册失败，请重新选择！");
	}
	UpdateData(false);
}

void CDlg1::OnCbnSelchangeCombo13()
{
	// TODO: 在此添加控件通知处理程序代码

	CString a=m_bo15;
	UpdateData(true);
	CAfx::m_bo15=m_bo15;
	if(1==CAfx::Refesh(CAfx::hwnd1,m_bo15,1013))
	{
		WritePrivateProfileString("System","mute",m_bo15,CAfx::filepath);
	}
	else  
	{
		CAfx::m_bo15=m_bo15=a;
		MessageBox("热键注册失败，请重新选择！");
	}
	UpdateData(false);
}

void CDlg1::OnCbnSelchangeCombo14()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a=m_bo16;
	UpdateData(true);
	CAfx::m_bo16=m_bo16;
	if(1 == CAfx::Refesh(CAfx::hwnd1,m_bo16,1014))
	{
		WritePrivateProfileString("System","recycle",m_bo16,CAfx::filepath);
	}
	else  
	{
		CAfx::m_bo16=m_bo16=a;
		MessageBox("热键注册失败，请重新选择！");
	}
	UpdateData(false);
}

void CDlg1::OnCbnSelchangeCombo11()
{
		UpdateData(true);
        WritePrivateProfileString("System","shortcut",m_bo11,CAfx::filepath);
		 ((CComboBox*)GetDlgItem(IDC_COMBO20))->ResetContent();
		 ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("None");
	     if(m_bo11=="Alt")
		 {
			 CAfx::mod=MOD_ALT;
		     //((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Alt");
		     ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Control");
		     ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Win");
		     ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Shift");
			     if(m_bo12=="Alt")
				 {
					 m_bo12="None";
				     WritePrivateProfileString("System","shortcut2",m_bo12,CAfx::filepath);
				 }
		 }
		 else if(m_bo11=="Control")
		 {
			 CAfx::mod=MOD_CONTROL;
		     ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Alt");
		     //((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Control");
		     ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Win");
		     ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Shift");
			     if(m_bo12=="Control")
				 {
					 m_bo12="None";
				     WritePrivateProfileString("System","shortcut2",m_bo12,CAfx::filepath);
				 }
		 }
		 else if(m_bo11=="Win")
		 {
			 CAfx::mod=MOD_WIN;
		     ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Alt");
		     ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Control");
		    // ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Win");
		     ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Shift");
			     if(m_bo12=="Win")
				 {
					 m_bo12="None";
				     WritePrivateProfileString("System","shortcut2",m_bo12,CAfx::filepath);
				 }
		 }
		 else if(m_bo11=="Shift")
		 {
			 CAfx::mod=MOD_SHIFT;
		     ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Alt");
		     ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Control");
		     ((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Win");
		     //((CComboBox*)GetDlgItem(IDC_COMBO20))->AddString("Shift");
			     if(m_bo12=="Shift")
				 {
					 m_bo12="None";
				     WritePrivateProfileString("System","shortcut2",m_bo12,CAfx::filepath);
				 }
		 }
	     UpdateData(false);


         CAfx::Register();
         ::SetFocus(NULL);
}

void CDlg1::OnCbnSelchangeCombo20()
{
		UpdateData(true);
        WritePrivateProfileString("System","shortcut2",m_bo12,CAfx::filepath);
	    
	     if(m_bo12=="Alt")
			CAfx::mod2=MOD_ALT;
		 else if(m_bo12=="Control")
			 CAfx::mod2=MOD_CONTROL;
		 else if(m_bo12=="Win")
			 CAfx::mod2=MOD_WIN;
		 else if(m_bo12=="Shift")
		     CAfx::mod2=MOD_SHIFT;
		 else if(m_bo12=="None")
             CAfx::mod2=NULL;

			CAfx::Register();
			::SetFocus(NULL);
}


////  热键响应
LRESULT CDlg1::OnHotKey(WPARAM wParam, LPARAM lParam)
{

		if(wParam == 1011 || wParam ==1012)
		{
			SetTimer(1,1400,NULL);

			if(!m_pDlg->IsWindowVisible())
			{
				int xx=::GetSystemMetrics(SM_CXSCREEN);
				int yy=::GetSystemMetrics(SM_CYSCREEN);
				CRect rc;
				m_pDlg->GetWindowRect(rc);
				m_pDlg->SetWindowPos(&CWnd::wndTopMost,xx-100,(yy-rc.Height())/2,0,0,SWP_NOSIZE);
 				m_pDlg->ShowWindow(SW_SHOWNORMAL);
			}
			
		}
		switch(wParam)
		{
			int que, dwVal;
		 case 1011:
			 que=(m_VControl.GetMaxVol() - m_VControl.GetMinVol())/50;
			 dwVal = m_VControl.GetVolume();  //获取当前音量
			 m_VControl.SetVolume(dwVal+que);
			 m_pProgress->SetPos(dwVal+que);
			 break;
		 case 1012:
			 que=(m_VControl.GetMaxVol() - m_VControl.GetMinVol())/50;
			 dwVal = m_VControl.GetVolume();  //获取当前音量
			 if(dwVal>m_VControl.GetMinVol()+que)
			 {
						m_VControl.SetVolume(dwVal-que);
						m_pProgress->SetPos(dwVal-que);
			 }
			break;
		 case 1013:
			 m_VControl.SetMute(m_VControl.GetMute()? 0:1);
		     break;
		 case  1014:
				//清空回收站
				SHEmptyRecycleBin(m_hWnd,NULL,SHERB_NOCONFIRMATION || SHERB_NOPROGRESSUI || SHERB_NOSOUND);
                break;	
		}
return 0;
}

// void CDlg1::OnStnClickedStatic1(UINT nID)
// {
// 	         // TODO: 在此添加控件通知处理程序代码
// 	        //ShellExecute(NULL,   "open",  "http://hi.baidu.com/hysyyelei",   NULL,   NULL,   SW_SHOWNORMAL); 
//             ShellExecute(0,NULL,"http://hi.baidu.com/hysyyelei", NULL, NULL, SW_SHOWMAXIMIZED);
// }


//  重启程序
// void CDlg1::Restart()
// {
// PROCESS_INFORMATION   info;   
// STARTUPINFO startup;   
// char szPath[128];   
// char *szCmdLine;  
// 
// GetModuleFileName(AfxGetApp()->m_hInstance,   szPath,   sizeof(szPath));   
// szCmdLine   =   GetCommandLine();   
// GetStartupInfo(&startup);  
// 
// BOOL   bSucc   =   CreateProcess(szPath,   szCmdLine,   NULL,   NULL,   
// FALSE,   NORMAL_PRIORITY_CLASS,   NULL,   NULL, &startup,   &info);   
// 
//    if(TRUE   &&   bSucc)   
//    {   
//     CWnd *pWnd   =   AfxGetMainWnd();   
//     
//     if(pWnd   !=   NULL)   
//     {   
// //        WaitForSingleObject(info.hProcess,   INFINITE);               
// //      CloseHandle(info.hProcess);       
// //      CloseHandle(info.hThread);
// //      CMainFrame::OnClose();
// CDialog::OnClose();
//       pWnd->PostMessage(WM_CLOSE,   0,   0);  // (关闭原程序)
//     }   
//     else   
//     ExitProcess(-1);   
//    }   
//    else   
//    ExitProcess(-1); 
// 
// }


void CDlg1::OnOK()
{

}

void CDlg1::OnCancel()
{

}

void CDlg1::OnStnClickedStaticset()
{
	// TODO: 在此添加控件通知处理程序代码
	//CKeyborDlg dlg;
	//dlg.SetszTip("hi");
	CKeyborDlg::SetszTip("");
	pDlg->ShowWindow(SW_SHOW);
}


HBRUSH CDlg1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
// 	if(nCtlColor == CTLCOLOR_EDIT)
// 	{
// 		pDC->SetTextColor(RGB(0,0,255));//字体色
// 		pDC->SetBkColor(RGB(245,0,255));//字体背景色*****
// 	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDlg1::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pDlg->ShowWindow(SW_HIDE);


	KillTimer(1);
	CDialog::OnTimer(nIDEvent);
}


void CDlg1::OnDestroy() 
{
	CAfx::UnRegister();  //注销快捷键
	delete pDlg;            //销毁对象

	m_pDlg->DestroyWindow();  //销毁PPDlg对话框
	delete m_pDlg;
	CDialog::OnDestroy();
}

