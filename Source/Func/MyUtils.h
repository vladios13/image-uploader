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

#ifndef _MYUTILS_H_
#define _MYUTILS_H_

#include <atlheaders.h>
#include <tchar.h>
#include <stdlib.h>

#include <string>
#define APPNAME _T("Image Uploader")
//#define VIDEO_DIALOG_FORMATS _T("Video files (avi, mpg, vob, wmv, flv, etc)\0*.avi;*.mpeg;*.mpg;*.mp2;*.divx;*.vob;*.flv;*.wmv;*.asf;*.mkv;*.mp4;*.ts;*.mov;*.mpeg2ts;*.3gp;\0All files\0*.*\0\0")
#define VIDEO_FORMATS _T("avi\0mpg\0mpeg\0vob\0divx\0flv\0wmv\0asf\0mkv\0mov\0ts\0mp2\0mp4\0")_T("3gp\0rm\0mpeg2ts\0\0")
#define IMAGE_DIALOG_FORMATS _T("Image files (JPEG, GIF, PNG, etc)\0*.jpg;*.gif;*.png;*.bmp;*.tiff\0All files\0*.*\0\0")

#ifndef IU_SHELLEXT
const CString StringSection(const CString& str,TCHAR sep, int index);
std::wstring strtows(const std::string &str, UINT codePage);
std::string wstostr(const std::wstring &ws, UINT codePage);
#define WstrToUtf8(str) IuCoreUtils::WstringToUtf8(str)
//wstostr(str, CP_UTF8)
#define WCstringToUtf8(str) wstostr(((LPCTSTR)(str)), CP_UTF8)
const std::wstring Utf8ToWstring(const std::string &str);
#define Utf8ToWCstring(str) CString(Utf8ToWstring(str).c_str())
const std::string AnsiToUtf8(const std::string &str, int codepage);
const std::string Utf8ToAnsi(const std::string &str, int codepage);
#endif

#define xor(a,b) ((a || b) && !(a && b))	

#define CheckBounds(n,a,b,d) {if((n<a) || (n>b)) n=d;}


int GetFontSize(int nFontHeight);
int GetFontHeight(int nFontSize);

bool ExtractStrFromList(
            LPCTSTR szString /* Source string */,
            int nIndex, /* Zero based item index */
            LPTSTR szBuffer /* Destination buffer */,
            LONG nSize ,/* Length in characters of destionation buffer */
            LPCTSTR szDefString = NULL,
            TCHAR cSeparator = _T(',') /* Character to be separator in list */);
#define LOADICO(ico) LoadIcon(GetModuleHandle(0), MAKEINTRESOURCE(ico))

bool FontToString(LOGFONT const * lFont, CString &Result);
bool StringToFont(LPCTSTR szBuffer,LPLOGFONT lFont);
LPTSTR ExtractFilePath(LPCTSTR FileName,LPTSTR buf);
int GetFontSizeInTwips(int nFontSize);
const CString myExtractFileName(const CString & FileName);

LPCTSTR GetFileExt(LPCTSTR szFileName);
bool IsImage(LPCTSTR szFileName);
bool IsVideoFile(LPCTSTR szFileName);

const CString GetOnlyFileName(const CString& szFilename);
bool ReadSetting(LPTSTR szSettingName,int* Value,int DefaultValue,LPTSTR szString=NULL,LPTSTR szDefString=NULL);
int GetSavingFormat(LPCTSTR szFileName);
bool IsStrInList(LPCTSTR szExt,LPCTSTR szList);
int MyGetFileSize(LPCTSTR FileName);

LPTSTR fgetline(LPTSTR buf,int num,FILE *f);
BOOL FileExists(LPCTSTR FileName);
const CString TrimString(const CString& source, int nMaxLen);

bool NewBytesToString(__int64 nBytes, LPTSTR szBuffer, int nBufSize);

LPCTSTR  CopyToStartOfW(LPCTSTR szString,LPCTSTR szPattern,LPTSTR szBuffer,int nBufferSize);
CString IntToStr(int n);


CString DisplayError(int idCode);

HFONT MakeFontUnderLine(HFONT font);
HFONT MakeFontBold(HFONT font);
LPTSTR MoveToEndOfW(LPTSTR szString,LPTSTR szPattern);

//#ifdef DEBUG
	void ShowX(LPCTSTR str,int line,int n);

	void ShowX(LPCTSTR str,int line,float n);
	void ShowX(LPCTSTR str,int line,LPCTSTR n);
	#define ShowVar(n) ShowX(_T(#n),__LINE__,n)
//#endif
#ifndef IU_SHELLEXT


#define PROP_OBJECT_PTR			MAKEINTATOM(ga.atom)
#define PROP_ORIGINAL_PROC		MAKEINTATOM(ga.atom)

/*
 * typedefs
 */
class CGlobalAtom
{
public:
	CGlobalAtom(void)
	{ atom = GlobalAddAtom(TEXT("_Hyperlink_Object_Pointer_")
	         TEXT("\\{AFEED740-CC6D-47c5-831D-9848FD916EEF}")); }
	~CGlobalAtom(void)
	{ DeleteAtom(atom); }

	ATOM atom;
};

/*
 * Local variables
 */
static CGlobalAtom ga;
#endif
#endif

bool IsDirectory(LPCTSTR szFileName);
bool IsVista();

FILE * fopen_utf8(const char * filename, const char * mode);
bool CheckFileName(const CString& fileName);