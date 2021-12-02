//
// Created by Abdoulkader Haidara on 01.12.2021.
//

#ifndef CLIENT_TOPWIDGET_H
#define CLIENT_TOPWIDGET_H

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
#include "LogoWidget.h"

class TopWidget : public QWidget {
Q_OBJECT
public:
    explicit TopWidget(QWidget* parent = nullptr);
    void enableConnectButton();

private slots:
    void onConnectionButtonClicked();

signals:
    void onConnect(const QString& ip, const int& port);

private:
    void showAlert(const QString& message);

    QHBoxLayout* _mainLayout;
    QLineEdit* _serverIP;
    QLabel* _serverLabel;
    QSpinBox* _serverPort;
    QLabel* _serverPortLabel;
    QPushButton* _connectionButton;
    LogoWidget* _logo;
};

#endif //CLIENT_TOPWIDGET_H
