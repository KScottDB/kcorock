const {
    QMainWindow,
    QLabel
} = require("@nodegui/nodegui");

const {
    readFileSync
} = require("fs");

const FormMain = new QMainWindow();
FormMain.setGeometry(0, 0, 300, 500);
FormMain.center();

// Protect my precious child from the filthy garbage man
global.win = FormMain;

global.theme = {};

function ThemeApply() {
    FormMain.setWindowTitle(global.theme.window_title);
}

function ThemeLoad(filename) {
    global.theme = JSON.parse( readFileSync(filename) );
    ThemeApply();
}

// Apply themes
ThemeLoad("assets/theme.json");

FormMain.show();
