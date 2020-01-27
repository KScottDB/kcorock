#include <wx/wx.h>
#include "gui/gladeFile.h"

class KcorocK_Frame: public MyFrame {
public:
    KcorocK_Frame(
        wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_FRAME_STYLE
    ):MyFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE) {};
    void LoadTheme(std::string filename);
};

class KcorocK: public wxApp {
public:
    bool OnInit();
};

IMPLEMENT_APP(KcorocK)