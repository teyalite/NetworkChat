//
// Created by Abdoulkader Haidara on 29.11.2021.
//

#ifndef NETWORKCHAT_SERVERWINDOW_H
#define NETWORKCHAT_SERVERWINDOW_H

#include <QWidget>
#include <QObject>
#include <QApplication>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QList>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QtNetwork/QHostAddress>
#include <QString>
#include <QDebug>

class ServerWindow : public QWidget
{
Q_OBJECT
public:
    ServerWindow();
    void sendToAll(const QString &message);

public slots:
    void newClient();
    void receivedData();
    void disconnectClient();

private:
    QLabel* _serverState;
    QPushButton* _quitButton;
    QTcpServer* _server;
    QList<QTcpSocket*> _clients;
    quint16 _messageSize;
};

#endif //NETWORKCHAT_SERVERWINDOW_H
