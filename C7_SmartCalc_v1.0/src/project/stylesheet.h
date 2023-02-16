#ifndef SRC_PROJECT_STYLESHEET_H_
#define SRC_PROJECT_STYLESHEET_H_

#include <QString>

static QString StyleSheetBackSpace = "QPushButton { "  // peach
"margin:5px;"
"color: black; "
"background-color: #ed9d64; "
"border: none; "
"font: 17pt 'Microsoft YaHei UI Light'; "
"outline: none; "
"} "
"QPushButton:hover { "
"background-color: #6495ED; "
"border-style: solid; "
"border-width: 3px; "
"border-color: #808080; "
"} "
"QPushButton:pressed { "
"background-color: #4682B4; "
"border-style: solid; "
"border-width: 3px; "
"border-color: #808080; "
"}";

static QString StyleSheetCalcsButton = "QPushButton {"  // plum
"margin: 5px;"
"font: 12pt 'Microsoft YaHei UI Light'; "
"padding: 0px 0px 0px 5px;"
"color: black;"
"border-radius: 5px;"
"background-color: #6B3D68;"
"}"
"QPushButton:hover { "
"background-color: #6A5ACD; "
"border-style: solid; "
"border-width: 3px; "
"border-color: #696969; "
"} "
"QPushButton:pressed { "
"background-color: #483D8B; "
"border-style: solid; "
"border-width: 3px; "
"border-color: #696969; "
"}";

static QString StyleSheetGraphButton = "QPushButton {"  // feathergreen
"font-size: 15px;"
"margin: 5px;"
"color: black;"
"background-color: #A3D0B6;"
"border: 0;"
"border-radius: 5px;"
"}"
"QPushButton:hover { "
"background-color: #808000; "
"border-style: solid; "
"border-width: 3px; "
"border-color: #808080; "
"} "
"QPushButton:pressed { "
"background-color: #556B2F; "
"border-style: solid; "
"border-width: 3px; "
"border-color: #808080; "
"}";

static QString StyleSheetLine = "QLineEdit {"  // brown
"background-color:#fa8e23;"
"font-size:30px;"
"padding:12px;"
"border:none;"
"outline:0;"
"color:#FAEBD7;"
"font-weight:300;"
"}";

static QString StyleSheetNumbers = "QPushButton {"  // peach
"margin:5px;"
"background-color:#ffab6b;"
"color:#696969;"
"width:60px;"
"height:60px;"
"font-size:20px;"
"border:0;"
"border-radius:5px;"
"} "
"QPushButton:hover {"
"background:#EEE8AA;"
"color:dimgray;"
"}";

static QString StyleSheetSigns = "QPushButton {"  // pale Turquoise
"margin:5px;"
"background-color:#FFDEAD;"
"color:#696969;"
"width:60px;"
"height:60px;"
"font-size:20px;"
"border:0;"
"border-radius:5px;"
"} "
"QPushButton:hover { "
"background-color: #D2B48C; "
"border-style: solid; "
"border-width: 3px; "
"border-color: #808080; "
"} "
"QPushButton:pressed { "
"background-color: #DEB887; "
"border-style: solid; "
"border-width: 3px; "
"border-color: #808080; "
"}";

static QString StyleSheetSpecSigns = "QPushButton {"  // light cyan
"margin:5px;"
"background-color:#ffab6b;"
"color:#696969;"
"width:60px;"
"height:60px;"
"font-size:20px;"
"border:0;"
"border-radius:5px;"
"} "
"QPushButton:hover {"
"background:#EEE8AA;"
"color:dimgray;"
"}";

static QString StyleSheetSpecRoot = "QPushButton {"  // ?
"max-width: 77px; "
"color: black; "
"background-color: #E0FFFF; "
"border: none; "
"font: 16pt 'Microsoft YaHei UI Light'; "
"outline: none; "
"} "
"QPushButton:hover { "
"background-color: #D8D8D8; "
"border-style: solid; "
"border-width: 3px; "
"border-color: #E6E6E6; "
"} "
"QPushButton:pressed { "
"background-color: #A4A4A4; "
"border-style: solid; "
"border-width: 3px; "
"border-color: #E6E6E6; "
"}";

#endif  // SRC_PROJECT_STYLESHEET_H_
