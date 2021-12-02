//
// Created by Abdoulkader Haidara on 29.11.2021.
//

#include "ServerWindow.h"

ServerWindow::ServerWindow() : QWidget()
{
    _serverState = new QLabel;
    _serverState->setAlignment(Qt::AlignCenter);

    _quitButton = new QPushButton("Stop server");

    QWidget::connect(_quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    auto *layout = new QVBoxLayout(this);

    layout->addWidget(_serverState, Qt::AlignCenter);
    layout->addWidget(_quitButton,  Qt::AlignCenter);

    setWindowTitle("Server manager");

    _server = new QTcpServer;

    /// start server to listen to port number 50885
    if (!_server->listen(QHostAddress::Any, 50885)) {
        /// something went wrong while trying to start the servert
        _serverState->setText(tr("Server couldn't start for the following reason: <br/>") + _server->errorString());

    } else {
        /// server running
        _serverState->setText(tr("The server is running on the port <strong>")
                              + QString::number(_server->serverPort())
                              + tr("</strong>.<br/>Clients can connect now."));

        /// connect new connection of server to new client slot
        QWidget::connect(_server, SIGNAL(newConnection()), this, SLOT(newClient()));
    }

    /// initialize message size to 0
    _messageSize = 0;
}

void ServerWindow::newClient() {

    /// send a message to all cliens
    sendToAll("A new client has got connected");

    QTcpSocket *new_client = _server->nextPendingConnection();

    /// add new client to the list of clients
    _clients << new_client;

    /// connect new client ready to read to received data slot
    QWidget::connect(new_client, SIGNAL(readyRead()), this, SLOT(receivedData()));
    /// connect new client disconnection to disconnect client slot
    QWidget::connect(new_client, SIGNAL(disconnected()), this, SLOT(disconnectClient()));
}

void ServerWindow::receivedData() {
    auto* socket = qobject_cast<QTcpSocket*>(sender());

    if (socket == nullptr)
        return;

    QDataStream in(socket);

    if (_messageSize == 0) {

        if (socket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> _messageSize;
    }

    if (socket->bytesAvailable() < _messageSize)
        return;

    QString message;

    in >> message;

    sendToAll(message);

    _messageSize = 0;
}

/**
 * Send message to all client that are connected
 * @param message
 */
void ServerWindow::sendToAll(const QString &message) {

    QByteArray frame;
    QDataStream out(&frame, QIODevice::WriteOnly);
    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16) (frame.size() - sizeof(quint16));

    for (auto & _client : _clients)
        _client->write(frame);

}

void ServerWindow::disconnectClient() {
    sendToAll("notification: A client got disconnected");

    auto *socket = qobject_cast<QTcpSocket *>(sender());

    if (socket == nullptr)
        return;

    _clients.removeOne(socket);
    socket->deleteLater();
}