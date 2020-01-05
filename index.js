const {
    QMainWindow,
    QWidget,
    QLabel,
    QIcon,
    QPushButton,
    QPixmap,
    FlexLayout
} = require("@nodegui/nodegui");

const {
    readFileSync
} = require("fs");

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

    openButton.setText( global.theme.strings.openButton );
    openLabel. setText( global.theme.strings.openLabel  );

    mainForm.setStyleSheet( global.theme.style );
}

function ThemeLoad(filename) {
    global.theme = JSON.parse( readFileSync(filename) );
    global.theme.style = readFileSync(global.theme.style);
    ThemeApply();
}

/////////////// DEFINE MAINWINDOW ///////////////

// Logo
const logoLabel = new QLabel();
logoLabel.setObjectName("logoLabel"); // #logoLabel {}
logoLabel.setText("");

// Open Source Button
const openButton = new QPushButton();
openButton.setObjectName("openButton");

// Open Source Label
const openLabel = new QLabel();
openLabel.setObjectName("openLabel");

// FormMain
const mainForm = new QWidget();
mainForm.setObjectName("mainForm"); // #mainForm {}
mainForm.setLayout(new FlexLayout());
mainForm.setFixedSize(300, 500);

mainForm.layout.addWidget(logoLabel);

mainForm.layout.addWidget(openLabel);
mainForm.layout.addWidget(openButton);

// Protect my precious child from the filthy garbage man
global.win = mainForm;

///////////////                   ///////////////

// Apply themes
ThemeLoad("assets/theme.json");

mainForm.show();
