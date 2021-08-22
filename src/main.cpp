#include <iostream>
#include <fstream>

#include "main.h"
#include "discord.h"
#include "file.h"
#include "../include/discord_rpc.h"

#define ENABLE_TRACE

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

extern struct discord_fields values;

class Dialouge : public wxDialog {
public:
	Dialouge(const wxString& title) : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(250, 230)) {
		wxPanel* panel = new wxPanel(this, -1);

		wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
		wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

		wxStaticBox* st = new wxStaticBox(panel, wxID_ANY, wxT("Colors"),
			wxPoint(5, 5), wxSize(240, 150));

		wxTextCtrl* tc = new wxTextCtrl(panel, wxID_ANY, wxT(""),
			wxPoint(20, 20));

		wxTextCtrl* tc1 = new wxTextCtrl(panel, wxID_ANY, wxT(""),
			wxPoint(20, 50));

		wxTextCtrl* tc2 = new wxTextCtrl(panel, wxID_ANY, wxT(""),
			wxPoint(20, 80));

		wxTextCtrl* tc3 = new wxTextCtrl(panel, wxID_ANY, wxT(""),
			wxPoint(20, 110));

		wxButton* okButton = new wxButton(this, wxID_ANY, wxT("Ok"),
			wxDefaultPosition, wxSize(70, 30));
		wxButton* closeButton = new wxButton(this, wxID_ANY, wxT("Close"),
			wxDefaultPosition, wxSize(70, 30));

		hbox->Add(okButton, 1);
		hbox->Add(closeButton, 1, wxLEFT, 5);

		vbox->Add(panel, 1);
		vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

		SetSizer(vbox);

		Centre();
		ShowModal();
		Destroy();
	}
};

class Frame : public wxFrame {
public:
	Frame() : wxFrame(nullptr, wxID_ANY, "Discord Custom Rich Presence Client") {
		clientID->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
			wxTextEntryDialog textEntryDialog(this, "Message text", "Caption text");

			values.clientID = textEntryDialog.GetValue().mb_str();
			values.clientID = "875580955472068619";
			RefreshFile();

			InitDiscord(values.clientID);

			//InitDiscord(textEntryDialog.GetValue().mb_str(wxConvUTF8));
			//InitDiscord(mystring);
			//InitDiscord("875580955472068619");

			if (textEntryDialog.ShowModal() == wxID_OK) {
				label->SetLabel(values.clientID);
			}
			});

		input->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
			/*Dialouge* dialogue = new Dialouge(wxT("CustomDialog"));
			dialogue->Show(true);*/
			UpdatePresence(values);
			});
	}

private:
	wxPanel* panel = new wxPanel(this);
	wxButton* clientID = new wxButton(panel, wxID_ANY, "Input Client ID", { 10, 10 }, { 100, 20 });
	wxButton* input = new wxButton(panel, wxID_ANY, "Update Presencee", { 10, 80 });
	wxStaticText* label = new wxStaticText(panel, wxID_ANY, values.clientID, {10, 50});
};

class DiscordRP : public wxApp {
	bool OnInit() override {
		GetFile();
		(new Frame())->Show();
		return true;
	}
};

wxIMPLEMENT_APP(DiscordRP);