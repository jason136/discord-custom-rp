#ifndef ICON_H
#define ICON_H

#include <wx/wxprec.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/taskbar.h>
#include <wx/mstream.h >
#include <wx/menu.h>

class TaskbarIcon : wxTaskBarIcon {
public:
	TaskbarIcon();
	wxTaskBarIcon* taskBarIcon;
	void Minimize();
	void Maximize();
	void OnLeftDoubleClick(wxTaskBarIconEvent& event);
	virtual wxMenu* CreatePopupMenu();
private:
	wxIcon icon;
};

#endif