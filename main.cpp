#include "scnmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SCNMainWindow w;
    w.show();

    return a.exec();
}
