// This file was generated by WTL Dialog wizard 
// UpdateDlg.h : Declaration of the CUpdateDlg

#pragma once

#include "resource.h"       // main symbols
#include "Func/UpdatePackage.h"
#include "3rdpart/thread.h"

class CUpdateDlg : 
	public CDialogImpl<CUpdateDlg>,
	public CDialogResize<CUpdateDlg>,
	public CThreadImpl<CUpdateDlg>, 
	public CUpdateStatusCallback
{
	public:
		CUpdateDlg();
		~CUpdateDlg();
		enum { IDD = IDD_UPDATEDLG };

		class CUpdateDlgCallback
		{
			public:
				virtual bool CanShowWindow() = 0;
				virtual void UpdateAvailabilityChanged(bool Available) = 0;
		};
	protected:
		BEGIN_MSG_MAP(CUpdateDlg)
			MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
			MESSAGE_HANDLER(WM_TIMER, OnTimer)
			COMMAND_HANDLER(IDOK, BN_CLICKED, OnClickedOK)
			COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnClickedCancel)
			CHAIN_MSG_MAP(CDialogResize<CUpdateDlg>)
		END_MSG_MAP()

		BEGIN_DLGRESIZE_MAP(CUpdateDlg)
			DLGRESIZE_CONTROL(IDC_UPDATELISTVIEW, DLSZ_SIZE_X|DLSZ_SIZE_Y)
			DLGRESIZE_CONTROL(IDC_UPDATEINFO,  DLSZ_SIZE_X | DLSZ_SIZE_Y)
			DLGRESIZE_CONTROL(IDOK, DLSZ_MOVE_X| DLSZ_MOVE_Y)
			DLGRESIZE_CONTROL(IDCANCEL, DLSZ_MOVE_X|DLSZ_MOVE_Y)
		END_DLGRESIZE_MAP()
    // Handler prototypes:
    //  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    //  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
    //  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
	LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	
	CListViewCtrl m_listView;
	bool m_bUpdateFinished;
	CUpdateDlgCallback* m_UpdateCallback;
	void setUpdateCallback(CUpdateDlgCallback* callback);
	DWORD Run();
	bool stop;
	bool m_Checked;
	bool m_Modal;
	void CheckUpdates();
	void DoUpdates();
	CEvent m_UpdateEvent;
	int m_bClose;
	bool m_InteractiveUpdate;
	CUpdateManager m_UpdateManager;
	bool ShowModal(HWND parent);
	void Abort();
	void updateStatus(int packageIndex, const CString& status);
};


