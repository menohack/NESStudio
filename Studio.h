#include "wx/wx.h" 

namespace NESStudio
{

class Studio: public wxApp
{
    virtual bool OnInit();
};

class Frame: public wxFrame
{
public:

    Frame(const wxString& title, const wxPoint& pos, const wxSize& size);

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnLoad(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
};

enum
{
    ID_Quit = 1,
    ID_About,
    ID_Save,
    ID_Load,
};

BEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_MENU(ID_Quit,  Frame::OnQuit)
    EVT_MENU(ID_About, Frame::OnAbout)
    EVT_MENU(ID_Save, Frame::OnSave)
    EVT_MENU(ID_Load, Frame::OnLoad)
END_EVENT_TABLE()



bool Studio::OnInit()
{
    Frame *frame = new Frame( _("NESStudio"), wxPoint(50, 50),
                                  wxSize(800,600) );
    frame->Show(true);
    SetTopWindow(frame);
    return true;
} 

Frame::Frame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame( NULL, -1, title, pos, size )
{
    wxMenu *menuFile = new wxMenu;

    menuFile->Append( ID_About, _("&About...") );
    menuFile->AppendSeparator();
    menuFile->Append( ID_Save, _("&Save"));
    menuFile->Append( ID_Save, _("&Load"));
    menuFile->AppendSeparator();
    menuFile->Append( ID_Quit, _("E&xit") );

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, _("&File") );

    SetMenuBar( menuBar );

    CreateStatusBar();
    SetStatusText( _("Welcome to wxWidgets!") );
}

void Frame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(TRUE);
}

void Frame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox( _("NESStudio copyright 2013 James Doverspike"),
                  _("About NESStudio"),
                  wxOK | wxICON_INFORMATION, this);
}

void Frame::OnSave(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox( _("Saved"),
                  _("Save"),
                  wxOK | wxICON_INFORMATION, this);
}

void Frame::OnLoad(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox( _("Loaded"),
                  _("Load"),
                  wxOK | wxICON_INFORMATION, this);
}
}
