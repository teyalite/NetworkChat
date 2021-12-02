//
// Created by Abdoulkader Haidara on 01.12.2021.
//

#ifndef CLIENT_LOGOWIDGET_H
#define CLIENT_LOGOWIDGET_H

/**
 * The class defined here represents the app logo and logo text
 */

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class LogoWidget : public QWidget {
public:
    explicit LogoWidget(QWidget *parent = nullptr);
private:
    QVBoxLayout* _container;
    QLabel* _appName;
    QLabel* _appLogo;
};

#endif //CLIENT_LOGOWIDGET_H