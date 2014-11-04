// Keybor.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "Keybor.h"
#include "KeyborDlg.h"
#include "Afx.h"
#include "XMessageBox.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CKeyborApp

BEGIN_MESSAGE_MAP(CKeyborApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CKeyborApp 构造

CKeyborApp::CKeyborApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CKeyborApp 对象

CKeyborApp theApp;


// CKeyborApp 初始化

BOOL CKeyborApp::InitInstance()
{
	XMSGBOXPARAMS xmb;
	xmb.nTimeoutSeconds  = 2;
	//xmb.nDisabledSeconds = 0;
	xmb.nIdIcon          = 0;

	//xmb.x = 50;
	//xmb.y = 20;

	xmb.dwOptions |= XMSGBOXPARAMS::VistaStyle;

	HANDLE m_hMutex=CreateMutex(NULL,TRUE, m_pszAppName); 
	if(GetLastError()==ERROR_ALREADY_EXISTS) {XMessageBox(NULL,"该程序正在运行!","Keybor",MB_OK | MB_ICONQUESTION, &xmb); return FALSE; }
	/////////////////一个实例


	if (!AfxSocketInit())
	{
		//AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}
//  char pathfile[100];
//  GetCurrentDirectory(sizeof(pathfile),pathfile);


  //pathfile="C:\\Program Files\\Keybor";  
//   if(PathFileExistsA(pathfile)==FALSE)//判断目录是否存在   
//   {   
//           if(CreateDirectory(pathfile,NULL)==FALSE)          //不存在则创建路径文件夹
//           AfxMessageBox("创建文挡目录出错");   
//   }
//   CreateDirectory(pathfile,NULL);


	TCHAR exeFullPath[MAX_PATH]; 
	CString strPath; 
	GetModuleFileName(NULL,exeFullPath,MAX_PATH); 
	strPath=(CString)exeFullPath; 
	int position=strPath.ReverseFind('\\'); 
	strPath=strPath.Left(position+1);  
	TCHAR FilePath[MAX_PATH]; 
	GetModuleFileName(NULL,FilePath,MAX_PATH); 
	(_tcsrchr(FilePath,'\\'))[1] = 0;
	CAfx::Directorypath=FilePath;
	lstrcat(FilePath,_T("Keybor.ini"));
	CAfx::filepath=FilePath;

	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CKeyborDlg dlg;
	 
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。

	return FALSE;
}
BOOL IsSameString(LPCSTR buff,int n,LPCSTR str)	//比对两个字符串的前多少位是否相同
{
	int i;

	for (i=0;i<n;i++)
	{
		if (buff[i]!=str[i]) return FALSE;
	}
	return TRUE;
}