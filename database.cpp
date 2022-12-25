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
                    ))
    {
        qDebug() << "DataBase: error of create " <<USERS;
        qDebug() << query.lastError().text();
        return false;
    }
    else
    {

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
     query.exec("PRAGMA foreign_keys = ON;");
    if(!query.exec( "CREATE TABLE " USLUGI  " ("
                           // "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "user_id INTEGER NOT NULL,"
                            USLUGI_CCTV                 " BOOLEAN DEFAULT '0',"
                            USLUGI_ANTIVIRUS            " BOOLEAN DEFAULT '0',"
                            USLUGI_CLOUDGAMES           " BOOLEAN DEFAULT '0',"
                            USLUGI_GARANTEEPLUS         " BOOLEAN DEFAULT '0',"
                            USLUGI_LITRES               " BOOLEAN DEFAULT '0',"
                            USLUGI_OFICCE365            " BOOLEAN DEFAULT '0',"
                            USLUGI_TURBO                " BOOLEAN DEFAULT '0',"
                            USLUGI_FIXEDIP              " BOOLEAN DEFAULT '0',"
                            USLUGI_PROMISEDPAYMENT      " BOOLEAN DEFAULT '0',"
                            USLUGI_PARENTALCONTROL      " BOOLEAN DEFAULT '0',"
                            USLUGI_COMPUTERHELP         " BOOLEAN DEFAULT '0',"
                            USLUGI_URGENTCONNECTION     " BOOLEAN DEFAULT '0',"
                            USLUGI_MULTIROOM            " BOOLEAN DEFAULT '0',"
                            USLUGI_LOCALDRIVE           " BOOLEAN DEFAULT '0',"
                            USLUGI_SELFBLOCK            " BOOLEAN DEFAULT '0',"
                            USLUGI_PREMIUM              " BOOLEAN DEFAULT '0',"
                            USLUGI_MULTISCREEN          " BOOLEAN DEFAULT '0',"
                            USLUGI_SMSPAYMENT           " BOOLEAN DEFAULT '0',"
                            USLUGI_LIKEATHOME           " BOOLEAN DEFAULT '0',"
                            "FOREIGN KEY (user_id) REFERENCES " USERS " (id)"
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
         createAdminAcc();
        return true;
    }
    return false;
}

bool DataBase::createAdminAcc()
{
        QString log="admin";
        QString pass="12345";
        QSqlQuery query;
        QString str=QString("INSERT INTO " WORKERS " (LOGIN, PASSWORD) VALUES('"+log+"', '"+pass+"')");
    //    query.bindValue(":LOG", "admin");
     //   query.bindValue(":PASS", "12345");
        qDebug()<< "try add ADMIN";
        if(query.exec(str))
            return true;
        else
        {
            qDebug()<<query.lastError();
            return false;
        }
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

bool DataBase::check_user_exist(QString dogovor)
{
    QSqlQuery query;
      QString names=nullptr;
      QString str = QString("SELECT * FROM " USERS " WHERE EXISTS "
                            "(SELECT " USER_LOGIN " FROM " USERS " WHERE " USER_DOGOVOR "= '"+dogovor+"')");

      query.prepare(str);
      query.exec();
     qDebug()<< query.lastError();
      if(query.isActive()){
          qDebug()<<"query is active now";
          while(query.next())
          {
              names=query.value(0).toString();
          }
      }
      else
          qDebug()<<"ERROR:"<<query.lastError();

      return names==nullptr?false:true;
}

QStringList DataBase::showUserUslugi(const int dogovor)
{
        QSqlQuery query;
        QStringList list;
        query.prepare("SELECT * FROM " USLUGI " WHERE user_id = ("
                                                                 "SELECT id FROM " USERS " WHERE "
                                                                 " " USER_DOGOVOR "= :dog) ");
        query.bindValue(":dog",dogovor);
        query.exec();

        QSqlRecord rec=query.record();



        qDebug()<<"all fields:"<<rec.count();
        while (query.next()){
            for(int i=0;i<rec.count()-1;i++){
               list.append(query.value(i+1).toString());
            }
        }
        qDebug()<<list;
        return list;

}

QStringList DataBase::getNamesUslugi()
{
    QStringList list;
    QSqlQuery query;

    query.prepare("SELECT * FROM " USLUGI " WHERE user_id ='1'");
    query.exec();

    QSqlRecord rec=query.record();
    qDebug()<<"there are fields:"<<rec.count();
    while (query.next()){
        for(int i=1;i<rec.count();i++){
            list.append(rec.fieldName(i));
        }
    }
    qDebug()<<list;
    return list;
}

bool DataBase::add_new_usluga(const QString text)
{
    QSqlQuery query;
    query.prepare("ALTER TABLE " USLUGI " ADD '"+text+"' BOOLEAN FALSE");
    if(!query.exec())
    {
        qDebug()<<"cant add new usluga:"<<query.lastError();
        return false;
    }
    else
        return true;
}

bool DataBase::add_status_uslugi(const QString dogovor,const QString colomn, const bool status)
{
    QSqlQuery query;
    query.prepare("UPDATE " USLUGI " SET '"+colomn+"' = (:status) WHERE user_id= ("
                                              "SELECT id FROM " USERS " WHERE " USER_DOGOVOR "= (:dogovor) )");

     query.bindValue(":status", status);
     query.bindValue(":dogovor", dogovor);

    qDebug()<< "try insert into db- "<<USLUGI<<" in colomn="<<colomn<<" status= "<<status;
       if(query.exec())
           return true;
       else
       {
           qDebug()<<query.lastError();
           return false;
       }
}

bool DataBase::add_new_client(const QStringList &list)
{
    QSqlQuery query;
    QString str=QString("INSERT INTO " USERS " (LOGIN, PASSWORD, FIO,DOGOVOR,MAIL,"
                                             "ADRESS,TARIF,DATE)"
                        " VALUES('"+list[0]+"', '"+list[1]+"', '"+list[2]+"', '"+list[3]+"', '"+list[4]+"',"
                                  "'"+list[5]+"', '"+list[6]+"', '"+list[7]+"')");

    qDebug()<< "try add Client";
    if(query.exec(str))
    {
        add_new_record_uslugi(list[3]);
        return true;
    }
    else
    {
        qDebug()<<query.lastError();
        return false;
    }
}

bool DataBase::add_new_record_uslugi(const QString dogovor)
{
    QString id;
    QSqlQuery query;

    query.prepare("SELECT id FROM " USERS " WHERE DOGOVOR ='"+dogovor+"'");
    query.exec();

   qDebug()<<"try to get id";
    if(query.isActive()){
        qDebug()<<"query is active now";
        while(query.next())
        {
            id=query.value(0).toString();
        }
    }
    else
        qDebug()<<"ERROR getting id:"<<query.lastError();

    QString str=QString("INSERT INTO " USLUGI " (user_id)"
                        " VALUES('"+id+"')");

    qDebug()<< "try add new record in table uslugi";
    if(query.exec(str))
    {
        qDebug()<< "sucsess in adding";
        return true;
    }
    else
    {
        qDebug()<<query.lastError();
        return false;
    }
}

bool DataBase::renameTable(const QString before, const QString after)
{

    QSqlQuery query;
    QString str=QString("ALTER TABLE '"+before+"' RENAME TO '"+after+"' ");
    qDebug()<<"TRY to rename table:"<<before;
    if(!query.exec(str))
    {
        qDebug()<<"cant rename table: "<<query.lastError();
        return false;
    }
    else
        return true;
}

bool DataBase::createRenamedTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " USLUGI  " ("
                           // "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            "user_id    INTEGER NOT NULL,"
                            "FOREIGN KEY (user_id) REFERENCES " USERS " (id) "
                             " )"
                    )){
        qDebug() << "DataBase: error of create RenamedTable" <<USLUGI;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}
