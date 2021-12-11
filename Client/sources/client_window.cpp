//
// Created by Abdoulkader Haidara on 30.11.2021.
//

#include "client_window.h"

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
    SetupSocket();

    /// connect send
    QWidget::connect(_bottomWidget, SIGNAL(OnSendMessage(QString)), this, SLOT(OnSendMessage(QString)));
    /// connecting the onConnect signal to onConnect of the current class
    QWidget::connect(_topWidget, SIGNAL(OnConnect(QString, int)), this, SLOT(OnConnect(QString, int)));

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
void ClientWindow::OnSendMessage(const QString& message) {

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
void ClientWindow::OnConnect(const QString &ip, const int &port) {
    _list->AddItem("Trying to connect to the server....");
    _socket->abort();
    _socket->connectToHost(ip, port);
}

/**
 * When the socket successfully connected to server
 */
void ClientWindow::OnConnected() {
    _list->AddItem("Connected successfully !");
    _bottomWidget->SetConnected(true);
    _topWidget->EnableConnectButton();
}

/**
 * When error happens with the socket
 * @param error
 */
void ClientWindow::OnSocketError(QAbstractSocket::SocketError error) {

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

    _bottomWidget->SetConnected(false);
    _list->AddItem(errorMessage);
    _topWidget->EnableConnectButton();
}

/**
 * Receive data from the server
 */
void ClientWindow::OnReceivedData() {

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

    _list->AddItem(message);

    _messageSize = 0;
}

/**
 * When the user disconnect from the server
 */
void ClientWindow::OnDisconnect() {
    _list->AddItem("Disconnected from the server");
}

/**
 * Setup the socket with signals and slots
 */
void ClientWindow::SetupSocket() {

    _socket = new QTcpSocket(this);

    QWidget::connect(_socket, SIGNAL(readyRead()), this, SLOT(OnReceivedData()));
    QWidget::connect(_socket, SIGNAL(connected()), this, SLOT(OnConnected()));
    QWidget::connect(_socket, SIGNAL(disconnected()), this, SLOT(OnDisconnect()));
    QWidget::connect(_socket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(OnSocketError(QAbstractSocket::SocketError)));

    _messageSize = 0;
}