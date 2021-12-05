//
// Created by Abdoulkader Haidara on 01.12.2021.
//

#ifndef CLIENT_LOGO_WIDGET_H
#define CLIENT_LOGO_WIDGET_H

/**
 * The class defined here represents the app name and logo but i was having error with image in qt
 */

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QDir>

class LogoWidget : public QWidget {
public:
    explicit LogoWidget(QWidget *parent = nullptr);

private:
    QString GetPath(QStringList list);

    QVBoxLayout* _container;
    QLabel* _appName;
};

#endif //CLIENT_LOGO_WIDGET_H