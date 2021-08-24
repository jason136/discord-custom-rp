#include "main.h"

extern discord_fields values;

bool DiscordRP::OnInit() {

	frame = new Frame();

	wxInitAllImageHandlers();
	values = GetFile();

	if (values.clientID != "") 
		InitDiscord(values.clientID);
	if (values.details != "") 
		UpdatePresence(values);
		
	frame->Show(true);
	return true;
}

wxIMPLEMENT_APP(DiscordRP);