#include "App.h"

using namespace NESStudio;

Studio * studio = new Studio();

void Frame::OnPlayPulse1(wxCommandEvent & WXUNUSED(event))
{
	studio->PlayPulse1();
}

void Frame::OnPlayPulse2(wxCommandEvent & WXUNUSED(event))
{
	studio->PlayPulse2();
}

void Frame::OnPlayTriangle(wxCommandEvent & WXUNUSED(event))
{
	studio->PlayTriangle();
}

BEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_MENU(ID_Quit, Frame::OnQuit)
    EVT_MENU(ID_About, Frame::OnAbout)
    EVT_MENU(ID_Save, Frame::OnSave)
    EVT_MENU(ID_Load, Frame::OnLoad)
    EVT_BUTTON(BUTTON_PlayPulse1, Frame::OnPlayPulse1)
    EVT_BUTTON(BUTTON_PlayPulse2, Frame::OnPlayPulse2)
    EVT_BUTTON(BUTTON_PlayTriangle, Frame::OnPlayTriangle)
END_EVENT_TABLE()


bool App::OnInit()
{
	Frame * frame = new Frame(_("NES Studio"), wxPoint(50, 50), wxSize(800, 600));

	frame->Show(true);
	SetTopWindow(frame);

	return true;
}

Frame::Frame(const wxString & title, const wxPoint & pos, const wxSize & size):wxFrame(NULL, -1, title, pos,
	size)
{
	wxMenu *menuFile = new wxMenu;

	menuFile->Append(ID_About, _("&About..."));
	menuFile->AppendSeparator();
	menuFile->Append(ID_Save, _("&Save"));
	menuFile->Append(ID_Save, _("&Load"));
	menuFile->AppendSeparator();
	menuFile->Append(ID_Quit, _("E&xit"));

	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, _("&File"));

	wxPanel *panel = new wxPanel(this, wxID_ANY);

	wxBoxSizer * buttons = new wxBoxSizer( wxHORIZONTAL );
	buttons->Add(new wxButton(this, BUTTON_PlayPulse1, _("Pulse 1")), 0, wxALIGN_CENTER);
	buttons->Add(new wxButton(this, BUTTON_PlayPulse2, _("Pulse 2")), 0, wxALIGN_CENTER);
	buttons->Add(new wxButton(this, BUTTON_PlayTriangle, _("Triangle")), 0, wxALIGN_CENTER);
	SetSizer(buttons);


	SetMenuBar(menuBar);
	SetIcon(wxIcon(_("icon.xpm")));

	CreateStatusBar();
	SetStatusText(_("Welcome to NES Studio!"));
}

void Frame::OnQuit(wxCommandEvent & WXUNUSED(event))
{
	Close(TRUE);
}

void Frame::OnAbout(wxCommandEvent & WXUNUSED(event))
{
	wxMessageBox(_("NES Studio copyright 2013 James Doverspike"),
		     _("About NES Studio"), wxOK | wxICON_INFORMATION, this);
}

void Frame::OnSave(wxCommandEvent & WXUNUSED(event))
{
	SetStatusText(_("Saved"));
}

void Frame::OnLoad(wxCommandEvent & WXUNUSED(event))
{
	SetStatusText(_("Loaded"));
}

