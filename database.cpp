#include "database.h"
#include <QSqlRecord>

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

/* Методы для подключения к базе данных
 * */
bool DataBase::connectToDataBase()
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
    if(!QFile("./" DATABASE_NAME).exists()){
        this->restoreDataBase();

        return false;
    } else {
        this->openDataBase();
        return true;
    }
}

/* Методы восстановления базы данных
 * */
bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createMainTable() || !this->createUslugiTable() || !this->createWorkersTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
    return false;
}

/* Метод для открытия базы данных
 * */
bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    db = QSqlDatabase::addDatabase("QSQLITE");//QSQLITE
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("./" DATABASE_NAME);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

/* Методы закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();
}

/* Метод для создания таблицы пользователей в базе данных
 * */
bool DataBase::createMainTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " USERS  " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            USER_LOGIN      " VARCHAR   NOT NULL,"
                            USER_PASSWORD   " VARCHAR   NOT NULL,"
                            USER_FIO        " VARCHAR  NOT NULL,"
                            USER_DOGOVOR    " INT NOT NULL ,"
                            USER_MAIL       " VARCHAR  NOT NULL, "
                            USER_ADRESS     " VARCHAR   NOT NULL,"
                            USER_TARIF      " VARCHAR   NOT NULL,"
                            USER_DATE       " DATE  NOT NULL"
                             " )"
                    )){
        qDebug() << "DataBase: error of create " <<USERS;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::createUslugiTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " USLUGI  " ("
                           // "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "user_id    INTEGER NOT NULL,"
                            USLUGI_CCTV                 " BOOLEAN NOT NULL,"
                            USLUGI_ANTIVIRUS            " BOOLEAN NOT NULL,"
                            USLUGI_CLOUDGAMES           " BOOLEAN NOT NULL,"
                            USLUGI_GARANTEEPLUS         " BOOLEAN NOT NULL,"
                            USLUGI_LITRES               " BOOLEAN NOT NULL,"
                            USLUGI_OFICCE365            " BOOLEAN NOT NULL,"
                            USLUGI_TURBO                " BOOLEAN NOT NULL,"
                            USLUGI_FIXEDIP              " BOOLEAN NOT NULL,"
                            USLUGI_PROMISEDPAYMENT      " BOOLEAN NOT NULL,"
                            USLUGI_PARENTALCONTROL      " BOOLEAN NOT NULL,"
                            USLUGI_COMPUTERHELP         " BOOLEAN NOT NULL,"
                            USLUGI_URGENTCONNECTION     " BOOLEAN NOT NULL,"
                            USLUGI_MULTIROOM            " BOOLEAN NOT NULL,"
                            USLUGI_LOCALDRIVE           " BOOLEAN NOT NULL,"
                            USLUGI_SELFBLOCK            " BOOLEAN NOT NULL,"
                            USLUGI_PREMIUM              " BOOLEAN NOT NULL,"
                            USLUGI_MULTISCREEN          " BOOLEAN NOT NULL,"
                            USLUGI_SMSPAYMENT           " BOOLEAN NOT NULL,"
                            USLUGI_LIKEATHOME           " BOOLEAN NOT NULL,"
                            "FOREIGN KEY (user_id) REFERENCES " USERS " (id) "
                             " )"
                    )){
        qDebug() << "DataBase: error of create " <<USERS;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::createWorkersTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " WORKERS  " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            WORKER_LOGIN      " VARCHAR   NOT NULL,"
                            WORKER_PASSWORD   " VARCHAR   NOT NULL "
                             " )"
                    )){
        qDebug() << "DataBase: error of create " <<WORKERS;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::check_log_In(const QString login, const QString password)
{
    QSqlQuery query;
    QString names=nullptr;
    QString str = QString("SELECT * FROM " WORKERS " WHERE EXISTS "
                          "(SELECT " WORKER_LOGIN " FROM " WORKERS " WHERE " WORKER_LOGIN "= '"+login+"'"
                          "AND " WORKER_PASSWORD "= '"+password+"' )");

    query.prepare(str);
    query.exec();
    if(query.isActive()){
        qDebug()<<"query is active now";
        while(query.next())
        {
            names=query.value(0).toString();
            qDebug()<<query.value(0).toString();
        }
    }
    else
        qDebug()<<"ERROR:"<<query.lastError();

    return names==nullptr?false:true;
}



//bool DataBase::createArchiveMessageTable(QString user_name)
//{
//    QSqlQuery query;
//    QString str=QString("CREATE TABLE '"+user_name+"' ("
//                                                   "id INTEGER PRIMARY KEY AUTOINCREMENT,"
//                                                   "ANOTHER_USER INTEGER,"
//                                                   "MAILS VARCHAR,"
//                                                   "FOREIGN KEY (ANOTHER_USER) REFERENCES "
//                                                   "" SERVER " (id) )");
//    qDebug()<< "CREATE DATABASE "<<user_name;
//    if(query.exec(str))
//        return true;
//    else
//    {
//        qDebug()<<query.lastError();
//        return false;
//    }
//}


//bool DataBase::InsertIntoArchiveMessageTable(QString user_name_table, QString user_id_name,QString message)
//{
//    QSqlQuery query;
//    QString str=QString("INSERT INTO '"+user_name_table+"'"
//                                                        "(ANOTHER_USER, MAILS)"
//                                                        "VALUES("
//                                                        "(SELECT NICKNAME FROM " SERVER " WHERE " SERVER_NICKNAME " = '"+user_id_name+"'),"
//                                                        "('"+message+"')  "
//                                                        ") ");
//    qDebug()<< "try insert into db- "<<user_name_table<<" this meesage= "<<message;
//    if(query.exec(str))
//        return true;
//    else
//    {
//        qDebug()<<query.lastError();
//        return false;
//    }
//}

//QString DataBase::loadArchiveMessages(QString user_name_table, QString user_id_name)
//{
//    QSqlQuery query;
//    QString males="";

//    QString str = QString("SELECT MAILS FROM "+user_name_table+" WHERE ANOTHER_USER = '"+user_id_name+"'  ");
//    query.prepare(str);
//    query.exec();

//   if(query.isActive()){
//       qDebug()<<"query is active now";
//       while(query.next())
//       {
//           males.append(query.value(0).toString());
//           males.append("\n");
//       }
//   }
//   else
//       qDebug()<<"ERROR:"<<query.lastError();

//   return males;
//}

//QString DataBase::getPersonalInfo(QString name_user_to_load, int name_surname_or_about)
//{
//    QString colomn;
//    QString mess;
//    if(name_surname_or_about==0)
//        colomn="NAME";
//    else if(name_surname_or_about==1)
//        colomn="SURNAME";
//    else if(name_surname_or_about==2)
//        colomn="ABOUT";

//    QSqlQuery query;
//    QString str = QString("SELECT "+colomn+" FROM " SERVER " WHERE NICKNAME = '"+name_user_to_load+"'  ");
//    query.prepare(str);
//    query.exec();

//    if(query.first())
//        mess=query.value(0).toString();
//    else
//        qDebug()<<query.lastError();

//    return mess;

//}



///* Метод для вставки записи в таблицу пользователей
// * */
//bool DataBase::inserIntoMainTable(const QString nickname, const QString password)
//{

//    QSqlQuery query;
//    /* В начале SQL запрос формируется с ключами,
//     * которые потом связываются методом bindValue
//     * для подстановки данных из QVariantList
//     * */
//    query.prepare("INSERT INTO " SERVER " ( " SERVER_NICKNAME ", "
//                                              SERVER_PASSWORD ") "
//                  "VALUES (:NICKNAME, :PASSWORD )");
//    query.bindValue(":NICKNAME",  nickname);
//    query.bindValue(":PASSWORD",  password);
//    // После чего выполняется запросом методом exec()
//    if(!query.exec()){
//        qDebug() << "error insert into " << SERVER;
//        qDebug() << query.lastError().text();
//        return false;
//    } else {
//        return true;
//    }
//    return false;
//}

//bool DataBase::UpdatePersonalInfoIntoMainTable(QString name_user, QString name_add, QString surname_add, QString about)
//{
//    QSqlQuery query;
//    /* В начале SQL запрос формируется с ключами,
//     * которые потом связываются методом bindValue
//     * для подстановки данных из QVariantList
//     * */
//    query.prepare("UPDATE  " SERVER " SET " SERVER_NAME" = '"+name_add+"' ,"
//                                            SERVER_SURNAME" = '"+surname_add+"' ,"
//                                            SERVER_ABOUT" = '"+about+"'"
//                                            "WHERE " SERVER_NICKNAME " = '"+name_user+"' ");

//    // После чего выполняется запросом методом exec()
//    if(!query.exec()){
//        qDebug() << "error UPDATE INFO in " << SERVER<<"to user:"<<name_user;
//        qDebug() << query.lastError().text();
//        return false;
//    } else {
//        return true;
//    }
//    return false;
//}

//bool DataBase::UpdatePasswordIntoMainTable(QString name_user, QString newpass)
//{
//    QSqlQuery query;
//    /* В начале SQL запрос формируется с ключами,
//     * которые потом связываются методом bindValue
//     * для подстановки данных из QVariantList
//     * */
//    query.prepare("UPDATE  " SERVER " SET " SERVER_PASSWORD" = '"+newpass+"' "
//                                   "WHERE " SERVER_NICKNAME " = '"+name_user+"' ");

//    // После чего выполняется запросом методом exec()
//    if(!query.exec()){
//        qDebug() << "error UPDATE PASS in " << SERVER<<"to user:"<<name_user;
//        qDebug() << query.lastError().text();
//        return false;
//    } else {
//        return true;
//    }
//    return false;
//}

//bool DataBase::check_name_exist(const QString nickname)
//{
//    QSqlQuery query;
//    QString names=nullptr;
//    QString str = QString("SELECT * FROM ServerTable WHERE EXISTS "
//                          "(SELECT NICKNAME FROM ServerTable WHERE NICKNAME= '"+nickname+"')");

//    query.prepare(str);
//    query.exec();
//   qDebug()<< query.lastError();
//    if(query.isActive()){
//        qDebug()<<"query is active now";
//        while(query.next())
//        {
//            names=query.value(0).toString();
//        }
//    }
//    else
//        qDebug()<<"ERROR:"<<query.lastError();

//    return names==nullptr?false:true;

//}


