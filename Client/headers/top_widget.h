//
// Created by Abdoulkader Haidara on 01.12.2021.
//

#ifndef CLIENT_TOP_WIDGET_H
#define CLIENT_TOP_WIDGET_H

/**
 * The class defined here is the top widget of the app
 * it contains the server data
 * and the app logo
 */

#include <QApplication>
#include <QWidget>
#include <QSpinBox>
#include <QPushButton>
#include <QListWidget>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include "logo_widget.h"

class TopWidget : public QWidget {
Q_OBJECT
public:
    explicit TopWidget(QWidget* parent = nullptr);
    void EnableConnectButton();
    /// the following methods will be used during tests
    QLineEdit* GetServerIP();
    QSpinBox* GetServerPort();
    QPushButton* GetConnectionButton();

private slots:
    void OnConnectionButtonClicked();

signals:
    void OnConnect(const QString& ip, const int& port);

private:
    void ShowAlert(const QString& message);
    void InitialiseWidgets();

    QHBoxLayout* _mainLayout{};
    QLineEdit* _serverIP{};
    QLabel* _serverLabel{};
    QSpinBox* _serverPort{};
    QLabel* _serverPortLabel{};
    QPushButton* _connectionButton{};
    LogoWidget* _logo{};
};

#endif //CLIENT_TOP_WIDGET_H
