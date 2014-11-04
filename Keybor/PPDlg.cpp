// PPDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Keybor.h"
#include "PPDlg.h"
#include "afxdialogex.h"


// CPPDlg 对话框

IMPLEMENT_DYNAMIC(CPPDlg, CDialog)

CPPDlg::CPPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPPDlg::IDD, pParent)
{

}

CPPDlg::~CPPDlg()
{
}

void CPPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROG1, m_p);
}


BEGIN_MESSAGE_MAP(CPPDlg, CDialog)

	ON_WM_PAINT()
END_MESSAGE_MAP()


// CPPDlg 消息处理程序



void CPPDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码

	// 不为绘图消息调用 
	CDialog::OnPaint();
}
BOOL CPPDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    //制作圆角窗口
	CRect r;
	GetClientRect(&r);
	HRGN rgn;
	rgn = CreateRoundRectRgn(0,0,r.Width()+1,r.Height()+1,4,4);
	SetWindowRgn(rgn,TRUE);

	ModifyStyleEx(WS_EX_APPWINDOW, WS_EX_TOOLWINDOW);     //使窗口不显示在任务栏
	return TRUE;
}	