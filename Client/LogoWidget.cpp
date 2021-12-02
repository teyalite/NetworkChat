//
// Created by Abdoulkader Haidara on 01.12.2021.
//

#include "LogoWidget.h"
#include <QDebug>

/**
 * Initialise the widget that will be displayed
 * @param parent
 */
LogoWidget::LogoWidget(QWidget *parent) : QWidget(parent) {
    /// initialisation of the layout and widgets
    _container = new QVBoxLayout(this);
    _appLogo = new QLabel;
    _appName = new QLabel("Network Chat");

    qInfo() << QDir::currentPath();

    /// setting app logo
    _appLogo->setStyleSheet("background-color:red;");
    _appLogo->setMaximumSize(80, 80);
    _appLogo->setMinimumSize(80, 80);

    /// add widget to container layout
    _container->addWidget(_appLogo);
    _container->addWidget(_appName);

    setLayout(_container);
}