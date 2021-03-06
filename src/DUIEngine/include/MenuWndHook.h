/*########################################################################
	Filename: 	MenuWndHook.h
	----------------------------------------------------
	Remarks:	...
	----------------------------------------------------
	Author:		成真
	Email:		anyou@sina.com
				anyou@msn.com
	Created:	7/4/2003 17:37
  ########################################################################*/

#pragma once

namespace DuiEngine
{

/*########################################################################
			  ------------------------------------------------
							 CMenuWndHook 类
			  ------------------------------------------------
  ########################################################################*/
class DUI_EXP CMenuWndHook
{
// 建构 ---------------------------------------------------------
public:
    CMenuWndHook(HWND hWnd);
    ~CMenuWndHook();
    static void InstallHook(HINSTANCE hInst,LPCSTR pszSkinName=NULL);
    static void UnInstallHook();

// 消息 ----------------------------------------------------------
public:
    static LRESULT CALLBACK CoolMenuProc (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK WindowHook (int code, WPARAM wParam, LPARAM lParam);

    int  OnCreate(LPCREATESTRUCT lpCreateStruct);
    void OnNcCalcsize(BOOL bValidCalc,NCCALCSIZE_PARAMS* lpncsp);
    void OnNcDestroy();
    void OnPrint(CDCHandle dc);
    void OnNcPaint();
    void OnWindowPosChanging(WINDOWPOS* pWindowPos);
    void SetLayeredAttr();

// 操作 ----------------------------------------------------------
public:
    static CMenuWndHook* AddWndHook(HWND hwnd);
    static CMenuWndHook* GetWndHook(HWND hwnd);

// 数据 -----------------------------------------------------------
protected:
    HWND m_hWnd;

    static CDuiMap<HWND, CMenuWndHook*> m_WndMenuMap;
    static HHOOK m_hMenuHook;
    static CDuiStringA	m_strSkinName;
};

}//namespace DuiEngine