#include "App.h"

using namespace NESStudio;

Studio * studio = new Studio();

void Frame::OnPlay(wxCommandEvent & WXUNUSED(event))
{
	studio->Play();
}

BEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_MENU(ID_Quit, Frame::OnQuit)
    EVT_MENU(ID_About, Frame::OnAbout)
    EVT_MENU(ID_Save, Frame::OnSave)
    EVT_MENU(ID_Load, Frame::OnLoad)
    EVT_BUTTON(BUTTON_Play, Frame::OnPlay)
END_EVENT_TABLE()


bool App::OnInit()
{
	Frame * frame = new Frame(_("NES Studio"), wxPoint(50, 50), wxSize(800, 600));

	frame->Show(true);
	SetTopWindow(frame);

	//studio = new Studio();

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

	play = new wxButton(this, BUTTON_Play, _("Play"), wxPoint(20, 20));

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

