// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include "funcs.h"

class CMainDlg : public SHostWnd
{
public:
	CMainDlg();
	~CMainDlg();

	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();

	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);
	
	void OnBtnInstall();
	void OnBtnSpoof();
	void OnBtnApply();
	void OnCtxMenu(EventArgs *pEvt);

protected:
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_NAME_COMMAND(L"btn_install", OnBtnInstall)
		EVENT_NAME_COMMAND(L"btn_uninstall", OnBtnInstall)
		EVENT_NAME_COMMAND(L"btn_spoof", OnBtnSpoof)
		EVENT_NAME_COMMAND(L"btn_apply", OnBtnApply)
		EVENT_NAME_HANDLER(L"hd0_new", EVT_CTXMENU, OnCtxMenu)
		EVENT_NAME_HANDLER(L"hd1_new", EVT_CTXMENU, OnCtxMenu)
		EVENT_NAME_HANDLER(L"hd2_new", EVT_CTXMENU, OnCtxMenu)
		EVENT_NAME_HANDLER(L"hd3_new", EVT_CTXMENU, OnCtxMenu)
		EVENT_NAME_HANDLER(L"hd4_new", EVT_CTXMENU, OnCtxMenu)
		EVENT_NAME_HANDLER(L"hd5_new", EVT_CTXMENU, OnCtxMenu)
		EVENT_MAP_END()
	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)


		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	void InitWnd();
	bool ReleaseSys();
	bool DeleteSys();
	void StrToSN(const TCHAR* str, byte* sn);
	void SNToStr(const byte* sn, TCHAR* str);
private:
	BOOL			m_bLayoutInited;
	bool serviceInstalled;
	HDSNInfo originSN;
	HDSNInfo newSN;
};
