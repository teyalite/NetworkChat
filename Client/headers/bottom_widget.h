//
// Created by Abdoulkader Haidara on 01.12.2021.
//

#ifndef CLIENT_BOTTOM_WIDGET_H
#define CLIENT_BOTTOM_WIDGET_H

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
#include <QList>

class BottomWidget : public QWidget {
Q_OBJECT
public:
    explicit BottomWidget(QWidget* parent = nullptr);
    void SetConnected(bool value);
    /// The following methods will be used during testing
    QLineEdit* GetUsername();
    QPushButton* GetSendButton();
    QLineEdit* GetMessage();

private slots:
    void OnSendButtonClicked();
    void OnSubmitMessage();

signals:
    void OnSendMessage(const QString& message);

private:
    void ShowAlert(const QString& message);
    void InitialiseWidgets();

    QHBoxLayout* _mainLayout{};
    QPushButton* _sendButton{};
    QLineEdit* _username{};
    QLabel* _usernameLabel{};
    QLineEdit* _message{};
    QLabel* _messageLabel{};
    bool _isConnected = false;
};

#endif //CLIENT_BOTTOM_WIDGET_H
