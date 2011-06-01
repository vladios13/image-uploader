// This file was generated by WTL subclass control wizard 
// LogListBox.h : Declaration of the CLogListBox

#pragma once

#include "resource.h"
#include <atlbase.h>
#include <atlctrls.h>
#include <atlmisc.h>
#include <atlcrack.h>
#define LOGMSGTYPE
typedef enum LogMsgType { logError = 1, logWarning };

struct LogListBoxItem
{
	CString strTitle;
	int TitleHeight;

	CString strText;
	int TextHeight;

	CString Info;
	int InfoHeight;

	LogMsgType Type;
	RECT InfoDim;

	CString Time;
	int nLinesCount;
};

// CLogListBox

class CLogListBox :
	public CWindowImpl<CLogListBox, CListBox,CControlWinTraits>
{
	public:
		CLogListBox();
		~CLogListBox();
		DECLARE_WND_SUPERCLASS(_T("CLogListBox"), CListBox::GetWndClassName())
		
		 BEGIN_MSG_MAP(CLogListBox)
			MSG_WM_KILLFOCUS(OnKillFocus)
			MESSAGE_HANDLER(OCM_DRAWITEM, OnDrawitem)
			MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
			MESSAGE_HANDLER(OCM_MEASUREITEM, OnMeasureItem)
		 END_MSG_MAP()

		 // Handler prototypes:
		 //  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		 //  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		 //  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
		LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL& bHandled);
		
		 LRESULT OnDrawitem(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL& bHandled);
		LRESULT OnMeasureItem(UINT uMsg, WPARAM wParam, LPARAM lParam,BOOL& bHandled);
		int AddString(LogMsgType Type, LPCTSTR szTitle,LPCTSTR szText, LPCTSTR szInfo=NULL);
		LRESULT OnKillFocus(HWND hwndNewFocus);
	public:
		int NotifyParent(int nItem);
		CIcon ErrorIcon, WarningIcon;
		CFont UnderlineFont, NormalFont, BoldFont;
		BOOL SubclassWindow(HWND hWnd);
		void Init();
		void Clear();
		
};


