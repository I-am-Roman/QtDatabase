#pragma once
#include <database.h>

#include <QWidget>
#include <QtWidgets>
class Authorization : public QWidget
{
    Q_OBJECT
private:
    QLabel*    name_label ;
    QLineEdit* information;

    QLabel*    plblPassword;
    QLineEdit* ptxtPassword;

    QString Name;
    QString Password ;

    Database db_for_us;

public:
    Authorization(QWidget* pwgt = 0);

public slots:
    void authorization();
    void registration();
    void showdatabase();
    void deletedatabase();
};
