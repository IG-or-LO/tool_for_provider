#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stylehelper.h"
#include "qdinamiccheckbox.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QValidator>
#include <QCheckBox>
#include <QLayout>
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
    ///
    ///
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
void MainWindow::addComboBoxes()
{
     listUslugi=db->getNamesUslugi();
    for (int i=0;i<listUslugi.size();i++) {
        qdinamicCheckBox *newbox=new qdinamicCheckBox(this);
        newbox->setText(listUslugi[i]);
        newbox->setLayoutDirection(Qt::RightToLeft);
        ui->verticalLayout_3->addWidget(newbox);
    }
}




bool MainWindow::addNewUsluga(QString text)
{
    qdinamicCheckBox *newbox=new qdinamicCheckBox;

    newbox->setLayoutDirection(Qt::RightToLeft);
    newbox->setText("text");

    ui->verticalLayout_3->addWidget(newbox);
    return true;
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
        QStringList statuslist;
        statuslist=db->showUserUslugi(ui->leDogovor->text().toInt());
        for (int i=0; i<listUslugi.size();i++) {
            qdinamicCheckBox *box=qobject_cast<qdinamicCheckBox*>(ui->verticalLayout_3->itemAt(i)->widget());
            if(statuslist[i]=="0"){
                box->setChecked(true);
            }
            else
                box->setChecked(false);
        }
        ui->tabWidget->setCurrentIndex(2);
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
            qdinamicCheckBox *newbox=new qdinamicCheckBox(this);
            newbox->setText(str);
            newbox->setLayoutDirection(Qt::RightToLeft);
            ui->verticalLayout_3->addWidget(newbox);
        }
        else
        {
            mess.setText("Ошибка добавления!");
            mess.exec();
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}
