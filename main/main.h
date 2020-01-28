#include <wx/wx.h>
#include "gui/gladeFile.h"

class KcorocK_Frame: public MyFrame {
public:
    KcorocK_Frame(
        wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_FRAME_STYLE
    ):MyFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE) {
        Bind_Events();
    };
    void LoadTheme(std::string filename);
    void Show_About(wxCommandEvent &event);
    void Bind_Events();
};

class About_Window: public MyDialog {
public:
    About_Window(
        wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_DIALOG_STYLE
    ):MyDialog(parent, id, title, pos, size, wxDEFAULT_DIALOG_STYLE) { Bind_Events(); };
    void Bind_Events();
    void Exit_Dialog(wxCommandEvent &event);
protected:
    DECLARE_EVENT_TABLE();
};

class KcorocK: public wxApp {
public:
    bool OnInit();
};

IMPLEMENT_APP(KcorocK)