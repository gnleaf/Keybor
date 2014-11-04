// Dlg5.cpp : 实现文件
//

#include "stdafx.h"
#include "Keybor.h"
#include "Dlg5.h"
#include "Afx.h"
#include "LoadDlg.h"
// CDlg5 对话框

IMPLEMENT_DYNAMIC(CDlg5, CDialog)

CDlg5::CDlg5(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg5::IDD, pParent)
{

}

CDlg5::~CDlg5()
{
}

void CDlg5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SET, m_set);
	DDX_Control(pDX, IDC_SET2, m_set2);
}


BEGIN_MESSAGE_MAP(CDlg5, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg5::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON14, &CDlg5::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON11, &CDlg5::OnBnClickedButton11)
	ON_STN_CLICKED(IDC_SET, &CDlg5::OnStnClickedSet)
	ON_BN_CLICKED(IDC_BUTTON13, &CDlg5::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlg5::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON12, &CDlg5::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON15, &CDlg5::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON17, &CDlg5::OnBnClickedButton17)
	ON_STN_CLICKED(IDC_SET2, &CDlg5::OnStnClickedSet2)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlg5 消息处理程序


BOOL CDlg5::OnInitDialog()
{
	    CDialog::OnInitDialog();
		 //PcStart();      ////初始化中发送开机提示邮件

		m_bt1.SubclassDlgItem(IDC_BUTTON1, this);
		m_bt1.SetIcon(IDI_XKJS);
		m_bt1.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt1.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt1.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt1.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt1.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt1.EnableBalloonTooltip();
		m_bt1.SetTooltipText(_T("星空极速密码破解\r\n内含MD5转换"));
		m_bt1.SetRounded(TRUE,FALSE);		

		m_bt2.SubclassDlgItem(IDC_BUTTON11, this);
		m_bt2.SetIcon(IDI_JSBH);
		m_bt2.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt2.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt2.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt2.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt2.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt2.EnableBalloonTooltip();
		m_bt2.SetTooltipText(_T("极速拨号\r\n拨号成功后不再占用系统资源！"));
		m_bt2.SetRounded(TRUE,FALSE);

		m_bt3.SubclassDlgItem(IDC_BUTTON13, this);
		m_bt3.SetIcon(IDI_JHGJ);
		m_bt3.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt3.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt3.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt3.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt3.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt3.EnableBalloonTooltip();
		m_bt3.SetTooltipText(_T("设置定时关闭计算机"));
		m_bt3.SetRounded(TRUE,FALSE);

		m_bt4.SubclassDlgItem(IDC_BUTTON2, this);
		m_bt4.SetIcon(IDI_Web);
		m_bt4.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt4.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt4.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt4.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt4.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt4.EnableBalloonTooltip();
		m_bt4.SetTooltipText(_T("飞秋,随时随地聊天"));
		m_bt4.SetRounded(TRUE,FALSE);

		m_bt5.SubclassDlgItem(IDC_BUTTON12, this);
		m_bt5.SetIcon(IDI_JP);
		m_bt5.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt5.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt5.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt5.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt5.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt5.EnableBalloonTooltip();
		m_bt5.SetTooltipText(_T("Keybor截屏\r\n优秀的截屏工具，不一样的体验！"));
		m_bt5.SetRounded(TRUE,FALSE);

		m_bt6.SubclassDlgItem(IDC_BUTTON14, this);
		m_bt6.SetIcon(IDI_PIN);
		m_bt6.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt6.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt6.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt6.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt6.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt6.EnableBalloonTooltip();
		m_bt6.SetTooltipText(_T("锁屏"));
		m_bt6.SetRounded(TRUE,FALSE);

		m_bt7.SubclassDlgItem(IDC_BUTTON15, this);
		m_bt7.SetIcon(IDI_SET);
		m_bt7.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt7.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt7.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt7.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt7.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt7.EnableBalloonTooltip();
		m_bt7.SetTooltipText(_T("桌面盒子"));
		m_bt7.SetRounded(TRUE,FALSE);

		m_bt8.SubclassDlgItem(IDC_BUTTON17, this);
		m_bt8.SetIcon(IDI_MESSAGE);
		m_bt8.SetAlign(CButtonST::ST_ALIGN_VERT,FALSE);
		m_bt8.SetColor(CButtonST::BTNST_COLOR_FG_IN,0xFF0000,FALSE);
		m_bt8.SetColor(CButtonST::BTNST_COLOR_BK_IN,0x33CC70,FALSE);
		m_bt8.SetColor(CButtonST::BTNST_COLOR_BK_OUT,0xFFFFFF,FALSE);
		m_bt8.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS,0xFFFFFF,FALSE);
		m_bt8.EnableBalloonTooltip();
		m_bt8.SetTooltipText(_T("短信提醒"));
		m_bt8.SetRounded(TRUE,FALSE);

		if(GetPrivateProfileIntA(_T("System"),_T("BeginHide"),0,CAfx::filepath))
		{
			m_set.SetWindowText(_T("启动隐藏"));
			m_set.SetToolTipText(_T("启动扩展应用将隐藏主窗口"));
		}
		else
		{
			m_set.SetWindowText(_T("启动不隐藏"));
			m_set.SetToolTipText(_T("启动扩展应用将不再隐藏主窗口"));
		}
		m_set2.SetToolTipText(_T("Keybor启动时加载应用项设置"));

		//Keybor启动加载项目
		if(GetPrivateProfileIntA(_T("Load"), _T("星空破解"),0,CAfx::filepath))
			OnBnClickedButton1();
		if(GetPrivateProfileIntA(_T("Load"), _T("急速拨号"),0,CAfx::filepath))
			OnBnClickedButton11();
		if(GetPrivateProfileIntA(_T("Load"),_T("计划关机"),0,CAfx::filepath))
			OnBnClickedButton13();
		if(GetPrivateProfileIntA(_T("Load"),_T("Web生活"),0,CAfx::filepath))
			OnBnClickedButton2();
		if(GetPrivateProfileIntA(_T("Load"), _T("Keybor截屏"),0,CAfx::filepath))
			OnBnClickedButton12();
		if(GetPrivateProfileIntA(_T("Load"),_T("Keybor锁屏"),0,CAfx::filepath))
			OnBnClickedButton14();
		if(GetPrivateProfileIntA(_T("Load"),_T("桌面盒子"),0,CAfx::filepath))
			OnBnClickedButton15();
		if(GetPrivateProfileIntA(_T("Load"),_T("短信提醒"),0,CAfx::filepath))
			OnBnClickedButton17();


		return TRUE;
}

void CDlg5::PcStart()         /////////////////////电脑开机邮件提示
{
       
// TODO: Add your control notification handler code here
char buff[100];
CString curuser=_T("administrator");
CString curmailfrom;
CString currcptto=_T("15886495012");
CString curdomain=_T("domain.com");
CString strsubject=_T("电脑已开机");
CString strmessagebody=_T("您电脑已开机，正在运行Keybor");
CString strtemp;
CString	strmail;

//curuser="abc";


currcptto+=_T("@qq.com");
curmailfrom.Format(_T("%s@%s"), curuser,curdomain);
memset(buff,0,100);

if(!m_socket.Create())
{
	//MessageBox("创建socket失败.");
	return;
}
if(!m_socket.Connect(_T("mx0.qq.com"),25))
{
	//MessageBox("连接服务器失败");
	return;
}
//连接成功后取得欢迎信息
m_socket.Receive(buff,100);
if (!IsSameString(buff,3,_T("220")))
{
	m_socket.Close();
	//MessageBox(buff,"220错误");
	return;
}
//发送HELO命令
sprintf_s(buff,_T("HELO %s\r\n"),curdomain);
m_socket.Send(buff,strlen(buff));
m_socket.Receive(buff,100);
if (!IsSameString(buff,3,_T("250")))
{
	m_socket.Send(_T("QUIT\r\n"),strlen(_T("QUIT\r\n")));
	//m_socket.Receive(buff,100);
	m_socket.Close();
	//MessageBox(buff,"HELO命令返回错误");
	return ;
}
//发送MAIL FROM命令
sprintf_s(buff,_T("MAIL FROM:<%s>\r\n"),curmailfrom);
m_socket.Send(buff,strlen(buff));
m_socket.Receive(buff,100);
if (!IsSameString(buff,3,_T("250")))
{
	m_socket.Send(_T("QUIT\r\n"),strlen(_T("QUIT\r\n")));
	//m_socket.Receive(buff,100);
	m_socket.Close();
	//MessageBox(buff,"MAIL FROM命令返回错误");
	return;
}
//发送RCPT TO命令
sprintf_s(buff,_T("RCPT TO:<%s>\r\n"),currcptto);
m_socket.Send(buff,strlen(buff));
m_socket.Receive(buff,100);
if (IsSameString(buff,3,_T("550")))
{
	m_socket.Send(_T("QUIT\r\n"),strlen(_T("QUIT\r\n")));
	m_socket.Receive(buff,100);
	//m_socket.Close();
	strtemp.Format(_T("你的邮件收件人地址不存在\r\n服务器信息:%s"),buff);
	//MessageBox(strtemp);
	return;
}
if (!IsSameString(buff,3,_T("250")))
{
	m_socket.Send(_T("QUIT\r\n"),strlen(_T("QUIT\r\n")));
	//m_socket.Receive(buff,100);
	m_socket.Close();
	//MessageBox(buff,"RCPT TO命令返回错误");
	return;
}
sprintf_s(buff,_T("DATA\r\n"));
m_socket.Send(buff,strlen(buff));
m_socket.Receive(buff,100);
if (!IsSameString(buff,3,_T("354")))
{
	m_socket.Send(_T("QUIT\r\n"),strlen(_T("QUIT\r\n")));
	//m_socket.Receive(buff,100);
	m_socket.Close();
	//MessageBox(buff,"DATA命令返回错误");
	return;
}

//按照格式来构造邮件
strmail=_T("");
strtemp.Format(_T("From: \"%s\" <%s>\r\n"),curuser,curmailfrom);
strmail+=strtemp;
strtemp.Format(_T("To: <%s>\r\n"),currcptto);
strmail+=strtemp;
strtemp.Format(_T("Subject: %s\r\n"),strsubject);
strmail+=strtemp;
CTime time=CTime::GetCurrentTime();
strtemp=time.Format(_T("Date: %a,%d %b %Y %X +0800\r\n")); //"Date: Thu, 30 Aug 2007 15:23:32 +0800\r\n";  //预留日期
strmail+=strtemp;
strtemp=_T("Content-Type: multipart/mixed; boundary=\"#BOUNDARY.CMAILSERVER#\"\r\n\r\n\r\n");
strmail+=strtemp;
strtemp=_T("--#BOUNDARY.CMAILSERVER#\r\n");
strmail+=strtemp;
strtemp=_T("Content-Type: text/html; charset=\"gb2312\"\r\nContent-Transfer-Encoding: 7bit\r\n\r\n");
strmail+=strtemp;
strmail+=strmessagebody;
strtemp=_T("\r\n\r\n--#BOUNDARY.CMAILSERVER#--\r\n\r\n.\r\n");
strmail+=strtemp;

//发送邮件正文

m_socket.Send(strmail,strmail.GetLength());
m_socket.Receive(buff,100);
if (!IsSameString(buff,3,_T("250")))
{
	m_socket.Send(_T("QUIT\r\n"),strlen(_T("QUIT\r\n")));
	//m_socket.Receive(buff,100);
	m_socket.Close();
	//MessageBox(buff,"DATA命令返回错误");
	return;
}
//发送QUIT命令
sprintf_s(buff,_T("QUIT\r\n"));
m_socket.Send(buff,strlen(buff));
m_socket.Receive(buff,100);
if (!IsSameString(buff,3,_T("221")))
{
	//MessageBox(buff,"QUIT命令返回错误");
	return;
}
m_socket.Close();
//MessageBox("发送成功");

}


void CDlg5::OnBnClickedButton1()       // 星空破解dll
{
	// TODO: 在此添加控件通知处理程序代码
	HideMainWnd();
	HINSTANCE hInst;
	hInst=LoadLibrary(_T("XingBreak.dll"));
	typedef int (*ADDPROC)();
	ADDPROC XingBreak=(ADDPROC)GetProcAddress(hInst,_T("XingBreak"));
// 	if(!XingBreak)
// 	{
// 		//MessageBox("获取函数地址失败!");
// 		return;
// 	}
	//XingBreak();

	FreeLibrary(hInst);
}

void CDlg5::OnBnClickedButton14()      //锁屏
{
	// TODO: 在此添加控件通知处理程序代码


}

void CDlg5::OnBnClickedButton11()      //极速拨号（扩展）
{
	// TODO: 在此添加控件通知处理程序代码
	HideMainWnd();
	CString str=CAfx::Directorypath+_T("Dial\\极速拨号.exe");
	char dial[100];
	strcpy_s(dial,str);
	ShellExecuteA(NULL,NULL,dial,NULL,NULL,SW_SHOWNORMAL);
}

void CDlg5::OnBnClickedButton13()           //计划关机
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDlg5::OnBnClickedButton2()            //飞秋
{
	// TODO: 在此添加控件通知处理程序代码
	HideMainWnd();
	CString str=CAfx::Directorypath+_T("feiq\\飞秋FeiQ.exe");
	char dial[100];
	strcpy_s(dial,str);
	ShellExecuteA(NULL,NULL,dial,NULL,NULL,SW_SHOWNORMAL);
}


void CDlg5::OnBnClickedButton12()         //截屏（扩展）
{
	// TODO: 在此添加控件通知处理程序代码
	HideMainWnd();
	CString str=CAfx::Directorypath+_T("Cut Screen\\截屏.exe");
	char jp[100];
	strcpy_s(jp,str);
	ShellExecuteA(NULL,NULL,jp,NULL,NULL,SW_SHOWNORMAL);
}


void CDlg5::OnBnClickedButton15()        //桌面盒子
{
	// TODO: 在此添加控件通知处理程序代码
	HideMainWnd();
	CString str=CAfx::Directorypath+_T("DeskBox\\DeskBox.exe");
	char jp[100];
	strcpy_s(jp,str);
	ShellExecuteA(NULL,NULL,jp,NULL,NULL,SW_SHOWNORMAL);
}


void CDlg5::OnBnClickedButton17()        //短信提示
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDlg5::HideMainWnd()
{
	if (GetPrivateProfileIntA(_T("System"),_T("BeginHide"),0,CAfx::filepath))
	{
		AfxGetMainWnd()->ShowWindow(SW_HIDE);
	}
}

void CDlg5::OnStnClickedSet()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_set.GetWindowText(str);
	if(str==_T("启动隐藏"))
	{
				GetDlgItem(IDC_SET)->SetWindowText(_T("启动不隐藏"));
				m_set.SetToolTipText(_T("启动扩展应用将不再隐藏主窗口"));
				WritePrivateProfileString(_T("System"),_T("BeginHide"),_T("0"),CAfx::filepath);
	}
	else
	{
				GetDlgItem(IDC_SET)->SetWindowText(_T("启动隐藏"));
				m_set.SetToolTipText(_T("启动扩展应用将隐藏主窗口"));
				WritePrivateProfileString(_T("System"),_T("BeginHide"),_T("1"),CAfx::filepath);
	}
	Invalidate();  //更新窗口
}

void CDlg5::OnStnClickedSet2()
{
	// TODO: 在此添加控件通知处理程序代码
	CLoadDlg dlg;
	dlg.DoModal();
}

void CDlg5::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rect; 
	GetClientRect(&rect); //计算对话框的尺寸 
	dc.FillSolidRect(&rect,RGB(255,255,255)); //绘制对话框背景色
	// TODO: 在此处添加消息处理程序代码
	 CDialog::OnPaint();
}
