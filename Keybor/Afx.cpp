#include "StdAfx.h"
#include "Afx.h"

UINT CAfx::mod=0;
UINT CAfx::mod2=0;
CString CAfx::filepath=_T("");
CString CAfx::Directorypath=_T("");
HWND CAfx::hwnd1=NULL;
HWND CAfx::hwnd2=NULL;
BOOL  CAfx::m_reg=TRUE;
CString CAfx::m_bo1=_T("");
CString CAfx::m_bo2=_T("");
CString CAfx::m_bo3=_T("");
CString CAfx::m_bo4=_T("");
CString CAfx::m_bo5=_T("");
CString CAfx::m_bo6=_T("");
CString CAfx::m_bo7=_T("");
CString CAfx::m_bo8=_T("");
CString CAfx::m_bo9=_T("");
CString CAfx::m_bo10=_T("");

CString CAfx::m_bo13=_T("");
CString CAfx::m_bo14=_T("");
CString CAfx::m_bo15=_T("");
CString CAfx::m_bo16=_T("");

CAfx::CAfx(void)
{
}

CAfx::~CAfx(void)
{
}



BOOL CAfx::Refesh(HWND hwnd,CString m_bo, int num)
{
	CString as;
    as.Format("%d",m_bo.GetAt(0));
    m_bo.ReleaseBuffer();
	if(m_bo.GetLength()==1)
	{
		        int m = atoi(as);
// 				if (m <)
// 				{
// 				}
				if(!RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,atoi(as)))
						 return 0;
				else
						 return 1;
	}
	else
	{
				if(m_bo==_T("Home") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_HOME))
							return 0;
				else if(m_bo==_T("End") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_END))
							return 0;
				else if(m_bo==_T("PgUp")&&0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_PRIOR))
							return 0;
				else if(m_bo==_T("PgDn") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_NEXT))
							return 0;
				else if(m_bo==_T("Up") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_UP))
					return 0;
				else if(m_bo==_T("Down") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_DOWN))
					return 0;
				else if(m_bo==_T("Left") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_LEFT))
					return 0;
				else if(m_bo==_T("Right") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_RIGHT))
					return 0;
				else if(m_bo==_T("F1") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_F1))
					return 0;
				else if(m_bo==_T("F2") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_F2))
					return 0;
				else if(m_bo==_T("F3") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_F3))
					return 0;
				else if(m_bo==_T("F4") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_F4))
					return 0;
				else if(m_bo==_T("F5") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_F5))
					return 0;
				else if(m_bo==_T("F6") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_F6))
					return 0;
				else if(m_bo==_T("F7") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_F7))
					return 0;
				else if(m_bo==_T("F8") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_F8))
					return 0;
				else if(m_bo==_T("F9") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_F9))
					return 0;
				else if(m_bo==_T("F10") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_F10))
					return 0;
				else if(m_bo==_T("F11") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_F11))
					return 0;
				else if(m_bo==_T("F12") && 0==RegisterHotKey(hwnd,num,CAfx::mod | CAfx::mod2,VK_F12))
					return 0;
				else
				    return 1;
	}
}

//×¢²á¿ì½Ý¼ü
void CAfx::Register()
{
	CAfx::Refesh(hwnd2,m_bo1, 1001);
	CAfx::Refesh(hwnd2,m_bo2, 1002);
	CAfx::Refesh(hwnd2,m_bo3, 1003);
	CAfx::Refesh(hwnd2,m_bo4, 1004);
	CAfx::Refesh(hwnd2,m_bo5, 1005);
	CAfx::Refesh(hwnd2,m_bo6, 1006);
	CAfx::Refesh(hwnd2,m_bo7, 1007);
	CAfx::Refesh(hwnd2,m_bo8, 1008);
	CAfx::Refesh(hwnd2,m_bo9, 1009);
	CAfx::Refesh(hwnd2,m_bo10, 1010);

	CAfx::Refesh(hwnd1,m_bo13, 1011);
	CAfx::Refesh(hwnd1,m_bo14, 1012);
	CAfx::Refesh(hwnd1,m_bo15, 1013);
	CAfx::Refesh(hwnd1,m_bo16, 1014);
}

//×¢Ïú¿ì½Ý¼ü
void CAfx::UnRegister()
{
	UnregisterHotKey(CAfx::hwnd1,1011);
	UnregisterHotKey(CAfx::hwnd1,1012);
	UnregisterHotKey(CAfx::hwnd1,1013);
	UnregisterHotKey(CAfx::hwnd1,1014);

	UnregisterHotKey(CAfx::hwnd2,1001);
	UnregisterHotKey(CAfx::hwnd2,1002);
	UnregisterHotKey(CAfx::hwnd2,1003);
	UnregisterHotKey(CAfx::hwnd2,1004);
	UnregisterHotKey(CAfx::hwnd2,1005);
	UnregisterHotKey(CAfx::hwnd2,1006);
	UnregisterHotKey(CAfx::hwnd2,1007);
	UnregisterHotKey(CAfx::hwnd2,1008);
	UnregisterHotKey(CAfx::hwnd2,1009);
	UnregisterHotKey(CAfx::hwnd2,1010);
}
