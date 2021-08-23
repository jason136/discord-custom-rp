#ifndef GUI_H
#define GUI_H

#include "main.h"

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class Frame : public wxFrame {
public:
	Frame();
private:
	wxPanel* panel;
	wxButton* clientID;
	wxButton* input;
	wxStaticText* discordInitialized;
	wxStaticText* clientIDmsg;
	wxStaticText* clientIDtxt;
};

class Dialouge : public wxDialog {
public:
	Dialouge(const wxString& title);
private:
	wxPanel* panel;
	wxBoxSizer* vbox;
	wxBoxSizer* hbox;
	wxStaticBox* box;
	wxTextCtrl* tc;
	wxTextCtrl* tc1;
	wxTextCtrl* tc2;
	wxTextCtrl* tc3;
	wxButton* okButton;
};

#endif