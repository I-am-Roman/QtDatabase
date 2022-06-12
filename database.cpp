#include "database.h"
#include <QtWidgets>

Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("accountbook");


    if (!db.open())
    {
        qDebug() << "Cannot open database:" << db.lastError();
        return ;
    }

    query = new QSqlQuery(db);
    QString   str  = "CREATE TABLE accountbook ( "
                         "Number INTEGER PRIMARY KEY NOT NULL , "
                         "Login   VARCHAR(26), "
                         "Password VARCHAR(26))";
}

bool Database::CheckResult(QString& N, QString& P)
{

  if (!query->exec("SELECT * FROM accountbook;"))
  {
    qDebug() << "Unable to execute query - exiting";
  }
    //Reading of the data
    QSqlQuery* query2;
    query2 = query;
    QSqlRecord rec     = query2->record();
    QString    strLog;
    QString    strPass;

    if (!query2->exec("SELECT * FROM accountbook;"))
    {
        qDebug() << "Unable to execute query - exiting";
    }

    while (query2->next())
    {
        strLog  = query2->value(rec.indexOf("Login")).toString();
        strPass = query2->value(rec.indexOf("Password")).toString();

        if((N == strLog) && (P == strPass))
        {
            return true;
        }
    }
    return false;
}

void Database::AddUser(QString& N, QString& P)
{
    if (!query->exec("SELECT * FROM accountbook;"))
    {
        qDebug() << "Unable to execute query - exiting";
    }

    // srting for adding data
     QString strF =
           "INSERT INTO  accountbook (Number, Login, Password) "
           "VALUES(%1, '%2', '%3');";

     int numberOfRows = 0;
     // the size() function is not supported by SQLITE
     // get numner of Row
     if(query->last())
     {
         numberOfRows =  query->at() + 1;
         query->first();
         query->previous();
     }

    QString str = strF.arg(numberOfRows + 1)
               .arg(N)
               .arg(P);

     if (!query->exec(str))
     {
         qDebug() << "Unable to make insert operation";
     }
     if (!query->exec("SELECT * FROM accountbook;"))
     {
         qDebug() << "Unable to execute query - exiting";
     }
}

void Database::Print_Databe()
{
    if (!query->exec("SELECT * FROM accountbook;"))
    {
        qDebug() << "Unable to execute query - exiting";
    }

    QSqlRecord rec     = query->record();
    int        nNumber = 0;
    QString    strLog;
    QString    strPass;
    while (query->next())
    {
        nNumber  = query->value(rec.indexOf("Number")).toInt();
        strLog  = query->value(rec.indexOf("Login")).toString();
        strPass = query->value(rec.indexOf("Password")).toString();

        qDebug() << nNumber << " " << strLog << ";\t"
                 << strPass << ";" ;
    }

    if(nNumber == 0)
    {
         qDebug() << "Database is empty!";
    }
    return;
}

void Database :: DeleteDb()
{
    if (!query->exec("DELETE FROM accountbook;"))
    {
        qDebug() << "Unable DELETE";
    }
}
