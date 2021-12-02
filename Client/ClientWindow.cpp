//
// Created by Abdoulkader Haidara on 30.11.2021.
//

#include "ClientWindow.h"

/**
 * Unique constructor for the class it initialises widgets, layout and the socket
 */
ClientWindow::ClientWindow() : QWidget() {

    setWindowTitle("Network Chat Client");
    setMinimumSize(700, 700);

    /// initialisation of layout and widgets
    _mainLayout = new QVBoxLayout(this);
    _topWidget = new TopWidget(this);
    _bottomWidget = new BottomWidget(this);
    _list = new ListWidget(this);

    /// prepare the socket
    setupSocket();

    /// connect send
    QWidget::connect(_bottomWidget, SIGNAL(onSendMessage(QString)), this, SLOT(onSendMessage(QString)));
    /// connecting the onConnect signal to onConncet of the current class
    QWidget::connect(_topWidget, SIGNAL(onConnect(QString, int)), this, SLOT(onConnect(QString, int)));

    /// add widget to main layout
    _mainLayout->addWidget(_topWidget);
    _mainLayout->addWidget(_list,  1);
    _mainLayout->addWidget(_bottomWidget);

    /// set the layout for the class
    setLayout(_mainLayout);
}

/**
 * Slot to call when onSendMessage of bottom message happens
 * @param message
 */
void ClientWindow::onSendMessage(const QString& message) {

    QByteArray packet;
    QDataStream out(&packet, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << message;

    out.device()->seek(0);
    out << (quint16) (packet.size() - sizeof(quint16));

    _socket->write(packet);
}

/**
 * Slot to call when Top widget onConnect signal fires
 * @param ip
 * @param port
 */
void ClientWindow::onConnect(const QString &ip, const int &port) {
    _list->addItem("Trying to connect to the server....");
    _socket->abort();
    _socket->connectToHost(ip, port);
}

/**
 * When the socket successfully connected to server
 */
void ClientWindow::onConnected() {
    _list->addItem("Connected successfully !");
    _bottomWidget->setConnected(true);
    _topWidget->enableConnectButton();
}

/**
 * When error happens with the socket
 * @param error
 */
void ClientWindow::onSocketError(QAbstractSocket::SocketError error) {

    QString errorMessage;

    switch(error) {
        case QAbstractSocket::HostNotFoundError:
            errorMessage = "Server not found, check ip address or port number";
            break;

        case QAbstractSocket::ConnectionRefusedError:
            errorMessage = "Connection rejected, check if the server is running, check ip address or port number";
            break;

        case QAbstractSocket::RemoteHostClosedError:
            errorMessage = "Error, server has turned or the connection";
            break;

        default:
            errorMessage = "Error ! " + _socket->errorString();
    }

    _bottomWidget->setConnected(false);
    _list->addItem(errorMessage);
    _topWidget->enableConnectButton();
}

/**
 * Receive data from the server
 */
void ClientWindow::receivedData() {

    QDataStream in(_socket);

    if (_messageSize == 0) {

        if (_socket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> _messageSize;
    }

    if (_socket->bytesAvailable() < _messageSize)
        return;

    QString message;

    in >> message;

    _list->addItem(message);

    _messageSize = 0;
}

/**
 * When the user disconnect from the server
 */
void ClientWindow::onDisconnect() {
    _list->addItem("Disconnected from the server");
}

/**
 * Setup the socket with signals and slots
 */
void ClientWindow::setupSocket() {

    _socket = new QTcpSocket(this);

    connect(_socket, SIGNAL(readyRead()), this, SLOT(receivedData()));
    connect(_socket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(_socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()));
    connect(_socket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));

    _messageSize = 0;
}