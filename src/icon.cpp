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

void TaskbarIcon::OnLeftDoubleClick(wxTaskBarIconEvent& event) {
	std::cout << "double click";
	//Frame().Show();
}

wxMenu* TaskbarIcon::CreatePopupMenu() {
	wxMenu* popup = new wxMenu;

	popup->AppendSeparator();
	popup->Append(1, wxT("E&xit"));

	std::cout <<"create popup";
	return popup;
}

void TaskbarIcon::Minimize() {
	taskBarIcon->SetIcon(icon);
}

void TaskbarIcon::Maximize() {
	taskBarIcon->RemoveIcon();
}