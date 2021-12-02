//
// Created by Abdoulkader Haidara on 01.12.2021.
//

#include "TopWidget.h"

/**
 * The constructor set the widgets and related values
 * It uses some values as default
 * @param parent
 */
TopWidget::TopWidget(QWidget *parent) : QWidget(parent){

    /// initialisation of layout and widgets
    _mainLayout = new QHBoxLayout;
    _serverIP = new QLineEdit;
    _serverLabel = new QLabel("Server IP address");
    _serverPortLabel = new QLabel("Port :");
    _serverPort = new QSpinBox;
    _connectionButton = new QPushButton("Connect");
    _logo = new LogoWidget(this);

    /// set values for server ip
    _serverIP->setPlaceholderText("IP address");
    _serverIP->setMaximumWidth(150);
    _serverIP->setMinimumWidth(150);
    _serverIP->setText("127.0.0.1");
    _serverIP->clearFocus();

    /// set values for sever port
    _serverPortLabel->setContentsMargins(20, 0, 5, 0);
    _serverPort->setMaximum(65535);
    _serverPort->setValue(50885);
    _serverPort->setMaximumWidth(80);
    _serverPort->setMinimumWidth(80);

    /// add widgets to layout
    _mainLayout->addWidget(_serverLabel);
    _mainLayout->addWidget(_serverIP);
    _mainLayout->addWidget(_serverPortLabel);
    _mainLayout->addWidget(_serverPort);
    _mainLayout->addWidget(_connectionButton);
    _mainLayout->addStretch();
    _mainLayout->addWidget(_logo);

    /// set class layout
    setLayout(_mainLayout);

    /// connect connect button with the handler
    QWidget::connect(_connectionButton, SIGNAL(clicked()), this, SLOT(onConnectionButtonClicked()));
}

/**
 * connect button handler
 */
void TopWidget::onConnectionButtonClicked() {
    /// check if the ip address field is empty
    if (_serverIP->text().isEmpty()) {
        showAlert("Server IP address is required to connect");
        return;
    }

    /// check if the port field is empty
    if (_serverPort->text().isEmpty()) {
        showAlert("Server Port is required to connect");
        return;
    }

    emit onConnect(_serverIP->text(), _serverPort->value());
    /// disable button
    _connectionButton->setEnabled(false);
}

/**
 * Alert dialog to display when can't fire sendMessage signal
 * @param message
 */
void TopWidget::showAlert(const QString& message) {
    QMessageBox::critical(this, "Window title", message);
}

/**
 * Enable connect button after connected or failed to connect
 */
void TopWidget::enableConnectButton() {
    _connectionButton->setEnabled(true);
}
