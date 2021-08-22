#include <iostream>
#include <fstream>

#include <windows.h>

#include "main.h"
#include "../include/discord_rpc.h"

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

bool g_ready = false;

void handleDiscordReady(const DiscordUser* request) {
	g_ready = true;
	char str[1024];
	sprintf_s(str, sizeof(str), "Displaying Presence for %s#%s\n", request->username, request->discriminator);
	OutputDebugStringA(str);
}

void handleDiscordError(int errorCode, const char* message) {
	char str[1024];
	sprintf_s(str, sizeof(str), "Discord error(% d: % s)\n", errorCode, message);
	OutputDebugStringA(str);
}

void handleDiscordDisconnected(int errorCode, const char* message) {

}

void handleDiscordJoinGame(const char* joinSecret) {

}

void handleDiscordSpectateGame(const char* spectateSecret) {

}

void handleDiscordJoinRequest(const DiscordUser* request) {

}

void InitDiscord(std::string clientID)
{
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	handlers.ready = handleDiscordReady;
	handlers.errored = handleDiscordError;
	handlers.disconnected = handleDiscordDisconnected;
	handlers.joinGame = handleDiscordJoinGame;
	handlers.spectateGame = handleDiscordSpectateGame;
	handlers.joinRequest = handleDiscordJoinRequest;

	// Discord_Initialize(const char* applicationId, DiscordEventHandlers * handlers, int autoRegister, const char* optionalSteamId);
	Discord_Initialize(clientID.c_str(), &handlers, 1, NULL);
}

//void UpdatePresence()
//{
//    char buffer[256];
//    DiscordRichPresence discordPresence;
//    memset(&discordPresence, 0, sizeof(discordPresence));
//    discordPresence.state = "In a Group";
//    sprintf_s(buffer, "Ranked | Mode:");
//    discordPresence.details = buffer;
//    discordPresence.endTimestamp = time(0) + 5 * 60;
//    discordPresence.largeImageKey = "canary-large";
//    discordPresence.smallImageKey = "ptb-small";
//    discordPresence.partyId = "123";
//    discordPresence.partySize = 1;
//    discordPresence.partyMax = 6;
//    discordPresence.matchSecret = "4b2fdce12f639de8bfa7e3591b71a0d679d7c93f";
//    discordPresence.spectateSecret = "e7eb30d2ee025ed05c71ea495f770b76454ee4e0";
//    discordPresence.instance = 1;
//    Discord_UpdatePresence(&discordPresence);
//}

static void UpdatePresence()
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = "Playing Solo";
	discordPresence.details = "Competitive";
	discordPresence.startTimestamp = 2432423;
	discordPresence.endTimestamp = 1507665886;
	discordPresence.largeImageKey = "hayasaka";
	discordPresence.largeImageText = "Numbani";
	discordPresence.smallImageText = "Rogue - Level 100";
	discordPresence.partyId = "ae488379-351d-4a4f-ad32-2b9b01c91657";
	discordPresence.partySize = 1;
	discordPresence.partyMax = 5;
	discordPresence.joinSecret = "MTI4NzM0OjFpMmhuZToxMjMxMjM= ";
	Discord_UpdatePresence(&discordPresence);
}

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

			std::string mystring = textEntryDialog.GetValue().ToStdString();

			//InitDiscord(textEntryDialog.GetValue().mb_str(wxConvUTF8));
			//InitDiscord(mystring);
			InitDiscord("875580955472068619");

			if (textEntryDialog.ShowModal() == wxID_OK) {
				label->SetLabel(typeid(mystring).name());

			}
			});

		input->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
			/*Dialouge* dialogue = new Dialouge(wxT("CustomDialog"));
			dialogue->Show(true);*/
			UpdatePresence();
			});
	}

private:
	wxPanel* panel = new wxPanel(this);
	wxButton* clientID = new wxButton(panel, wxID_ANY, "Input Client ID", { 10, 10 }, { 100, 20 });
	wxButton* input = new wxButton(panel, wxID_ANY, "Update Presencee", { 10, 80 });
	wxStaticText* label = new wxStaticText(panel, wxID_ANY, "", { 10, 50 });
};

class DiscordRP : public wxApp {
	bool OnInit() override {

		(new Frame())->Show();

		return true;
	}
};

wxIMPLEMENT_APP(DiscordRP);