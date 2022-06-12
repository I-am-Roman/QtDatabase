#include "authorization.h"
#include <QtWidgets>


Authorization::Authorization(QWidget* pwgt/* = 0*/) : QWidget(pwgt)
{
    show();

    setStyleSheet("background-color:#76A3C4");
    name_label = new QLabel("&Login:");
    information     = new QLineEdit;
    // connect a Line and Label
    name_label->setBuddy(information);

    plblPassword = new QLabel("&Password:");
    ptxtPassword = new QLineEdit;
    plblPassword->setBuddy(ptxtPassword);
    // hide simbols
    ptxtPassword->setEchoMode(QLineEdit::Password);

    QPushButton* pcmdAuth = new QPushButton("Authorization");
    pcmdAuth->setStyleSheet("background-color:#819672");
    connect(pcmdAuth,SIGNAL(clicked()),this,SLOT(authorization()));

    QPushButton* pcmdReg = new QPushButton("Registration");
    pcmdReg->setStyleSheet("background-color: #819672");
    connect(pcmdReg,SIGNAL(clicked()),this,SLOT(registration()));

    QPixmap pix(":/new/prefix1/1.ico");
    QPushButton* pcmdShow = new QPushButton("");
    pcmdShow->setIcon(pix);
    pcmdShow->setIconSize(pix.size());
    pcmdShow->setStyleSheet("QPushButton{background: transparent;}");
    connect(pcmdShow,SIGNAL(clicked()),this,SLOT(showdatabase()));

    QPushButton* pcmdDel = new QPushButton("Delete");
    pcmdDel->setStyleSheet("background-color: #819672");
    connect(pcmdDel,SIGNAL(clicked()),this,SLOT(deletedatabase()));

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(name_label);
    pvbxLayout->addWidget(information);
    pvbxLayout->addWidget(plblPassword);
    pvbxLayout->addWidget(ptxtPassword);
    pvbxLayout->addWidget(pcmdAuth);
    pvbxLayout->addWidget(pcmdReg);
    pvbxLayout->addWidget(pcmdDel);
    pvbxLayout->addWidget(pcmdShow);

    setLayout(pvbxLayout);

}

void Authorization :: authorization()
{

    Name = information->text();
    Password = ptxtPassword->text();

    if(db_for_us.CheckResult(Name,Password))
    {
        QMessageBox::information(this, "Welcome, " + Name, "Welcome home!");
    }
    else
    {
        QMessageBox::warning(this, "Title", "User not found!");
    }
}

void Authorization :: registration()
{
    Name = information->text();
    Password = ptxtPassword->text();
    if(Name == "" || Name == " " )
    {
        QMessageBox::warning(this, "Welcome, " + Name, "The name is empty!");
        return;
    }
    if(Password == "" || Password == " " )
    {
        QMessageBox::warning(this, "Welcome, " + Name, "The password is empty!");
        return;
    }

    if(db_for_us.CheckResult(Name,Password))
    {
        QMessageBox::information(this, "Welcome, " + Name, "You are already registered!");
        return;
    }
    db_for_us.AddUser(Name,Password);
}

void Authorization :: showdatabase()
{
    db_for_us.Print_Databe();
}
void Authorization ::deletedatabase()
{
    db_for_us.DeleteDb();
}
