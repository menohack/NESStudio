#include "wx/wx.h"
#include <SFML/Audio.hpp>

using namespace sf;

namespace NESStudio {

class Frame;

class Studio:public wxApp {
private:
	Frame * frame;
	SoundBuffer buffer;
	Int16 *samples;

	virtual bool OnInit();

public:
	void Play(wxCommandEvent & event);
};

class Frame:public wxFrame {
private:
	wxButton * play;

public:

	Frame(const wxString & title, const wxPoint & pos,
	      const wxSize & size);

	void OnQuit(wxCommandEvent & event);
	void OnAbout(wxCommandEvent & event);
	void OnSave(wxCommandEvent & event);
	void OnLoad(wxCommandEvent & event);

	 DECLARE_EVENT_TABLE()
};

enum {
	ID_Quit = 1,
	ID_About,
	ID_Save,
	ID_Load,
	BUTTON_Play,
};
}
