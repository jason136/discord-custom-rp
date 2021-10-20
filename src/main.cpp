#include "main.h"

extern discord_fields values;

bool DiscordRP::OnInit() {

	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);

	values = GetFile();
	frame = new Frame();
	//taskBarIcon->SetIcon();

	if (values.clientID != "") {
		InitDiscord(values.clientID);
		UpdatePresence(values);
	}
	
	frame->Show(true);
	return true;
}

void DiscordRP::Hide() {
	frame->Show(false);
}

void DiscordRP::Show() {
	frame->Show(true);
}

wxIMPLEMENT_APP(DiscordRP);