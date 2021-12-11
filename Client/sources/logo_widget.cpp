//
// Created by Abdoulkader Haidara on 01.12.2021.
//

#include "../headers/logo_widget.h"
#include <QDebug>

/**
 * Initialise the widget that will be displayed
 * @param parent
 */
LogoWidget::LogoWidget(QWidget *parent) : QWidget(parent) {
    /// initialisation of the layout and widgets
    _container = new QVBoxLayout(this);
    _appName = new QLabel("Network Chat");

    _appName->setStyleSheet("font-size: 20px;");

    _container->addWidget(_appName);

    setLayout(_container);
}

/**
 * Get the path of the current directory
 * @param list
 * @return
 */
QString LogoWidget::GetPath(QList<QString> list) {

    if (list.empty())
        return "";

    if (list[list.size() - 1] == "Client")
        return list.join('/');

    list.pop_back();

    return GetPath(list);
}
