#include "main.h"

extern discord_fields values;

bool DiscordRP::OnInit() {
	values = GetFile();
	frame = new Frame();
	frame->Show(true);
	return true;
}

wxIMPLEMENT_APP(DiscordRP);