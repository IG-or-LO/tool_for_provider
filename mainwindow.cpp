#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stylehelper.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setInterfaceStyle();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//метод для применения стилей интрефейса приложения
void MainWindow::setInterfaceStyle(){

}
