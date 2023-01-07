#include "WindowMain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    WindowMain w;
    w.show();
    return a.exec();
}
