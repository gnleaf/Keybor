// LoadDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Keybor.h"
#include "LoadDlg.h"
#include "Afx.h"

// CLoadDlg 对话框

IMPLEMENT_DYNAMIC(CLoadDlg, CDialog)

CLoadDlg::CLoadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoadDlg::IDD, pParent)
{

}

CLoadDlg::~CLoadDlg()
{
}

void CLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoadDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoadDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON11, &CLoadDlg::OnBnClickedButton11)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CLoadDlg 消息处理程序

BOOL CLoadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(GetPrivateProfileIntA("Load","星空破解",0,CAfx::filepath));
	((CButton*)GetDlgItem(IDC_CHECK7))->SetCheck(GetPrivateProfileIntA("Load","急速拨号",0,CAfx::filepath));
	((CButton*)GetDlgItem(IDC_CHECK8))->SetCheck(GetPrivateProfileIntA("Load","计划关机",0,CAfx::filepath));
	((CButton*)GetDlgItem(IDC_CHECK9))->SetCheck(GetPrivateProfileIntA("Load","Web生活",0,CAfx::filepath));
	((CButton*)GetDlgItem(IDC_CHECK10))->SetCheck(GetPrivateProfileIntA("Load","Keybor截屏",0,CAfx::filepath));
	((CButton*)GetDlgItem(IDC_CHECK11))->SetCheck(GetPrivateProfileIntA("Load","Keybor锁屏",0,CAfx::filepath));
	((CButton*)GetDlgItem(IDC_CHECK12))->SetCheck(GetPrivateProfileIntA("Load","桌面盒子",0,CAfx::filepath));
    ((CButton*)GetDlgItem(IDC_CHECK13))->SetCheck(GetPrivateProfileIntA("Load","短信提醒",0,CAfx::filepath));


	return TRUE;
}
void CLoadDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//星空破解
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		WritePrivateProfileStringA("Load","星空破解","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		WritePrivateProfileStringA("Load","星空破解","0",CAfx::filepath);
	}
	//急速拨号
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck())
	{
		WritePrivateProfileStringA("Load","急速拨号","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck())
	{
		WritePrivateProfileStringA("Load","急速拨号","0",CAfx::filepath);
	}

	//计划关机
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck())
	{
		WritePrivateProfileStringA("Load","计划关机","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck())
	{
		WritePrivateProfileStringA("Load","计划关机","0",CAfx::filepath);
	}

	//Web生活
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck())
	{
		WritePrivateProfileStringA("Load","Web生活","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck())
	{
		WritePrivateProfileStringA("Load","Web生活","0",CAfx::filepath);
	}
	//Keybor截屏
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK10))->GetCheck())
	{
		WritePrivateProfileStringA("Load","Keybor截屏","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK10))->GetCheck())
	{
		WritePrivateProfileStringA("Load","Keybor截屏","0",CAfx::filepath);
	}
	//Keybor锁屏
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck())
	{
		WritePrivateProfileStringA("Load","Keybor锁屏","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck())
	{
		WritePrivateProfileStringA("Load","Keybor锁屏","0",CAfx::filepath);
	}
	//桌面盒子
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck())
	{
		WritePrivateProfileStringA("Load","桌面盒子","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck())
	{
		WritePrivateProfileStringA("Load","桌面盒子","0",CAfx::filepath);
	}
	//短信提醒
	if(BST_CHECKED== ((CButton*)GetDlgItem(IDC_CHECK13))->GetCheck())
	{
		WritePrivateProfileStringA("Load","短信提醒","1",CAfx::filepath);
	}
	else if (BST_UNCHECKED== ((CButton*)GetDlgItem(IDC_CHECK13))->GetCheck())
	{
		WritePrivateProfileStringA("Load","短信提醒","0",CAfx::filepath);
	}
}


void CLoadDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}


HBRUSH CLoadDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
