#pragma once

class CAfx
{
public:
	CAfx(void);
	~CAfx(void);
public :
	static UINT mod;
	static UINT mod2;
	static CString filepath;
    static CString Directorypath;
	static HWND hwnd1;
	static HWND hwnd2;
	static BOOL m_reg;
	static BOOL Refesh(HWND hwnd,CString m_bo, int num);
	static void Register();
	static void UnRegister();

	static CString m_bo1;
	static CString m_bo2;
	static CString m_bo3;
	static CString m_bo4;
	static CString m_bo5;
	static CString m_bo6;
	static CString m_bo7;
	static CString m_bo8;
	static CString m_bo9;
	static CString m_bo10;
    static CString m_bo13;
	static CString m_bo14;
	static CString m_bo15;
	static CString m_bo16;
};
