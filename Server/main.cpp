#include <QApplication>
#include "ServerWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ServerWindow server;
    server.show();
    return QApplication::exec();
}