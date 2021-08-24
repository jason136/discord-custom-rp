#include <iostream>
#include <fstream>

#include "discord.h"
#include "file.h"
#include "gui.h"

#include "../include/discord_rpc.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

class DiscordRP : public wxApp {
public:
	Frame* frame;
private:
	bool OnInit() override;
};