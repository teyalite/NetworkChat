//
// Created by Abdoulkader Haidara on 01.12.2021.
//

#include "../headers/top_widget.h"

/**
 * The constructor set the widgets and related values
 * It uses some values as default
 * @param parent
 */
TopWidget::TopWidget(QWidget *parent) : QWidget(parent){

    InitialiseWidgets();

    QList<QWidget*> widgets = {_serverLabel, _serverIP, _serverPortLabel, _serverPort, _connectionButton, nullptr, _logo};

    /// add widgets to layout
    for(auto& widget : widgets) {
        if (widget != nullptr) {
            _mainLayout->addWidget(widget);
        } else {
            _mainLayout->addStretch();
        }
    }

    /// set class layout
    setLayout(_mainLayout);

    /// connect connect button with the handler
    QWidget::connect(_connectionButton, SIGNAL(clicked()), this, SLOT(OnConnectionButtonClicked()));
}

void TopWidget::InitialiseWidgets() {
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
}

/**
 * connect button handler
 */
void TopWidget::OnConnectionButtonClicked() {
    /// check if the ip address field is empty
    if (_serverIP->text().isEmpty()) {
        ShowAlert("Server IP address is required to connect");
        return;
    }

    /// check if the port field is empty
    if (_serverPort->text().isEmpty()) {
        ShowAlert("Server Port is required to connect");
        return;
    }

    emit OnConnect(_serverIP->text(), _serverPort->value());
    /// disable button
    _connectionButton->setEnabled(false);
}

/**
 * Alert dialog to display when can't fire sendMessage signal
 * @param message
 */
void TopWidget::ShowAlert(const QString& message) {
    QMessageBox::critical(this, "Window title", message);
}

/**
 * Enable connect button after connected or failed to connect
 */
void TopWidget::EnableConnectButton() {
    _connectionButton->setEnabled(true);
}

/**
 * Get the pointer to the QLineEdit
 * @return
 */
QLineEdit *TopWidget::GetServerIP() {
    return _serverIP;
}

/**
 * Get the pointer to the QSpinBox
 * @return
 */
QSpinBox *TopWidget::GetServerPort() {
    return _serverPort;
}

/**
 * Get the pointer to the QPushButton
 * @return
 */
QPushButton *TopWidget::GetConnectionButton() {
    return _connectionButton;
}
