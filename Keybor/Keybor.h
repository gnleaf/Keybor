// Keybor.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#define WINDOWPLACEMENT_KEY "Window Placement"
#define SETTINGS_KEY "Software\\CompanyName\\ApplicationName\\Settings"

BOOL IsSameString(LPCSTR buff,int n,LPCSTR str);	//比对两个字符串的前多少位是否相同
// CKeyborApp:
// 有关此类的实现，请参阅 Keybor.cpp
//

class CKeyborApp : public CWinApp
{
public:
	CKeyborApp();
	CString pathfile;
// 重写
protected:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CKeyborApp theApp;