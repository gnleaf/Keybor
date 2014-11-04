// Dlg3.cpp : 实现文件
//

#include "stdafx.h"
#include "Keybor.h"
#include "Dlg3.h"


// CDlg3 对话框

IMPLEMENT_DYNAMIC(CDlg3, CDialog)

CDlg3::CDlg3(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg3::IDD, pParent)
{

}

CDlg3::~CDlg3()
{
}

void CDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC2, m_here);
}


BEGIN_MESSAGE_MAP(CDlg3, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg3::OnBnClickedButton1)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDlg3 消息处理程序

BOOL CDlg3::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_here.SetURL(_T("http://280686610.qzone.qq.com/"));

// 	m_here.SetLinkCursor(AfxGetApp()->LoadCursor(IDI_HAND));
// 
// 	::SetCursor(::LoadCursor(NULL, IDC_ARROW));
	return TRUE;
}

void CDlg3::OnBnClickedButton1()                               ////快捷方式
{
	// TODO: 在此添加控件通知处理程序代码
	char szPath[MAX_PATH]=_T("");
	char szLink[MAX_PATH]=_T("");
	TCHAR path[MAX_PATH];
	GetModuleFileName(NULL, szPath, MAX_PATH); 
	SHGetSpecialFolderPath(0,path,CSIDL_DESKTOPDIRECTORY,0);
	strcat_s(path,_T("\\Keybor.lnk"));
	CreateLink(szPath, path);
}

BOOL CDlg3::CreateLink(LPSTR   szPath, LPSTR   szLink) ////快捷方式
{ 
	CoInitialize(NULL); 

	HRESULT   hres; 
	IShellLink*   psl; 
	IPersistFile*   ppf; 
	WORD  wsz[MAX_PATH]; 

	hres   =   CoCreateInstance(CLSID_ShellLink,   NULL,   CLSCTX_INPROC_SERVER, 
		IID_IShellLink,   (void**)&psl); 
	if(FAILED(hres)) 
		return   FALSE; 

	psl-> SetPath(szPath); 

	hres   =   psl-> QueryInterface(IID_IPersistFile,   (void**)&ppf); 
	if(FAILED(hres)) 
		return   FALSE; 

	MultiByteToWideChar(CP_ACP,   0,   szLink,   -1,   (LPWSTR)wsz,   MAX_PATH); 

	hres   =   ppf-> Save((LPWSTR)wsz,   STGM_READWRITE); 

	ppf-> Release(); 
	psl-> Release(); 

	CoUninitialize(); 
	return   TRUE; 
} 


HBRUSH CDlg3::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
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
