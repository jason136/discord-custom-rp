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

	wxTextCtrl* stateCtrl;
	wxStaticText* stateText;

	wxTextCtrl* detailsCtrl;
	wxStaticText* detailsText;

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
};

#endif