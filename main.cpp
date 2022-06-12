#include <authorization.h>
#include <QApplication>
// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    Authorization db;
    db.resize(250,100);
    db.setWindowTitle("Enter to system");
    //db.Show();
    return app.exec();
}
