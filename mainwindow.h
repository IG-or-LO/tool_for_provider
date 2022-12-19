#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbEnter_clicked();

    void on_pbShowUslugi_clicked();

    void on_pbAddUsluga_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    DataBase        *db;
    void addComboBoxes();
    void setInterfaceStyle();//метод для применения стилей интрефейса приложения
    bool addNewUsluga(QString text);

    QStringList listUslugi;

};
#endif // MAINWINDOW_H
