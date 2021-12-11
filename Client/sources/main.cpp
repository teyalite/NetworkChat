#include <QApplication>
#include "../headers/client_window.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ClientWindow window;
    window.show();
    return QApplication::exec();
}