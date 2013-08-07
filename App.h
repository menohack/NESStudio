#ifndef _APP_H
#define _APP_H

#include "wx/wx.h"

#include "Studio.h"

using namespace sf;

namespace NESStudio {

class Frame;

class App : public wxApp {
private:
	virtual bool OnInit();
};

class Frame : public wxFrame {
private:

public:

	Frame(const wxString & title, const wxPoint & pos,
	      const wxSize & size);

	void OnQuit(wxCommandEvent & event);
	void OnAbout(wxCommandEvent & event);
	void OnSave(wxCommandEvent & event);
	void OnLoad(wxCommandEvent & event);
	void OnPlayPulse1(wxCommandEvent & event);
	void OnPlayPulse2(wxCommandEvent & event);
	void OnPlayTriangle(wxCommandEvent & event);

	DECLARE_EVENT_TABLE()
};

enum {
	ID_Quit = 1,
	ID_About,
	ID_Save,
	ID_Load,
	BUTTON_PlayPulse1,
	BUTTON_PlayPulse2,
	BUTTON_PlayTriangle,
};
}
#endif
