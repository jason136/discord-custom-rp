#ifndef GUI_H
#define GUI_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/icon.h>
#include <wx/taskbar.h>
#include <iostream>
#include <string>
#include <fstream>

#include "../include/discord_rpc.h"

class DiscordRP : public wxApp {
public:
	void Hide();
	void Show();
private:
	bool OnInit() override;
};

class TaskbarIcon : public wxTaskBarIcon {
public:
	TaskbarIcon() {}

	void OnLeftDoubleClick(wxTaskBarIconEvent&);
	wxDECLARE_EVENT_TABLE();
};

class Window : public wxDialog {
public:
	Window();
	virtual ~Window();
	void OnCloseWindow(wxCloseEvent& event);
	void GetClientID(wxCommandEvent& WXUNUSED(event));
	void GetInput(wxCommandEvent& WXUNUSED(event));
	void Minimize(wxCommandEvent& WXUNUSED(event));

	wxStaticText* clientIDmsg;
	wxStaticText* clientIDtxt;
	wxStaticText* presencetxt;
protected:
	wxPanel* panel;
	wxButton* clientID;
	wxButton* input;
	wxButton* taskbar;
	TaskbarIcon* m_taskBarIcon;

	wxDECLARE_EVENT_TABLE();
};

class Dialog : public wxDialog {
public:
	Dialog(const wxString& title);
private:
	wxPanel* panel;
	wxBoxSizer* vbox;
	wxBoxSizer* hbox;
	wxStaticBox* box;

	wxTextCtrl* detailsCtrl;
	wxStaticText* detailsText;

	wxTextCtrl* stateCtrl;
	wxStaticText* stateText;

	wxTextCtrl* startTSCtrl;
	wxStaticText* startTSText;

	wxTextCtrl* endTSCtrl;
	wxStaticText* endTSText;

	wxTextCtrl* largeKeyCtrl;
	wxStaticText* largeKeyText;

	wxTextCtrl* largeTextCtrl;
	wxStaticText* largeTextText;

	wxTextCtrl* smallKeyCtrl;
	wxStaticText* smallKeyText;

	wxTextCtrl* smallTextCtrl;
	wxStaticText* smallTextText;

	wxTextCtrl* partySizeCtrl;
	wxStaticText* partySizeText;

	wxTextCtrl* partyMaxCtrl;
	wxStaticText* partyMaxText;

	wxButton* okButton;
	wxButton* closeButton;
};

#endif