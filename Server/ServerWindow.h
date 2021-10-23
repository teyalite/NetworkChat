#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QtWidgets>
#include <QtNetwork>

class ServerWindow: public QWidget {
    Q_OBJECT
public:
    ServerWindow();
    void SendToAll(const QString& message);
private slots:
    void ClientConnect();
    void ClientDisconnect();
    void ReceivedData();
private:
    QLabel* serverState;
    QPushButton* closeButton;
    QTcpServer* server;
    QList<QTcpSocket*> clients;
    quint16 messageSize;
};

#endif // SERVERWINDOW_H
