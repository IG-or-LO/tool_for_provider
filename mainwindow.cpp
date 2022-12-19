#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stylehelper.h"

#include<QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setInterfaceStyle();

    //загрузка базы данных
    db=new DataBase;
    db->connectToDataBase();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//метод для применения стилей интрефейса приложения
void MainWindow::setInterfaceStyle()
{

}

bool MainWindow::addNewUsluga(QString text)
{
    QCheckBox *newbox=new QCheckBox;
    newbox->setLayoutDirection(Qt::RightToLeft);
    newbox->setText(text);

    if(ui->verticalLayout_8->count()<ui->verticalLayout_7->count())
        ui->verticalLayout_8->addWidget(newbox);
    else
        ui->verticalLayout_7->addWidget(newbox);
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
