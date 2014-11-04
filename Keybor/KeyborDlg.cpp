// KeyborDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Keybor.h"
#include "KeyborDlg.h"
#include "Afx.h"
#include "BCMenu.h"
#include "XMessageBox.h"

#define WM_NOTIFYICON 111

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKeyborDlg 对话框


CDlg1 dlg1;
CDlg2 dlg2;
CDlg3 dlg3;
CDlg4 dlg4;
CDlg5 dlg5;

CKeyborDlg::CKeyborDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKeyborDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CKeyborDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tab);
}

BEGIN_MESSAGE_MAP(CKeyborDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_NCPAINT()
//	ON_WM_LBUTTONDOWN()
	ON_MESSAGE(WM_NOTIFYICON,OnNotifyIcon)
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771,OnSet)
	ON_COMMAND(ID_32772,OnExit)
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CKeyborDlg::OnTcnSelchangeTab1)
	ON_WM_CLOSE()
	ON_COMMAND(ID_32773, &CKeyborDlg::OnQuitTime)
	ON_MESSAGE(WM_HOTKEY,OnHotKey)
	ON_COMMAND(ID_32779, &CKeyborDlg::On32779)
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// CKeyborDlg 消息处理程序

BOOL CKeyborDlg::OnInitDialog()
{
	
	CDialog::OnInitDialog();
 
	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_tab.InsertItem(0," 基本设置 "); //添加参数一选项卡 
    m_tab.InsertItem(1," 快捷映射 "); //添加参数二选项卡 
	m_tab.InsertItem(2," 计划任务 "); 
	m_tab.InsertItem(3," 扩展应用 ");
    m_tab.InsertItem(4," 关于 "); //添加结果选项卡 

	//关联对话框,并且将IDC_TAB控件设为父窗口 
	dlg1.Create(IDD_DIALOG1,GetDlgItem(IDC_TAB)); 
	dlg2.Create(IDD_DIALOG2,GetDlgItem(IDC_TAB)); 
	dlg4.Create(IDD_DIALOG4,GetDlgItem(IDC_TAB)); 
	dlg5.Create(IDD_DIALOG5,GetDlgItem(IDC_TAB));
	dlg3.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB)); 

	//获得IDC_TABTEST客户区大小 
	CRect rs; 
	m_tab.GetClientRect(&rs ); 
	//调整子对话框在父窗口中的位置 
	rs.top+=22; 
	rs.bottom+=30; 
	//rs.left+=1; 
	//rs.right-=2; 

	//设置子对话框尺寸并移动到指定位置 
	dlg1.MoveWindow(&rs); 
	dlg2.MoveWindow(&rs); 
	dlg3.MoveWindow(&rs); 
	dlg4.MoveWindow(&rs);
	dlg5.MoveWindow(&rs);

	//分别设置隐藏和显示  
	dlg1.ShowWindow(true);
	dlg2.ShowWindow(false); 
	dlg3.ShowWindow(false); 
	dlg4.ShowWindow(false); 
	dlg5.ShowWindow(false);

	//设置默认的选项卡 
	m_tab.SetCurSel(0);

    CString m_good;
	CTime ct = CTime::GetCurrentTime();
	int hour = ct.GetHour();
	if(hour>=0 && hour<6)
		m_good="凌晨好，熬夜？强悍！注意休息！";
	else if(hour>=6 && hour<8)
		m_good="早上好，这个时候得看书啊！";
	else if(hour>=8 && hour<11)
		m_good="上午好，现在清净啊，呵呵！";
	else if(hour>=11 && hour<13)
		m_good="中午好，现在是休息时间咯！";
	else if(hour>=13 && hour<19)
		m_good="下午好，嘿嘿";
	else if(hour>=19)
		m_good="晚上好，别玩太晚了，早点睡觉lo！";

	notifydata.cbSize=sizeof(NOTIFYICONDATA);
	notifydata.hWnd=this->m_hWnd;
	notifydata.uCallbackMessage=WM_NOTIFYICON;
	notifydata.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP;
	notifydata.uID=IDI_ICON1;
	notifydata.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON1));
	strcpy_s(notifydata.szTip," Keybor for you");
	Shell_NotifyIconA(NIM_ADD,&notifydata);

	if(GetPrivateProfileIntA("System","Balloon",1,CAfx::filepath))
	{
		ShowBalloonTip("尊敬的客户"+m_good,"Keybor", 3000, 1);//弹出气泡提示
	}

//*******************************获取对话框坐标*********************************//
	RECT rect;
	rect.left=GetPrivateProfileIntA("System","PosX",0,CAfx::filepath);
	rect.top=GetPrivateProfileIntA("System","PosY",0,CAfx::filepath);
	rect.right=rect.left+473;
	rect.bottom=rect.top+362;
	MoveWindow(&rect);

    UpdateWindow();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

BOOL CKeyborDlg::ShowBalloonTip(LPCTSTR szMsg, LPCTSTR szTitle, UINT uTimeout, DWORD dwInfoFlags)
{
	//notifydata.cbSize=sizeof(NOTIFYICONDATA);
	notifydata.uFlags = NIF_INFO;
	notifydata.uTimeout = uTimeout;
	notifydata.dwInfoFlags = dwInfoFlags;
	strcpy_s(notifydata.szInfo,szMsg ? szMsg : _T(""));
	strcpy_s(notifydata.szInfoTitle,szTitle ? szTitle : _T(""));
	return Shell_NotifyIcon(NIM_MODIFY, &notifydata);
}

void CKeyborDlg::SetszTip(LPCTSTR str)
{
// 	notifydata.uFlags=NIF_TIP;
// 	strcpy_s(notifydata.szTip,str);
// 	Shell_NotifyIconA(NIM_MODIFY,&notifydata);
}

void CKeyborDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if(nID==SC_CLOSE)
	{
        ShowWindow(SW_HIDE);
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CKeyborDlg::OnPaint()
{		


		if (IsIconic())
		{
			CPaintDC dc(this); // 用于绘制的设备上下文
			SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

			// 使图标在工作区矩形中居中
			int cxIcon = GetSystemMetrics(SM_CXICON);
			int cyIcon = GetSystemMetrics(SM_CYICON);
			CRect rect;
			GetClientRect(&rect);
			int x = (rect.Width() - cxIcon + 1) / 2;
			int y = (rect.Height() - cyIcon + 1) / 2;

			// 绘制图标
			dc.DrawIcon(x, y, m_hIcon);
		}
		else
		{
			CDialog::OnPaint();
		}
}

void CKeyborDlg::OnNcPaint() 
{
      // TODO: Add your message handler code here
	//**********************隐藏窗口************************//
	 if(GetPrivateProfileIntA("System","Hide",1,CAfx::filepath))
	 {
     static int i = 2; 
      if(i>0) 
      { 
           i--;
           ShowWindow(SW_HIDE); 
      } 
	 }
    CDialog::OnNcPaint();
}



//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CKeyborDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CKeyborDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int CurSel = m_tab.GetCurSel(); 
	switch(CurSel) 
	{ 
	case 0: 
	dlg1.ShowWindow(true);
	dlg2.ShowWindow(false); 
	dlg3.ShowWindow(false); 
	dlg4.ShowWindow(false);
	dlg5.ShowWindow(false);
	::SetFocus(NULL);
	break; 
	case 1: 
	dlg1.ShowWindow(false);    
	dlg2.ShowWindow(true); 
	dlg3.ShowWindow(false); 
	dlg4.ShowWindow(false);
	dlg5.ShowWindow(false);
	::SetFocus(NULL);
	break; 
	case 2: 
	dlg1.ShowWindow(false);     
	dlg2.ShowWindow(false);    
	dlg3.ShowWindow(false); 
	dlg4.ShowWindow(true);
	dlg5.ShowWindow(false);
	::SetFocus(NULL);
	break; 
	case 3: 
	dlg1.ShowWindow(false); 
	dlg2.ShowWindow(false);     
	dlg3.ShowWindow(false); 
	dlg4.ShowWindow(false); 
	dlg5.ShowWindow(true);
	::SetFocus(NULL);
	break; 
	case 4: 
		dlg1.ShowWindow(false);     
		dlg2.ShowWindow(false);    
		dlg3.ShowWindow(true); 
		dlg4.ShowWindow(false);
		dlg5.ShowWindow(false);
		::SetFocus(NULL);
		break; 
	default: 
	; 
	} 

	*pResult = 0;
}

//void CKeyborDlg::OnLButtonDown(UINT nFlags, CPoint point) 
//{
//    // 调用父类处理函数完成基本操作
//    CDialog::OnLButtonDown(nFlags, point);
//
//    // 发送WM_NCLBUTTONDOWN消息
//    // 使Windows认为鼠标在标题条上
//    PostMessage(WM_NCLBUTTONDOWN,HTCAPTION, MAKELPARAM(point.x, point.y));
//}

LRESULT CKeyborDlg::OnNotifyIcon(WPARAM wParam,LPARAM lParam)
{
	//单击鼠标左键
	 if((lParam==WM_LBUTTONDOWN)&&(!ShowWindow(SW_HIDE)))
	 { 	
             OnSet();
	 }

	//鼠标单击右键
	 if(lParam==WM_RBUTTONDOWN)
	 {
		  //  弹出菜单
		  POINT rpoint;
	      GetCursorPos(&rpoint);
	      BCMenu mu;
		  mu.LoadMenu(IDR_MENU1);
          SetForegroundWindow();
		  mu.GetSubMenu(0)->SetDefaultItem(ID_32779);
		  mu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,rpoint.x,rpoint.y,this);
	 }
	 
	 return 0;

}


void CKeyborDlg::OnExit()
{    
		XMSGBOXPARAMS xmb;
		//xmb.nTimeoutSeconds  = 3;
		//xmb.nDisabledSeconds = 0;
		xmb.nIdIcon          = 0;
	
 	    //xmb.x = 50;
 	    //xmb.y = 20;
	
		xmb.dwOptions |= XMSGBOXPARAMS::VistaStyle;
	
		if( IDOK == ::XMessageBox(m_hWnd, _T("确定退出Keybor？"), _T("提示"), 
						MB_OKCANCEL | MB_ICONQUESTION, &xmb))
		{
//************************************保存对话框坐标**********************************//
			CString rt1,rt2/*,rt3,rt4*/;
			RECT r;
			GetWindowRect(&r);
			rt1.Format("%d",r.left);
			rt2.Format("%d",r.top);
			///////////////////////////测试主对话框宽度和高度
// 			rt3.Format("%d",r.right-r.left);
// 			rt4.Format("%d",r.bottom-r.top);
// 			MessageBox(rt3,rt4,0);
			WritePrivateProfileStringA("System","PosX",rt1,CAfx::filepath);
			WritePrivateProfileStringA("System","PosY",rt2,CAfx::filepath);
//***************************************************************************************//
			SendMessage(WM_CLOSE);
		}
}
void CKeyborDlg::OnSet()
{
	    AfxGetMainWnd()->ShowWindow(SW_MINIMIZE);
	    //AnimateWindow( 500,   AW_BLEND);   //淡入
		//Invalidate();
	    AfxGetMainWnd()->ShowWindow(SW_RESTORE);		 
		::SetFocus(NULL);			
}

void CKeyborDlg::OnOK()
{

}

void CKeyborDlg::OnCancel()
{
	   AnimateWindow(500,   AW_BLEND   |   AW_HIDE   );   //淡出
}
	
void CKeyborDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialog::OnOK();
	Shell_NotifyIcon(NIM_DELETE,&notifydata);
}

void CKeyborDlg::OnQuitTime()
{
	// TODO: 在此添加命令处理程序代码
	dlg4.OnBnClickedButton12();
}

LRESULT CKeyborDlg::OnHotKey(WPARAM wParam, LPARAM lParam)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//if(wParam==1014)

	if (!ShowWindow(SW_HIDE))
		OnSet();

    return 0;
}
void CKeyborDlg::On32779()
{
	// TODO: 在此添加命令处理程序代码
	if(CAfx::m_reg)
	{
		  CAfx::UnRegister();
	      CAfx::m_reg=FALSE;
	}
	else
	{
		  CAfx::Register();
          CAfx::m_reg=TRUE;
	}
}

LRESULT CKeyborDlg::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
       CRect rc;
	   GetClientRect(&rc);
	   ClientToScreen(&rc);
	   return rc.PtInRect(point) ? HTCAPTION : CDialog::OnNcHitTest(point);
}
