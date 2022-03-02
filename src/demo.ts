import { FlexLayout, QFont, QFontDatabase, QPushButton, QLabel, QWidget, QMainWindow, QSize, QApplication, QToolButton, ToolButtonPopupMode, QMenu, QVariant, QStylePixelMetric } from '@nodegui/nodegui';
import { StyleTweaker } from './index';
import * as path from 'path';
import { createFontIcon } from 'nodegui-plugin-font-icon';

// Load in our custom icon font
const extraicons = path.join(__dirname, "../resources/extraicons.ttf");
QFontDatabase.addApplicationFont(extraicons);

const win = new QMainWindow();
win.setWindowTitle('Style Tweaker Demo');

const centralWidget = new QWidget();
centralWidget.setObjectName('myroot');
const rootLayout = new FlexLayout();
centralWidget.setLayout(rootLayout);

const font = new QFont("extraicons", 10)

const label = new QLabel();
label.setText('Push buttons with icons');
rootLayout.addWidget(label);

const button = new QPushButton();
const icon = createFontIcon(font, "\uEA09");  // Pocketknife icon
button.setIcon(icon);
button.setText('Font Icon');
rootLayout.addWidget(button);

const menuButton = new QToolButton();
menuButton.setText("Popup menu");
menuButton.setPopupMode(ToolButtonPopupMode.InstantPopup);
const menu = new QMenu();
const action = menu.addAction("Pocketknife");
action.setData(new QVariant(""));
const menuIcon = createFontIcon(font, "\uEA09");  // Pocketknife icon
action.setIcon(menuIcon);
menuButton.setMenu(menu);

rootLayout.addWidget(menuButton);

const st = new StyleTweaker("Windows");
st.setPixelMetric(65 /* QStylePixelMetric.PM_SmallIconSize */, 64);
QApplication.setStyle(st);
win.setCentralWidget(centralWidget);

win.show();

(global as any).win = win;
