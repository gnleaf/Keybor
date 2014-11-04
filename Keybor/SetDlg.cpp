// SetDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Keybor.h"
#include "SetDlg.h"
// CSetDlg 对话框

IMPLEMENT_DYNAMIC(CSetDlg, CDialog)

CSetDlg::CSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDlg::IDD, pParent)
{

}

CSetDlg::~CSetDlg()
{
}

void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HOTKEY1, m_hot1);
	DDX_Control(pDX, IDC_HOTKEY2, m_hot2);
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &CSetDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CSetDlg::OnBnClickedButton1)
	ON_WM_HOTKEY()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSetDlg 消息处理程序

BOOL CSetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    ///////////////////////////////////  气泡提示  /////////////////////////////////////    
	UINT Balloon=GetPrivateProfileIntA("System","Balloon",1,CAfx::filepath);
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(Balloon);

	////////////////////////////////   开机启动初始化  //////////////////////////////////
	UINT start=GetPrivateProfileIntA("System","m_bstart",1,CAfx::filepath);
	((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(start);

	if(start)
	{
		CString   str;                     
		LPCH     CurrentPath= (LPCH)new WCHAR[sizeof(WCHAR)*100];//程序当前路径
		HKEY   hRegKey;             //注册key
		BOOL   bResult;              //打开注册表返回值
		str=_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run");//注册表   
		GetModuleFileName(NULL,CurrentPath,MAX_PATH); //获得运用程序路径
		if(bResult=RegOpenKeyA(HKEY_LOCAL_MACHINE,   str,   &hRegKey)   !=   ERROR_SUCCESS)//打开注册表     
		{   
			delete[] CurrentPath;
			return TRUE;   
		}
		RegSetValueExA(hRegKey,_T("Keybor"),0,REG_SZ, (const unsigned char *)CurrentPath, MAX_PATH);//打开成功写信息到注册表
		RegCloseKey(hRegKey);   
		delete[] CurrentPath; 
	}
	 /////////////////////////////////////   启动隐藏主窗口初始化 //////////////////////////////////
	UINT Hide=GetPrivateProfileIntA("System","Hide",1,CAfx::filepath);
	((CButton*)GetDlgItem(IDC_CHECK5))->SetCheck(Hide);
    //////////////////////////////////////////   老板键初始化  /////////////////////////////////
	UINT Hot1=GetPrivateProfileIntA("Hot","Key1",1,CAfx::filepath);
	((CButton*)GetDlgItem(IDC_CHECK4))->SetCheck(Hot1);
	
		WORD vk1=GetPrivateProfileIntA("Hot","vk1",0,CAfx::filepath);
		WORD sk1=GetPrivateProfileIntA("Hot","sk1",0,CAfx::filepath);
		m_hot1.SetHotKey(vk1,sk1);

	if(Hot1)
	{
		UINT fs1 = 0;
		if (sk1 & HOTKEYF_ALT)	    fs1|= MOD_ALT;
		if (sk1 & HOTKEYF_CONTROL)   fs1|= MOD_CONTROL;
		if (sk1 & HOTKEYF_SHIFT) 	fs1|= MOD_SHIFT; 	
		RegisterHotKey(m_hWnd, 111, fs1, vk1);	
	}
	//***************************************退出键初始化*************************************//
	UINT Hot2=GetPrivateProfileIntA("Hot","Key2",1,CAfx::filepath);
	((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(Hot2);

	WORD vk2=GetPrivateProfileIntA("Hot","vk2",0,CAfx::filepath);
	WORD sk2=GetPrivateProfileIntA("Hot","sk2",0,CAfx::filepath);
	m_hot2.SetHotKey(vk2,sk2);
	if(Hot2)
	{
		UINT fs2 = 0;
		if (sk2 & HOTKEYF_ALT)	    fs2|= MOD_ALT;
		if (sk2 & HOTKEYF_CONTROL)   fs2|= MOD_CONTROL;
		if (sk2 & HOTKEYF_SHIFT) 	fs2|= MOD_SHIFT; 	
		RegisterHotKey(m_hWnd, 222, fs2, vk2);		
    }
	//***************************************窗口置顶******************************************//
	UINT PosW=GetPrivateProfileIntA("System","PosW",1,CAfx::filepath);
	((CButton*)GetDlgItem(IDC_CHECK6))->SetCheck(PosW);
	if (PosW)
		//让设置对话框显示在屏幕最前方
		AfxGetMainWnd()->SetWindowPos(&wndTopMost,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);

	::SetFocus(NULL);
	return TRUE;
}
void CSetDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
	CWnd *pWnd=AfxGetMainWnd();
// 	pWnd->AnimateWindow( 200,   AW_BLEND);   //淡入
//     UpdateData(FALSE);

	pWnd->ShowWindow(SW_SHOWNORMAL);
   
}
void CSetDlg::OnBnClickedButton1()
{
	/////////////////////////////////////    气泡提示  ////////////////////////////////////
	 if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	 {
		 WritePrivateProfileStringA("System","Balloon","1",CAfx::filepath);
	 }
	 if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	 {
		 WritePrivateProfileStringA("System","Balloon","0",CAfx::filepath);
	 }
	 /////////////////////////////////////   开机启动   //////////////////////////////////
	 CString   str;                     
	 LPCH     CurrentPath= (LPCH)new WCHAR[sizeof(WCHAR)*100];//程序当前路径
	 HKEY   hRegKey;             //注册key
	 BOOL   bResult;              //打开注册表返回值
	 str=_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run");//注册表   
	 GetModuleFileName(NULL,CurrentPath,MAX_PATH); //获得运用程序路径
	 if(bResult=RegOpenKeyA(HKEY_LOCAL_MACHINE,   str,   &hRegKey)   !=   ERROR_SUCCESS)//打开注册表     
	 {   
		 delete[] CurrentPath;
		 return;   
	 }

	 if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())
	 {
		 RegSetValueExA(hRegKey,_T("Keybor"),0,REG_SZ, (const unsigned char *)CurrentPath, MAX_PATH);//打开成功写信息到注册表
		 RegCloseKey(hRegKey);   
		 delete[] CurrentPath; 
		 WritePrivateProfileString("System","m_bstart","1",CAfx::filepath);
	 }

	 if(BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())
	 {
		 RegDeleteValue(hRegKey,"Keybor");
		 RegCloseKey(hRegKey);
		 delete[] CurrentPath;
		 WritePrivateProfileString("System","m_bstart","0",CAfx::filepath);
	 }
	 /////////////////////////////////////   启动隐藏主窗口 //////////////////////////////////
	 if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck())
	 {
		 WritePrivateProfileStringA("System","Hide","1",CAfx::filepath);
	 }
	 if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck())
	 {
		 WritePrivateProfileStringA("System","Hide","0",CAfx::filepath);
	 }
	 ///////////////////////////////////////   启用老板键   ///////////////////////////////////
	 
	 UpdateData();
	 if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck())
	 {
		 WritePrivateProfileStringA("Hot","Key1","1",CAfx::filepath);
	 }
	 if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck())
	 {
		 WritePrivateProfileStringA("Hot","Key1","0",CAfx::filepath);
	 }
	 WORD vk1, sk1;
	 m_hot1.GetHotKey(vk1,sk1);
	 CString m_vk1,m_sk1;
	 m_vk1.Format("%d",vk1);
	 m_sk1.Format("%d",sk1);
	 WritePrivateProfileStringA("Hot","vk1",m_vk1,CAfx::filepath);
	 WritePrivateProfileStringA("Hot","sk1",m_sk1,CAfx::filepath);

	 UINT fs1 = 0;
	 if (sk1 & HOTKEYF_ALT)	    fs1|= MOD_ALT;
	 if (sk1 & HOTKEYF_CONTROL)   fs1|= MOD_CONTROL;
	 if (sk1 & HOTKEYF_SHIFT) 	fs1|= MOD_SHIFT; 	

	 RegisterHotKey(m_hWnd, 111, fs1, vk1);

	//************************************退出键*********************************// 
	 if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck())
	 {
		 WritePrivateProfileStringA("Hot","Key2","1",CAfx::filepath);
	 }
	 if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck())
	 {
		 WritePrivateProfileStringA("Hot","Key2","0",CAfx::filepath);
	 }
	 WORD vk2,sk2;
	 m_hot2.GetHotKey(vk2,sk2);
	 CString m_vk2,m_sk2;
	 m_vk2.Format("%d",vk2);
	 m_sk2.Format("%d",sk2);
	 WritePrivateProfileStringA("Hot","vk2",m_vk2,CAfx::filepath);
	 WritePrivateProfileStringA("Hot","sk2",m_sk2,CAfx::filepath);
	 UINT fs2 = 0;
	 if (sk2 & HOTKEYF_ALT)	    fs2|= MOD_ALT;
	 if (sk2 & HOTKEYF_CONTROL)   fs2|= MOD_CONTROL;
	 if (sk2 & HOTKEYF_SHIFT) 	fs2|= MOD_SHIFT; 	
	 RegisterHotKey(m_hWnd, 222, fs2, vk2);
	 ///////////////////////////////////////   启用退出键   ///////////////////////////////////

	 //*****************************************窗口置顶****************************************//
	 if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck())
	 {
		 WritePrivateProfileStringA("System","PosW","1",CAfx::filepath);
		 AfxGetMainWnd()->SetWindowPos(&wndTopMost,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE);
	 }
	 if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck())
	 {
		 WritePrivateProfileStringA("System","PosW","0",CAfx::filepath);
		 AfxGetMainWnd()->SetWindowPos(&wndNoTopMost,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE);
	 }
	 //*******************************************************************************************//
}

void CSetDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nHotKeyId)
	{

	case 111:
		if (!AfxGetMainWnd()->ShowWindow(SW_HIDE))
		{
			CKeyborDlg dlg;
			dlg.OnSet();
		}
		break;
	case 222:
		//************************************保存对话框坐标**********************************//
		CString rt1,rt2;
		RECT r;
		AfxGetMainWnd()->GetWindowRect(&r);
		rt1.Format("%d",r.left);
		rt2.Format("%d",r.top);
		WritePrivateProfileStringA("System","PosX",rt1,CAfx::filepath);
		WritePrivateProfileStringA("System","PosY",rt2,CAfx::filepath);
        AfxGetMainWnd()->SendMessage(WM_CLOSE);    //给主窗口发送消息推出程序
		break;
	}

	CDialog::OnHotKey(nHotKeyId, nKey1, nKey2);
}


HBRUSH CSetDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
