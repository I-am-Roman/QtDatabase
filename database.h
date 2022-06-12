#pragma once
#include <QWidget>
#include <QtWidgets>

#include <QtSql>

class Database : public QWidget
{
    Q_OBJECT
private:
    QSqlDatabase db;
    //Creating of the data base query
    QSqlQuery* query;
public:

   Database();

    bool CheckResult(QString& N, QString& P);
    void AddUser(QString& N, QString& P);
    void Print_Databe();
    void DeleteDb();
};

