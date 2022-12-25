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

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void updateSizes(int index);

    void on_pbEnter_clicked();

    void on_pbShowUslugi_clicked();

    void on_pbAddUsluga_clicked();

    void on_pbBack_clicked();

    void on_pbSaveChanges_clicked();

    void on_pbClientSave_clicked();

    void on_pbAddClient_clicked();

    void on_pbExit_clicked();

private:
    Ui::MainWindow *ui;
    DataBase        *db;
    void addComboBoxes();
    void setInterfaceStyle();//метод для применения стилей интрефейса приложения
    void setTabWidgetStyle();
    void addNewUsluga_ui(QString text);
    void clearClientLables();

    QStringList listUslugi;

};
#endif // MAINWINDOW_H
