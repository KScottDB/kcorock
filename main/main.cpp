#include "gui/gladeFile.h"
#include <wx/wx.h>
#include "main.h"
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <SimpleIni.h>

using namespace std;

void KcorocK_Frame::LoadTheme(string filename) {
    CSimpleIniA ini;

    // LOAD INI
    ini.SetUnicode();
    ini.LoadFile(filename.c_str());

    // [WINDOW]
    bitmap_Logo->SetBitmap(
        wxBitmap(
            ini.GetValue("window","logo","assets/logo.png"),
            wxBITMAP_TYPE_ANY
        )
    );
    wxIcon tempIcon; tempIcon.LoadFile(
        ini.GetValue("window","icon","assets/icon.ico"),
        wxBITMAP_TYPE_ANY
    );
    SetIcon(tempIcon);
    SetSize(
        wxSize(
            stoi( ini.GetValue("window","sizew","300") ),
            stoi( ini.GetValue("window","sizeh","450") )
        )
    );

    // [LOCALE]
    SetTitle(
        ini.GetValue("locale","windowTitle","WINDOWTITLE")
    );
    label_Open->SetLabel(
        ini.GetValue("locale","openLabel","OPENLABEL")
    );
    label_Save->SetLabel(
        ini.GetValue("locale","saveLabel","SAVELABEL")
    );
    button_Open->SetLabel(
        ini.GetValue("locale","openButton","OPENBUTTON")
    );
    button_Save->SetLabel(
        ini.GetValue("locale","saveButton","SAVEBUTTON")
    );
}

void KcorocK_Frame::Show_About(wxCommandEvent &event) {
    MyDialog* AboutDialog = new MyDialog(this, wxID_ANY, wxEmptyString);
    AboutDialog->Show();
    event.Skip();
}

void KcorocK_Frame::Bind_Events() {
    Bind(wxEVT_MENU, &KcorocK_Frame::Show_About, this, about->GetId());
}

// TODO: ABOUT "OK" BUTTON DOES NOT CLOSE THE WINDOW //

void About_Window::Exit_Dialog(wxCommandEvent &event) {
    event.Skip();
    Close();
}

void About_Window::Bind_Events() {
    Bind(wxEVT_BUTTON, &About_Window::Exit_Dialog, this, button_OK->GetId());
}

BEGIN_EVENT_TABLE(About_Window, MyDialog)
    EVT_BUTTON(wxID_ANY, About_Window::Exit_Dialog)
END_EVENT_TABLE();

///////////////////////////////////////////////////////

bool KcorocK::OnInit() {
    wxInitAllImageHandlers();

    KcorocK_Frame* frame_Main = new KcorocK_Frame(NULL, wxID_ANY, wxEmptyString);
    SetTopWindow(frame_Main);
    frame_Main->Show();
    frame_Main->LoadTheme("assets/default.ini");

    return true;
}