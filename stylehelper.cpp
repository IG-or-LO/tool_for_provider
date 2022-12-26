#include "stylehelper.h"

//начинай здесь...







//............
/*примеры функций для заданий стилевых свойств виджетам

QString stylehelper::getListWidgetStyle()
{
    return "QListWidget{"
            "border:none;"
           "}";
}

QString stylehelper::getTopFrameStyle()
{
    return "QFrame{"
           "border: none;"
           "}";
}

QString stylehelper::getButtonsStyle()
{
    return "QPushButton{"
           "border:none;"
            "}"
            "QPushButton::hover{"
            "background:#961f99;"
            "}";
}

QString stylehelper::getTabsStyle()
{
    return "QWidget#reg {"
           " border-image: url(:/new/img/registration) 0 0 0 0 stretch stretch;"
           "} "
            "QWidget#perinfo {"
                       " border-image: url(:/new/img/fon_information.jpg) 0 0 0 0 stretch stretch;"
                       "} "
            "QWidget#info {"
                       " border-image: url(:/new/img/fon_information.jpg) 0 0 0 0 stretch stretch;"
                       "} "
             "QWidget#about {"
                              " border-image: url(:/new/img/fon_information.jpg) 0 0 0 0 stretch stretch;"
                              "} ";
}




QString stylehelper::getLabelsStyle()
{
    return "QLabel{"
            "color:#fff;"
            "background: none;"
            "border: none;"
            "border-radius:2px;"
            "font-family: 'Roboto-Medium';"
            "font-size:20px;"
           "}";
}

QString stylehelper::getButtonsRegAndEnterStyle()
{
    return
            "QPushButton{"
      "color: #fff;"
      "border-radius: 5px;"
      "padding: 10px 25px;"
      "font-family: 'Roboto-Medium';"
      "font-weight: 500;"
      "background: transparent;"
      "position: relative;"
      "outline: none;"
    "}"

     "QPushButton{"
      "background: #b621fe;"
      "border: none;"
    "}"


    "QPushButton::hover {"
      "background:qlineargradient(spread:pad, x1:0.99, y1:0, x2:0.035, y2:1, stop:0 rgba(240, 0, 172, 255), stop:1 rgba(26, 126, 164, 255));"
      "color: #fff;"
    "}";
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
*/

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
