#include <string>
#include <fstream>

#include "main.h"
#include "gui.h"
#include "discord.h"
#include "file.h"

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

extern discord_fields values;

Dialouge::Dialouge(const wxString& title) : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(360, 420)) {
	panel = new wxPanel(this, -1);

	vbox = new wxBoxSizer(wxVERTICAL);
	hbox = new wxBoxSizer(wxHORIZONTAL);

	box = new wxStaticBox(panel, wxID_ANY, wxT(""), wxPoint(5, 5), wxSize(325, 320));

	stateCtrl = new wxTextCtrl(panel, wxID_ANY, values.state, wxPoint(125, 20), wxSize(200, 24));
	stateText = new wxStaticText(panel, wxID_ANY, "State: ", wxPoint(10, 20));

	detailsCtrl = new wxTextCtrl(panel, wxID_ANY, values.details, wxPoint(125, 50), wxSize(200, 24));
	detailsText = new wxStaticText(panel, wxID_ANY, "Details: ", wxPoint(10, 50));

	startTSCtrl = new wxTextCtrl(panel, wxID_ANY, std::to_string(values.startTimestamp), wxPoint(125, 80), wxSize(200, 24));
	startTSText = new wxStaticText(panel, wxID_ANY, "Start Timestamp: ", wxPoint(10, 80));

	endTSCtrl = new wxTextCtrl(panel, wxID_ANY, std::to_string(values.endTimestamp), wxPoint(125, 110), wxSize(200, 24));
	endTSText = new wxStaticText(panel, wxID_ANY, "End Timestamp: ", wxPoint(10, 110));
	
	largeKeyCtrl = new wxTextCtrl(panel, wxID_ANY, values.largeImageKey, wxPoint(125, 140), wxSize(200, 24));
	largeKeyText = new wxStaticText(panel, wxID_ANY, "Large Image Key: ", wxPoint(10, 140));
	
	largeTextCtrl = new wxTextCtrl(panel, wxID_ANY, values.largeImageText, wxPoint(125, 170), wxSize(200, 24));
	largeTextText = new wxStaticText(panel, wxID_ANY, "Large Image Text: ", wxPoint(10, 170));
	
	smallKeyCtrl = new wxTextCtrl(panel, wxID_ANY, values.smallImageKey, wxPoint(125, 200), wxSize(200, 24));
	smallKeyText = new wxStaticText(panel, wxID_ANY, "Small Image Key: ", wxPoint(10, 200));
	
	smallTextCtrl = new wxTextCtrl(panel, wxID_ANY, values.smallImageText, wxPoint(125, 230), wxSize(200, 24));
	smallTextText = new wxStaticText(panel, wxID_ANY, "Small Image Text: ", wxPoint(10, 230));
	
	partySizeCtrl = new wxTextCtrl(panel, wxID_ANY, std::to_string(values.partySize), wxPoint(125, 260), wxSize(200, 24));
	partySizeText = new wxStaticText(panel, wxID_ANY, "Party Size: ", wxPoint(10, 260));
	
	partyMaxCtrl = new wxTextCtrl(panel, wxID_ANY, std::to_string(values.partyMax), wxPoint(125, 290), wxSize(200, 24));
	partyMaxText = new wxStaticText(panel, wxID_ANY, "Party Max: ", wxPoint(10, 290));

	okButton = new wxButton(this, wxID_ANY, wxT("Ok"), wxDefaultPosition, wxSize(150, 30));

	stateCtrl->SetMaxLength(128);
	detailsCtrl->SetMaxLength(128);
	startTSCtrl->SetMaxLength(19);
	endTSCtrl->SetMaxLength(19);
	largeKeyCtrl->SetMaxLength(32);
	largeTextCtrl->SetMaxLength(128);
	smallKeyCtrl->SetMaxLength(32);
	smallTextCtrl->SetMaxLength(10);
	partySizeCtrl->SetMaxLength(10);

	okButton->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
		values.state = stateCtrl->GetValue().mb_str(wxConvUTF8);
		values.details = detailsCtrl->GetValue().mb_str(wxConvUTF8);
		values.startTimestamp = strtoll(startTSCtrl->GetValue().mb_str(wxConvUTF8), NULL, 10);
		values.endTimestamp = strtoll(endTSCtrl->GetValue().mb_str(wxConvUTF8), NULL, 10);
		values.largeImageKey = largeKeyCtrl->GetValue().mb_str(wxConvUTF8);
		values.largeImageText = largeTextCtrl->GetValue().mb_str(wxConvUTF8);
		values.smallImageKey = smallKeyCtrl->GetValue().mb_str(wxConvUTF8);
		values.smallImageText = smallTextCtrl->GetValue().mb_str(wxConvUTF8);
		values.partySize = wxAtoi(partySizeCtrl->GetValue());
		values.partyMax = wxAtoi(partyMaxCtrl->GetValue());
		WriteFile();
		UpdatePresence(values);
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
	clientID = new wxButton(panel, wxID_ANY, "Input Client ID", wxPoint(10, 10), wxSize(100, 20));
	input = new wxButton(panel, wxID_ANY, "Update Presencee", wxPoint(10, 80));
	clientIDmsg = new wxStaticText(panel, wxID_ANY, "Currently Loaded Client ID: ", wxPoint(10, 45));
	clientIDtxt = new wxStaticText(panel, wxID_ANY, values.clientID, wxPoint(160, 45));

	clientID->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
		wxTextEntryDialog textEntryDialog(this, "Message text", "Caption text", values.clientID);

		if (textEntryDialog.ShowModal() == wxID_OK) {
			clientIDtxt->SetLabel(textEntryDialog.GetValue().ToStdString());
		}

		values.clientID = textEntryDialog.GetValue().mb_str(wxConvUTF8);
		WriteFile();
		InitDiscord(values.clientID);
		});

	input->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
		Dialouge* dialogue = new Dialouge(wxT("Update Presence"));
		dialogue->Show(true);
		});
}
