#ifndef ICON_H
#define ICON_H

#include <wx/wxprec.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/taskbar.h>
#include <wx/mstream.h >
#include <wx/menu.h>

class TaskbarIcon : public wxTaskBarIcon {
public:
	TaskbarIcon();
	wxTaskBarIcon* taskBarIcon;
	void Minimize();
	void Maximize();

	void OnLeftDoubleClick(wxTaskBarIconEvent&);
	void OnMenuRestore(wxCommandEvent&);
	void OnMenuExit(wxCommandEvent&);
	void OnMenuSetNewIcon(wxCommandEvent&);
	void OnMenuCheckmark(wxCommandEvent&);
	void OnMenuUICheckmark(wxUpdateUIEvent&);
	void OnMenuSub(wxCommandEvent&);
	virtual wxMenu* CreatePopupMenu() wxOVERRIDE;

	wxDECLARE_EVENT_TABLE();

	wxIcon icon;
};

#endif