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
            stoi( ini.GetValue("window","sizew","assets/icon.ico") ),
            stoi( ini.GetValue("window","sizeh","assets/icon.ico") )
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

bool KcorocK::OnInit() {
    wxInitAllImageHandlers();
    KcorocK_Frame* frame_Main = new KcorocK_Frame(NULL, wxID_ANY, wxEmptyString);
    SetTopWindow(frame_Main);
    frame_Main->Show();
    frame_Main->LoadTheme("assets/default.ini");

    return true;
}