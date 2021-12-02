//
// Created by Abdoulkader Haidara on 30.11.2021.
//

#ifndef CLIENT_CLIENTWINDOW_H
#define CLIENT_CLIENTWINDOW_H

/**
 * Main client window it displays all necessary widgets for the app
 */
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QtNetwork/QTcpSocket>
#include "BottomWidget.h"
#include "TopWidget.h"
#include "ListWidget.h"

class ClientWindow : public QWidget {
    Q_OBJECT
public:
    ClientWindow();

private slots:
    void onConnect(const QString& ip, const int& port);
    void onSendMessage(const QString& message);
    void onConnected();
    void receivedData();
    void onDisconnect();
    void onSocketError(QAbstractSocket::SocketError error);

private:
    void setupSocket();

    quint16 _messageSize {};
    QTcpSocket* _socket {};
    QVBoxLayout* _mainLayout;
    TopWidget* _topWidget;
    BottomWidget* _bottomWidget;
    ListWidget* _list;
};

#endif //CLIENT_CLIENTWINDOW_H
