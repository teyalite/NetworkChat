//
// Created by Abdoulkader Haidara on 01.12.2021.
//

#ifndef CLIENT_BOTTOMWIDGET_H
#define CLIENT_BOTTOMWIDGET_H

/**
 * This class represent the bottom widget that manage the message and username
 */

#include <QApplication>
#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QtNetwork/QTcpSocket>

class BottomWidget : public QWidget {
Q_OBJECT
public:
    explicit BottomWidget(QWidget* parent = nullptr);
    void setConnected(bool value);

private slots:
    void onSendButtonClicked();
    void onSubmitMessage();

signals:
    void onSendMessage(const QString& message);

private:
    void showAlert(const QString& message);

    QHBoxLayout* _mainLayout;
    QPushButton* _sendButton;
    QLineEdit* _username;
    QLabel* _usernameLabel;
    QLineEdit* _message;
    QLabel* _messageLabel;
    bool _isConnected = false;
};

#endif //CLIENT_BOTTOMWIDGET_H
