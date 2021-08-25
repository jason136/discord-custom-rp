#include "main.h"

extern discord_fields values;

bool DiscordRP::OnInit() {

	wxInitAllImageHandlers();
	values = GetFile();
	frame = new Frame();

	if (values.clientID != "") 
		InitDiscord(values.clientID);
	if (values.details != "") 
		UpdatePresence(values);
		
	frame->Show(true);
	return true;
}

wxIMPLEMENT_APP(DiscordRP);