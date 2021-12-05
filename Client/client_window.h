//
// Created by Abdoulkader Haidara on 30.11.2021.
//

#ifndef CLIENT_CLIENT_WINDOW_H
#define CLIENT_CLIENT_WINDOW_H

/**
 * Main client window it displays all necessary widgets for the app
 */
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QtNetwork/QTcpSocket>
#include "bottom_widget.h"
#include "top_widget.h"
#include "list_widget.h"

class ClientWindow : public QWidget {
    Q_OBJECT
public:
    ClientWindow();

private slots:
    void OnConnect(const QString& ip, const int& port);
    void OnSendMessage(const QString& message);
    void OnConnected();
    void OnReceivedData();
    void OnDisconnect();
    void OnSocketError(QAbstractSocket::SocketError error);

private:
    void SetupSocket();

    quint16 _messageSize {};
    QTcpSocket* _socket {};
    QVBoxLayout* _mainLayout;
    TopWidget* _topWidget;
    BottomWidget* _bottomWidget;
    ListWidget* _list;
};

#endif //CLIENT_CLIENT_WINDOW_H
