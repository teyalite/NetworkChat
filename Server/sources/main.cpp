#include <QApplication>
#include "../headers/server_window.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ServerWindow server;
    server.show();
    return QApplication::exec();
}