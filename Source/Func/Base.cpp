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
 
#include "Base.h"
#include "Func/Settings.h"
#include "Core/Utils/CoreUtils.h"
#include <Func/LocalFileCache.h>

ZBase* ZBase::m_base = 0;

void ZBase::cleanUp()
{
	delete m_base;
}

ZBase::ZBase()
{
	m_hm.setHistoryFileName(Settings.SettingsFolder+"/History/","history");
}

ZBase* ZBase::get()
{
	if(m_base == 0) {
		m_base = new ZBase();
		atexit(&cleanUp);
	}
	return m_base;
}

CHistoryManager* ZBase::historyManager() 
{
	return &m_hm;
}


void ZBase::addToGlobalCache(const std::string fileName, const std::string url)
{
	LocalFileCache::instance().addFile(url, fileName);
	//m_UrlCache[url] = fileName;
}

std::string ZBase::getFromCache(const std::string url)
{
	return LocalFileCache::instance().get(url);

}