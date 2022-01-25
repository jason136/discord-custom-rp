#include "main.h"
#include "discord.h"
#include "file.h"
extern discord_fields values;

static Window* window;
static TaskbarIcon* trayIcon;

bool DiscordRP::OnInit() {

	//AllocConsole();
	//freopen("CONOUT$", "w", stdout);
	//freopen("CONOUT$", "w", stderr);
	
	values = GetFile();
	window = new Window();

	if (values.clientID != "") {
		InitDiscord(values.clientID);
		UpdatePresence(values);
	}

	window->Show(true);
	return true;
}

void DiscordRP::Show() {
	window->Show(true);
}

wxIMPLEMENT_APP(DiscordRP);

Dialog::Dialog(const wxString& title) : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(352, 420)) {
	panel = new wxPanel(this, -1);

	vbox = new wxBoxSizer(wxVERTICAL);
	hbox = new wxBoxSizer(wxHORIZONTAL);

	box = new wxStaticBox(panel, wxID_ANY, wxT(""), wxPoint(5, 5), wxSize(326, 320));

	detailsCtrl = new wxTextCtrl(panel, wxID_ANY, values.details, wxPoint(125, 20), wxSize(200, 24));
	detailsText = new wxStaticText(panel, wxID_ANY, "Details: ", wxPoint(10, 20));

	stateCtrl = new wxTextCtrl(panel, wxID_ANY, values.state, wxPoint(125, 50), wxSize(200, 24));
	stateText = new wxStaticText(panel, wxID_ANY, "State: ", wxPoint(10, 50));

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
	closeButton = new wxButton(this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxSize(150, 30));

	stateCtrl->SetMaxLength(128);
	detailsCtrl->SetMaxLength(128);
	startTSCtrl->SetMaxLength(19);
	endTSCtrl->SetMaxLength(19);
	largeKeyCtrl->SetMaxLength(32);
	largeTextCtrl->SetMaxLength(128);
	smallKeyCtrl->SetMaxLength(32);
	smallTextCtrl->SetMaxLength(128);
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

	closeButton->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
		Destroy();
		});

	hbox->Add(okButton, 1);
	hbox->Add(closeButton, 1, wxLEFT, 5);
	vbox->Add(panel, 1);
	vbox->Add(hbox, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

	SetSizer(vbox);

	Centre();
	ShowModal();
	Destroy();
}

wxBEGIN_EVENT_TABLE(Window, wxDialog)
EVT_BUTTON(wxID_ABOUT, Window::GetClientID)
EVT_BUTTON(wxID_OK, Window::GetInput)
EVT_BUTTON(wxID_EXIT, Window::Minimize)
EVT_CLOSE(Window::OnCloseWindow)
wxEND_EVENT_TABLE()

Window::Window() : wxDialog(NULL, wxID_ANY, "Discord Custom Rich Presence Client") {
	panel = new wxPanel(this);
	clientID = new wxButton(panel, wxID_ABOUT, "Input Client ID", wxPoint(10, 10), wxSize(120, 20));
	input = new wxButton(panel, wxID_OK, "Update Presence", wxPoint(10, 60), wxSize(120, 20));
	taskbar = new wxButton(panel, wxID_EXIT, "Minimize to Tray", wxPoint(10, 100), wxSize(120, 20));
	clientIDmsg = new wxStaticText(panel, wxID_ANY, "Currently Loaded Client ID: ", wxPoint(10, 37));
	clientIDtxt = new wxStaticText(panel, wxID_ANY, values.clientID, wxPoint(160, 38));

}

void Window::GetClientID(wxCommandEvent& WXUNUSED(event)) {
	wxTextEntryDialog textEntryWindow(this, "Discord Application Client ID:", "Input Client ID", values.clientID);

	if (textEntryWindow.ShowModal() == wxID_OK) {
		clientIDtxt->SetLabel(textEntryWindow.GetValue().ToStdString());
	}

	values.clientID = textEntryWindow.GetValue().mb_str(wxConvUTF8);
	WriteFile();
	InitDiscord(values.clientID);
	UpdatePresence(values);
}

void Window::GetInput(wxCommandEvent& WXUNUSED(event)) {
	Dialog* Window = new Dialog(wxT("Update Presence"));
	Window->Show(true);
}

void Window::Minimize(wxCommandEvent& WXUNUSED(event)) {
	wxIcon icon = wxICON(IDI_ICON1);
	trayIcon = new TaskbarIcon();
	if (!trayIcon->SetIcon(icon, "Discord Custom Rich Presence Client")) {
		std::cout << "icon failed";
		wxLogError("Could not set icon.");
	}
	Show(false);
	std::cout << "hide ";
}

Window::~Window() {
	Discord_Shutdown();
}

void Window::OnCloseWindow(wxCloseEvent& WXUNUSED(event)) {
	Show(false);
	trayIcon->Destroy();
	Destroy();
	exit(0);
}

wxBEGIN_EVENT_TABLE(TaskbarIcon, wxTaskBarIcon)
EVT_TASKBAR_LEFT_DCLICK(TaskbarIcon::OnLeftDoubleClick)
wxEND_EVENT_TABLE()

void TaskbarIcon::OnLeftDoubleClick(wxTaskBarIconEvent&) {
	std::cout << "double click";
	window->Show(true);
	trayIcon->RemoveIcon();
}