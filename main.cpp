#include "widget.h"
#include <QMessageBox>
#include <QApplication>
#include <QSharedMemory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSharedMemory sharedMemory("QQMusic");
    if(sharedMemory.attach())
    {
        QMessageBox::information(nullptr,"QQMusic","QQMusic已经在运⾏...");
    }
    sharedMemory.create(1);

    Widget w;
    w.show();
    return QApplication::exec();



}
