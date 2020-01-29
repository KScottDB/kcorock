#include "gui/gladeFile.h"
#include <wx/wx.h>
#include "main.h"
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <SimpleIni.h>
#include <boost/any.hpp>

using namespace std;

void _log(string stuff, string who) {
    clog << who << ": " << stuff << "\n";
}
//  ^^ Might want to make this do nothing before a release...

void KcorocK_Frame::LoadTheme(string filename) {
    _log("Loading theme " + filename, "KcorocK_Frame-LoadTheme");

    CSimpleIniA ini;

    _log("INI load", "KcorocK_Frame-LoadTheme");
    // LOAD INI
    ini.SetUnicode();
    ini.LoadFile(filename.c_str());

    // [WINDOW]
    _log("Loading logo", "KcorocK_Frame-LoadTheme");
    bitmap_Logo->SetBitmap(
        wxBitmap(
            ini.GetValue("window","logo","assets/logo.png"),
            wxBITMAP_TYPE_ANY
        )
    );
    _log("Loading icon", "KcorocK_Frame-LoadTheme");
    wxIcon tempIcon; tempIcon.LoadFile(
        ini.GetValue("window","icon","assets/icon.ico"),
        wxBITMAP_TYPE_ANY
    );
    SetIcon(tempIcon);
    _log("Setting size", "KcorocK_Frame-LoadTheme");
    SetSize(
        wxSize(
            stoi( ini.GetValue("window","sizew","300") ),
            stoi( ini.GetValue("window","sizeh","450") )
        )
    );

    // [LOCALE]
    _log("Loading locale", "KcorocK_Frame-LoadTheme");
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

    _log("Successfully loaded.", "KcorocK_Frame-LoadTheme");
}

void KcorocK_Frame::Show_About(wxCommandEvent &event) {
    About_Window* AboutDialog = new About_Window(this, wxID_ANY, wxEmptyString);
    AboutDialog->Show();
    event.Skip();

    _log("menu/about -> Show_About", "KcorocK_Frame");
}

void KcorocK_Frame::Bind_Events() {
    Bind(wxEVT_MENU, &KcorocK_Frame::Show_About, this, about->GetId());

    _log("Events bound.", "KcorocK_Frame");
}

void About_Window::Exit_Dialog(wxCommandEvent &event) {
    Close();
    event.Skip();

    _log("button_OK -> Exit_Dialog", "About_Window");
}

void About_Window::Bind_Events() {
    button_OK->Bind(
        wxEVT_COMMAND_BUTTON_CLICKED,
        wxCommandEventHandler( About_Window::Exit_Dialog ),
        this
    );

    _log("Events bound.", "About_Window");
}

bool KcorocK::OnInit() {
    wxInitAllImageHandlers();

    KcorocK_Frame* frame_Main = new KcorocK_Frame(NULL, wxID_ANY, wxEmptyString);
    SetTopWindow(frame_Main);
    frame_Main->Show();
    frame_Main->LoadTheme("assets/default.ini");

    return true;
}