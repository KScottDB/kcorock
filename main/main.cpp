#include "gui/gladeFile.h"
#include <wx/wx.h>
#include "main.h"

bool MyApp::OnInit()
{
    wxInitAllImageHandlers();
    MyFrame* frame_Main = new MyFrame(NULL, wxID_ANY, wxEmptyString);
    SetTopWindow(frame_Main);
    frame_Main->Show();
    

    return true;
}

