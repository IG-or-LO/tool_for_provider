#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDate>
#include <QFile>
#include <QDebug>

/* Директивы имен таблицы, полей таблицы и базы данных */
#define DATABASE_HOSTNAME   "UslugiDataBase"
#define DATABASE_NAME       "Uslugi.db"
//таблица сотрудников
#define WORKERS               "WorkersTable"
#define WORKER_LOGIN          "LOGIN"
#define WORKER_PASSWORD       "PASSWORD"
//таблица клиентов
#define USERS               "UsersTable"
#define USER_LOGIN          "LOGIN"
#define USER_PASSWORD       "PASSWORD"
#define USER_FIO            "FIO"
#define USER_DOGOVOR        "DOGOVOR"
#define USER_MAIL           "MAIL"
#define USER_ADRESS         "ADRESS"
#define USER_TARIF          "TARIF"
#define USER_DATE           "DATE"
//таблица услуг
#define USLUGI                      "UslugiTable"
#define USLUGI_CCTV                 "CCTV"
#define USLUGI_ANTIVIRUS            "ANTIVIRUS"
#define USLUGI_CLOUDGAMES           "CLOUDGAMES"
#define USLUGI_GARANTEEPLUS         "GARANTEEPLUS"
#define USLUGI_LITRES               "LITRES"
#define USLUGI_OFICCE365            "OFICCE"
#define USLUGI_TURBO                "TURBO"
#define USLUGI_FIXEDIP              "FIXEDIP"
#define USLUGI_PROMISEDPAYMENT      "PROMISEDPAYMENT"
#define USLUGI_PARENTALCONTROL      "PARENTALCONTROL"
#define USLUGI_COMPUTERHELP         "COMPUTERHELP"
#define USLUGI_URGENTCONNECTION     "URGENTCONNECTION"
#define USLUGI_MULTIROOM            "MULTIROOM"
#define USLUGI_LOCALDRIVE           "LOCALDRIVE"
#define USLUGI_SELFBLOCK            "SELFBLOCK"
#define USLUGI_PREMIUM              "PREMIUM"
#define USLUGI_MULTISCREEN          "MULTISCREEN"
#define USLUGI_SMSPAYMENT           "SMSPAYMENT"
#define USLUGI_LIKEATHOME           "LIKEATHOME"



class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();
    /* Методы для непосредственной работы с классом
     * Подключение к базе данных и вставка записей в таблицу
     * */
    bool connectToDataBase();
    bool inserIntoMainTable(const QString nickname, const QString password);
    bool check_log_In(const QString login, const QString password);

    //////////////////

    bool UpdatePersonalInfoIntoMainTable(QString name_user,QString name_add,QString surname_add,QString about);
    bool UpdatePasswordIntoMainTable(QString name_user,QString newpass);
    bool check_name_exist(const QString nickname);

    bool createArchiveMessageTable(QString user_name);
    bool InsertIntoArchiveMessageTable(QString user_name_table,QString user_id_name,QString message);
    QString loadArchiveMessages(QString user_name_table,QString user_id_name);
    QString getPersonalInfo(QString name_user_to_load, int name_surname_or_about);

private:
    // Сам объект базы данных, с которым будет производиться работа
    QSqlDatabase    db;

private:
    /* Внутренние методы для работы с базой данных
     * */
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createMainTable();
    bool createUslugiTable();
    bool createWorkersTable();




};

#endif // DATABASE_H
