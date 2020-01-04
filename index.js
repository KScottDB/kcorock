const {
    QMainWindow,
    QWidget,
    QLabel,
    QIcon,
    QPixmap,
    FlexLayout
} = require("@nodegui/nodegui");

const {
    readFileSync
} = require("fs");

// Logo
const logoLabel = new QLabel();
logoLabel.setObjectName("logoLabel");
logoLabel.setText("peepee");

// FormMain
const mainForm = new QWidget();
mainForm.setLayout(new FlexLayout());
mainForm.setGeometry(0, 0, 300, 500);

mainForm.layout.addWidget(logoLabel);

// Protect my precious child from the filthy garbage man
global.win = mainForm;

global.theme = {};

function ThemeApply() {
    mainForm.setWindowTitle( global.theme.window_title );
    mainForm.setWindowIcon( new QIcon(global.theme.icon) );

    global.logo = new QPixmap( global.theme.logo );
    logoLabel.setGeometry(
        0, 0,
        global.logo.width(), global.logo.height()
    );
    logoLabel.setPixmap( global.logo );
    mainForm.setStyleSheet( global.theme.style );
}

function ThemeLoad(filename) {
    global.theme = JSON.parse( readFileSync(filename) );
    ThemeApply();
}

// Apply themes
ThemeLoad("assets/theme.json");

mainForm.show();
