/*
    Image Uploader - program for uploading images/files to Internet
    Copyright (C) 2007-2015 ZendeN <zenden2k@gmail.com>
	 
    HomePage:    http://zenden.ws/imageuploader

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef GUI_DIALOGS_LOGINDLG_H
#define GUI_DIALOGS_LOGINDLG_H

#pragma once
#include "atlheaders.h"
#include "resource.h"       // main symbols
#include "Core/Upload/UploadEngine.h"
#include "3rdpart/thread.h"
#include "Gui/Controls/PictureExWnd.h"

class ServerProfile;
// CLoginDlg

LoginInfo LoadLogin(int ServerId);

class CLoginDlg : public CDialogImpl<CLoginDlg>	, public CThreadImpl<CLoginDlg>
{
	public:
		int ServerId;
		CLoginDlg(ServerProfile& serverProfile,bool CreateNew = false );
		~CLoginDlg();
		enum { IDD = IDD_LOGINDLG };
	protected:
		BEGIN_MSG_MAP(CLoginDlg)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
			COMMAND_HANDLER(IDOK, BN_CLICKED, OnClickedOK)
			COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnClickedCancel)
			COMMAND_HANDLER(IDC_USEIECOOKIES, BN_CLICKED, OnClickedUseIeCookies)
			COMMAND_ID_HANDLER(IDC_DELETEACCOUNTLABEL, OnDeleteAccountClicked)
			COMMAND_ID_HANDLER(IDC_DOLOGINLABEL, OnDoLoginClicked)	
			COMMAND_HANDLER(IDC_LOGINEDIT, EN_CHANGE, OnLoginEditChange);
		END_MSG_MAP()
		// Handler prototypes:
		//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
		LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		LRESULT OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		LRESULT OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		LRESULT OnClickedUseIeCookies(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		LRESULT OnDeleteAccountClicked(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		LRESULT OnDoLoginClicked(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		LRESULT OnLoginEditChange(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
		CUploadEngineData *m_UploadEngine;
		CString accountName();
		DWORD Run();
		void OnProcessFinished();
		void Accept();
protected:
	ServerProfile& serverProfile_;
	CHyperLink deleteAccountLabel_;
	CHyperLink doLoginLabel_;
	CString accountName_;
	bool createNew_;
	bool ignoreExistingAccount_;
	bool serverSupportsBeforehandAuthorization_;
	void enableControls(bool enable);
	NetworkClient NetworkClient_;
	CPictureExWnd wndAnimation_;
	
};

#endif // LOGINDLG_H


