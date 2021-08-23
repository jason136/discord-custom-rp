#include "main.h"
#include "gui.h"
#include "discord.h"
#include "file.h"

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

extern discord_fields values;

Dialouge::Dialouge(const wxString& title) : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(500, 300)) {
	panel = new wxPanel(this, -1);

	vbox = new wxBoxSizer(wxVERTICAL);
	hbox = new wxBoxSizer(wxHORIZONTAL);

	box = new wxStaticBox(panel, wxID_ANY, wxT("Colors"),
		wxPoint(5, 5), wxSize(480, 280));

	tc = new wxTextCtrl(panel, wxID_ANY, wxT(""),
		wxPoint(20, 20));

	tc1 = new wxTextCtrl(panel, wxID_ANY, wxT(""),
		wxPoint(20, 50));

	tc2 = new wxTextCtrl(panel, wxID_ANY, wxT(""),
		wxPoint(20, 80));

	tc3 = new wxTextCtrl(panel, wxID_ANY, wxT(""),
		wxPoint(20, 110));

	okButton = new wxButton(this, wxID_ANY, wxT("Ok"),
		wxDefaultPosition, wxSize(150, 30));

	okButton->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
		Destroy();
		});

	hbox->Add(okButton, 1);

	vbox->Add(panel, 1);
	vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

	SetSizer(vbox);

	Centre();
	ShowModal();
	Destroy();
}

Frame::Frame() : wxFrame(nullptr, wxID_ANY, "Discord Custom Rich Presence Client") {

	panel = new wxPanel(this);
	clientID = new wxButton(panel, wxID_ANY, "Input Client ID", { 10, 10 }, { 100, 20 });
	input = new wxButton(panel, wxID_ANY, "Update Presencee", { 10, 80 });
	clientIDmsg = new wxStaticText(panel, wxID_ANY, "Currently Loaded Client ID: ", { 10, 40 });
	clientIDtxt = new wxStaticText(panel, wxID_ANY, values.clientID, { 160, 40 });

	clientID->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
		wxTextEntryDialog textEntryDialog(this, "Message text", "Caption text");

		if (textEntryDialog.ShowModal() == wxID_OK) {
			clientIDtxt->SetLabel(textEntryDialog.GetValue().ToStdString());
		}

		values.clientID = textEntryDialog.GetValue().mb_str(wxConvUTF8);

		WriteFile();

		InitDiscord(values.clientID);

		});

	input->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
		Dialouge* dialogue = new Dialouge(wxT("CustomDialog"));
		dialogue->Show(true);
		UpdatePresence(values);
		});
}
