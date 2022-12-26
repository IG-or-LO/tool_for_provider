#include "stylehelper.h"


QString stylehelper::getTabStyle()
{
    return "QWidget#login {"
            "background:none;"
           " border-image: url(:/resources/img/registr.jpg) 0 0 0 0 stretch;"
           "} "
           "QWidget#main {"
                      " border-image: url(:/resources/img/main.jpg) 0 0 0 0 stretch stretch;"
                      "} "
           "QWidget#uslugi {"
                      " border-image: url(:/resources/img/uslugi.jpg) 0 0 0 0 stretch stretch;"
                      "} "
            "QWidget#addClient {"
                             " border-image: url(:/resources/img/addclient.jpg) 0 0 0 0 stretch stretch;"
                             "} "
           "QWidget#addWorker {"
                       "background:none;"
                      " border-image: url(:/resources/img/registr.jpg) 0 0 0 0 stretch;"
                      "} ";
}

QString stylehelper::getTabWidgetStyle()
{
    return "QTabWidget{"
           "border: none;"
            "}"
            "QTabBar::tab {"
            "border:none;"
           "}";
}

QString stylehelper::getQframeStyle()
{
    return "QFrame {"
            "border: 5px solid qlineargradient(spread:pad, x1:0, y1:0.67, x2:0.475, y2:0.188091, stop:0 rgba(97, 201, 214, 255), stop:1 rgba(0, 62, 82, 255));"

           "background:rgba(40, 40, 39, 235);"
           "}";
}

QString stylehelper::getQLabelStyle()
{
    return "QLabel {"
            "border: none;"
           "color: rgb(83, 116, 143);"
           "font-size: 17px;"
           "}";
}

QString stylehelper::getQLabelZagolovokStyle()
{
    return "QLabel {"
            "border: none;"
           "background-color: qlineargradient(spread:pad, x1:0.28, y1:0.284, x2:0.91, y2:0.0970909, stop:0 rgba(97, 201, 214, 255), stop:1 rgba(0, 49, 64, 255));"
          "font: 75 italic 11pt Segoe Print;"
            "border-radius:5px;"
           "font-size: 18px;"
           "}";
}

QString stylehelper::getButtonRegistr()
{
    return "QPushButton {"
           "background-color: rgb(188, 131, 76);"
"}"
    "QPushButton::hover {"
      "background:rgb(228, 135, 135);"

           "}";
}

QString stylehelper::getQLabelDogovorStyle()
{
    return "QLabel {"
            "border: none;"
           "color: rgb(157, 97, 97);"
            "font: 75 italic 11pt Segoe Print;"
           "font-size: 18px;"
           "}";
}

QString stylehelper::getQMainButtonsStyle()
{
    return "QPushButton {"
           "background-color: rgb(52, 101, 164);"
            "color: black;"
"}"
    "QPushButton::hover {"
      "background:qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 251), stop:0.97 rgba(113, 31, 50, 255));"
"color:white;"
           "}";
}

QString stylehelper::getQButtonBackStyle()
{
    return "QPushButton {"
           "background-color: rgb(52, 101, 164);"
            "color: black;"
"}"
    "QPushButton::hover {"
      "background:qlineargradient(spread:pad, x1:1, y1:0, x2:0, y2:1, stop:0 rgba(0, 0, 0, 251), stop:0.97 rgba(39, 93, 131, 255));"
"color:white;"
           "}";
}

QString stylehelper::getUslugiCheck()
{
    return "QCheckBox {"
            "border:none;"
            "color: maroon;"
            "font-size: 15px;"
            "}";
}

QString stylehelper::getSaveButtonStyle()
{
    return "QPushButton {"
           "background-color: rgb(49, 105, 80);"
            "color: black;"
"}"
    "QPushButton::hover {"
      "background:qlineargradient(spread:pad, x1:0.99, y1:0, x2:0.035, y2:1, stop:0 rgba(46, 52, 54, 255), stop:1 rgba(49, 105, 80, 255));"
"color:white;"
           "}";
}

QString stylehelper::getEnterTextStyle()
{
    return "QLineEdit {"
            "border: none;"
           "color: white;"
          "background-color:rgba(40, 39, 39, 230);"
           "font-size: 19px;"
           "}";
}
