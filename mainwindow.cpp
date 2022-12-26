#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stylehelper.h"
#include "qdinamiccheckbox.h"

#include <QMessageBox>
#include <QStyleOption>
#include <QInputDialog>
#include <QValidator>
#include <QPainter>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //загрузка базы данных
    db=new DataBase;
    db->connectToDataBase();
    /////
    ///connections
    connect(ui->pb_ClientBack,&QPushButton::clicked,this,&MainWindow::on_pbBack_clicked);
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this, SLOT(updateSizes(int)));
    ///
    setTabWidgetStyle();
    addComboBoxes();
    setInterfaceStyle();

    //установка параметров ввода и списка услуг из бд
    ui->leDogovor->setValidator(new QIntValidator(0,999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//метод для применения стилей интрефейса приложения FOR DASHA
void MainWindow::setInterfaceStyle()
{

        //ПРИМЕР КАК ЗАДАТЬ ЭЛЛЕМЕНТУ НОВЫЙ СТИЛЬ
   //ui->pbEnter->setStyleSheet(stylehelper::get_enter_button_style());

    //pbEnter-это имя кнопки(можно в файле mainwindow.ui смотреть имена обьектов)
    //get_enter_button_style()-это функция, в которой ты описала стиль для этого обьекта
    //ЧМОКИ-ЧМОКИ))

}

void MainWindow::setTabWidgetStyle()
{
   ui->tabWidget->tabBar()->hide();
    ui->tab_login->setObjectName("login");
    ui->tab_main->setObjectName("main");
    ui->tab_uslugi->setObjectName("uslugi");
    ui->tab_addClient->setObjectName("addClient");

    ui->tabWidget->setCurrentIndex(0);
    ui->leName->setFocus();
    ui->tabWidget->setStyleSheet(stylehelper::getTabWidgetStyle());
    ui->tab_login->setStyleSheet(stylehelper::getTabStyle());
    ui->tab_main->setStyleSheet(stylehelper::getTabStyle());
    ui->tab_uslugi->setStyleSheet(stylehelper::getTabStyle());
    ui->tab_addClient->setStyleSheet(stylehelper::getTabStyle());
    ui->frame->setStyleSheet(stylehelper::getQframeStyle());
    ui->label_login->setStyleSheet(stylehelper::getQLabelStyle());
    ui->label_pass->setStyleSheet(stylehelper::getQLabelStyle());
    ui->label_enter_or_reg->setStyleSheet(stylehelper::getQLabelZagolovokStyle());
    ui->pbEnter->setStyleSheet(stylehelper::getButtonRegistr());
    ui->label_ClientDogovor->setStyleSheet(stylehelper::getQLabelDogovorStyle());
    ui->pbShowUslugi->setStyleSheet(stylehelper::getQMainButtonsStyle());
    ui->pbAddClient->setStyleSheet(stylehelper::getQMainButtonsStyle());
    ui->pbAddUsluga->setStyleSheet(stylehelper::getQMainButtonsStyle());
    ui->pbExit->setStyleSheet(stylehelper::getQMainButtonsStyle());
    ui->pbBack->setStyleSheet(stylehelper::getQButtonBackStyle());
    ui->pb_ClientBack->setStyleSheet(stylehelper::getQButtonBackStyle());
    ui->pbSaveChanges->setStyleSheet(stylehelper::getSaveButtonStyle());
    ui->pbClientSave->setStyleSheet(stylehelper::getSaveButtonStyle());
    ui->laClientLogin->setStyleSheet(stylehelper::getQLabelZagolovokStyle());
    ui->laClientPass->setStyleSheet(stylehelper::getQLabelZagolovokStyle());
    ui->laClientFio->setStyleSheet(stylehelper::getQLabelZagolovokStyle());
    ui->laClientDog->setStyleSheet(stylehelper::getQLabelZagolovokStyle());
    ui->laClientMail->setStyleSheet(stylehelper::getQLabelZagolovokStyle());
    ui->laClientAddress->setStyleSheet(stylehelper::getQLabelZagolovokStyle());
    ui->laClientTarif->setStyleSheet(stylehelper::getQLabelZagolovokStyle());
    ui->laClientDate->setStyleSheet(stylehelper::getQLabelZagolovokStyle());
    ui->leDogovor->setStyleSheet(stylehelper::getEnterTextStyle());
    ui->leClientLogin->setStyleSheet(stylehelper::getEnterTextStyle());
    ui->leClientPass->setStyleSheet(stylehelper::getEnterTextStyle());
    ui->leClientFio->setStyleSheet(stylehelper::getEnterTextStyle());
    ui->leClientDog->setStyleSheet(stylehelper::getEnterTextStyle());
    ui->leClientMail->setStyleSheet(stylehelper::getEnterTextStyle());
    ui->leClientAddress->setStyleSheet(stylehelper::getEnterTextStyle());
    ui->leClientTarif->setStyleSheet(stylehelper::getEnterTextStyle());
    ui->leClientDate->setStyleSheet(stylehelper::getEnterTextStyle());






}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p,this);
    QWidget::paintEvent(event);
}

void MainWindow::updateSizes(int index)
{
    for(int i=0;i<ui->tabWidget->count();i++)
        if(i!=index)
            ui->tabWidget->widget(i)->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    ui->tabWidget->widget(index)->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->tabWidget->widget(index)->resize(ui->tabWidget->widget(index)->minimumSizeHint());
    ui->tabWidget->widget(index)->adjustSize();
    resize(minimumSizeHint());
    adjustSize();
}

//добавление чекбоксов услуг
void MainWindow::addComboBoxes()
{
     listUslugi=db->getNamesUslugi();
    for (int i=0;i<listUslugi.size();i++) {
        qdinamicCheckBox *newbox=new qdinamicCheckBox(this);
//        newbox->setStyleSheet(stylehelper::getUslugiCheck());
        newbox->setText(listUslugi[i]);
        newbox->setLayoutDirection(Qt::RightToLeft);
        ui->verticalLayout_3->addWidget(newbox);
    }
}


void MainWindow::addNewUsluga_ui(QString text)
{
    qdinamicCheckBox *newbox=new qdinamicCheckBox;
    newbox->setLayoutDirection(Qt::RightToLeft);
    newbox->setText(text);
//     newbox->setStyleSheet(stylehelper::getUslugiCheck());
    ui->verticalLayout_3->addWidget(newbox);
}

void MainWindow::on_pbEnter_clicked()
{
    if(db->check_log_In(ui->leName->text(),ui->lePass->text()))
           ui->tabWidget->setCurrentIndex(1);
    else
    {
        QMessageBox mess;
        mess.setText("Не верные данные входа");
        mess.exec();
    }
}

void MainWindow::on_pbShowUslugi_clicked()
{

    QMessageBox mess;
    if(ui->leDogovor->text()=="")
    {
        mess.setText("Введите номер договора клиента!");
        mess.exec();

    }
    else if(!db->check_user_exist(ui->leDogovor->text()))
    {
        mess.setText("Нет клиента с таким номером договора!");
        mess.exec();
    }
    else
    {
        QString str="Клиент: "+ui->leDogovor->text();
        ui->lablel_Client->setText(str);
        QStringList statuslist;
        statuslist=db->showUserUslugi(ui->leDogovor->text().toInt());
        for (int i=0; i<listUslugi.size();i++) {
            qdinamicCheckBox *box=qobject_cast<qdinamicCheckBox*>(ui->verticalLayout_3->itemAt(i)->widget());
            if(statuslist[i]=="1"){
                box->setChecked(true);
            }
            else
                box->setChecked(false);
        }
        ui->tabWidget->setCurrentIndex(2);
    }
}

void MainWindow::on_pbSaveChanges_clicked()
{
    QMessageBox mess;
    bool ok;
    for (int i=0; i<ui->verticalLayout_3->count(); i++) {
        qdinamicCheckBox *box=qobject_cast<qdinamicCheckBox*>(ui->verticalLayout_3->itemAt(i)->widget());
            ok=db->add_status_uslugi(ui->leDogovor->text(), box->text(), box->isChecked());
            if(!ok)
                break;
    }
    if(ok)
    {
        mess.setText("Данные успешно записаны");
        mess.exec();
    }
    else
    {
        mess.setText("Ошибка при записи");
        mess.exec();
    }

}


void MainWindow::on_pbAddUsluga_clicked()
{
    QMessageBox mess;
    bool pbOK;
    QString str= QInputDialog::getText(0,
                                       "Новая услуга",
                                       "Наименование услуги",
                                       QLineEdit::Normal,
                                       "",
                                       &pbOK,
                                       Qt::Popup,
                                       Qt::ImhLatinOnly);
    if(pbOK)
    {
        if(db->add_new_usluga(str)){
            mess.setText("Услуга добавлена!");
            mess.exec();
            addNewUsluga_ui(str);
        }
        else
        {
            mess.setText("Ошибка добавления!");
            mess.exec();
        }
    }
}

void MainWindow::on_pbBack_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_pbClientSave_clicked()
{
    QMessageBox mess;
    QStringList list;
    if(ui->leClientLogin->text()!="" && ui->leClientPass->text()!="" &&
       ui->leClientFio->text()!="" && ui->leClientMail->text()!="" &&
       ui->leClientDog->text()!="" && ui->leClientDate->text()!="" &&
       ui->leClientTarif->text()!="" && ui->leClientAddress->text()!="")
    {
        list.append(ui->leClientLogin->text()); list.append(ui->leClientPass->text());
        list.append(ui->leClientFio->text()); list.append(ui->leClientDog->text());
        list.append(ui->leClientMail->text()); list.append(ui->leClientAddress->text());
        list.append(ui->leClientTarif->text());list.append(ui->leClientDate->text());
        if(db->add_new_client(list))
        {
            mess.setText("Клиент добавлен!");
            mess.exec();
            clearClientLables();
        }
        else
        {
            mess.setText("Ошибка!");
            mess.exec();
        }

    }
    else
    {
        mess.setText("Заполните все поля!");
        mess.exec();
    }
}

void MainWindow::clearClientLables()
{
           ui->leClientLogin->clear();
           ui->leClientPass->clear();
           ui->leClientFio->clear();
           ui->leClientMail->clear();
           ui->leClientDog->clear();
           ui->leClientDate->clear();
           ui->leClientTarif->clear();
           ui->leClientAddress->clear();
}

void MainWindow::on_pbAddClient_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_pbExit_clicked()
{
    ui->leName->clear();
    ui->lePass->clear();
    ui->tabWidget->setCurrentIndex(0);
}
