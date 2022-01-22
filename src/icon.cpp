#include "main.h"
#include "icon.h"

//const int tux_png_size = sizeof(tux_png);
//wxMemoryInputStream pngStream(tux_png, tux_png_size);
//
//wxImage tux;
//tux.LoadFile(pngStream, wxBITMAP_TYPE_PNG);
//
//wxIcon icon;
//icon.CopyFromBitmap(tux);

TaskbarIcon::TaskbarIcon() : wxTaskBarIcon() {
	icon = wxIcon();
	taskBarIcon = new wxTaskBarIcon();



	/*const int tux_png_size = sizeof(tux_png);
	wxMemoryInputStream pngStream(tux_png, tux_png_size);
	tux.LoadFile(pngStream, wxBITMAP_TYPE_PNG);
	wxIcon icon;
	icon.CopyFromBitmap(tux);*/

	
}

enum
{
	PU_RESTORE = 10001,
	PU_NEW_ICON,
	PU_EXIT,
	PU_CHECKMARK,
	PU_SUB1,
	PU_SUB2,
	PU_SUBMAIN
};

wxBEGIN_EVENT_TABLE(TaskbarIcon, wxTaskBarIcon)
EVT_MENU(PU_RESTORE, TaskbarIcon::OnMenuRestore)
EVT_MENU(PU_EXIT, TaskbarIcon::OnMenuExit)
EVT_MENU(PU_NEW_ICON, TaskbarIcon::OnMenuSetNewIcon)
EVT_MENU(PU_CHECKMARK, TaskbarIcon::OnMenuCheckmark)
EVT_UPDATE_UI(PU_CHECKMARK, TaskbarIcon::OnMenuUICheckmark)
EVT_TASKBAR_LEFT_DCLICK(TaskbarIcon::OnLeftDoubleClick)
EVT_MENU(PU_SUB1, TaskbarIcon::OnMenuSub)
EVT_MENU(PU_SUB2, TaskbarIcon::OnMenuSub)
wxEND_EVENT_TABLE()

void TaskbarIcon::OnMenuRestore(wxCommandEvent&)
{
	DiscordRP().Show();
}

void TaskbarIcon::OnMenuExit(wxCommandEvent&)
{
	DiscordRP().Show();
}

static bool check = true;

void TaskbarIcon::OnMenuCheckmark(wxCommandEvent&)
{
	check = !check;
}

void TaskbarIcon::OnMenuUICheckmark(wxUpdateUIEvent& event)
{
	event.Check(check);
}

void TaskbarIcon::OnMenuSetNewIcon(wxCommandEvent&)
{
	wxIcon icon(smile_xpm);

	if (!SetIcon(icon, "wxTaskBarIcon Sample - a different icon"))
		wxMessageBox("Could not set new icon.");
}

void TaskbarIcon::OnMenuSub(wxCommandEvent&)
{
	wxMessageBox("You clicked on a submenu!");
}

void TaskbarIcon::OnLeftDoubleClick(wxTaskBarIconEvent&) {
	std::cout << "double click";
	DiscordRP().Show();
	//Frame().Show();
}

wxMenu* TaskbarIcon::CreatePopupMenu()
{
	wxMenu* menu = new wxMenu;
	menu->Append(PU_RESTORE, "&Restore main window");
	menu->AppendSeparator();
	menu->Append(PU_NEW_ICON, "&Set New Icon");
	menu->AppendSeparator();
	menu->AppendCheckItem(PU_CHECKMARK, "Test &check mark");
	menu->AppendSeparator();
	wxMenu* submenu = new wxMenu;
	submenu->Append(PU_SUB1, "One submenu");
	submenu->AppendSeparator();
	submenu->Append(PU_SUB2, "Another submenu");
	menu->Append(PU_SUBMAIN, "Submenu", submenu);
	{
		menu->AppendSeparator();
		menu->Append(PU_EXIT, "E&xit");
	}
	return menu;
}

void TaskbarIcon::Minimize() {
	taskBarIcon->SetIcon(wxICON(sample),
		"wxTaskBarIcon Sample\n"
		"With a very, very, very, very\n"
		"long tooltip whose length is\n"
		"greater than 64 characters.");
}

void TaskbarIcon::Maximize() {
	taskBarIcon->RemoveIcon();
}