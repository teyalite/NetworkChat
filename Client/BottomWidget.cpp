//
// Created by Abdoulkader Haidara on 01.12.2021.
//

#include "BottomWidget.h"

/**
 * Unique constructor for the class and set widgets settings
 * @param parent
 */
BottomWidget::BottomWidget(QWidget *parent) : QWidget(parent) {

    /// initialisation of layout and widgets
    _mainLayout = new QHBoxLayout;
    _sendButton = new QPushButton("Send message");
    _username = new QLineEdit;
    _usernameLabel = new QLabel("Username :");
    _message = new QLineEdit;
    _messageLabel = new QLabel("Message :");

    /// defining style properties for widgets
    _sendButton->setContentsMargins(10, 10, 10, 40);
    _username->setMinimumSize(100, 30);
    _username->setMaximumSize(100, 30);
    _message->setMinimumSize(100, 30);
    _message->setFocus();
    _messageLabel->setContentsMargins(20, 0, 10, 0);

    /// add widgets to layout
    _mainLayout->addWidget(_usernameLabel);
    _mainLayout->addWidget(_username);
    _mainLayout->addWidget(_messageLabel);
    _mainLayout->addWidget(_message);
    _mainLayout->addWidget(_sendButton);

    /// set the class layout
    setLayout(_mainLayout);

    /// connect widget signals to slots
    QWidget::connect(_sendButton, SIGNAL(clicked()), this, SLOT(onSendButtonClicked()));
    QWidget::connect(_message, SIGNAL(returnPressed()), this, SLOT(onSubmitMessage()));
}

/**
 * this slot is called when user click on send message button
 */
void BottomWidget::onSendButtonClicked() {
    //// check if username is empty
    if (_username->text().isEmpty()) {
        showAlert("User name empty");
        return;
    }

    /// if the message is empty stop precessing
    if (_message->text().isEmpty())
        return;

    /// if the user is not connected
    if (!_isConnected) {
        showAlert("You are not connected, connect to a server to start chatting");
        return;
    }

    /// emit the signal sendMessage with the user name and message content
    emit onSendMessage("from " + _username->text() + " : " + _message->text());

    /// clear message input content and set focus
    _message->clear();
    _message->setFocus();
}

/**
 * this slot is called when enter button is clicked while typing inside the message area
 */
void BottomWidget::onSubmitMessage() {
    onSendButtonClicked();
}

/**
 * Alert dialog to display when can't fire sendMessage signal
 * @param message
 */
void BottomWidget::showAlert(const QString& message) {
    QMessageBox::critical(this, "Window title", message);
}

/**
 * set the connected state to if user is connected or not
 * @param value
 */
void BottomWidget::setConnected(bool value) {
    _isConnected = value;
}
