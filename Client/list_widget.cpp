//
// Created by Abdoulkader Haidara on 02.12.2021.
//

#include "list_widget.h"
/**
 * Initialise the widget and set values
 * @param parent
 */
ListWidget::ListWidget(QWidget* parent) : QWidget(parent){
    /// initialisation of widgets and layout
    _messageList = new QListWidget(this);
    _main = new QVBoxLayout;
    _emptyListLabel = new QLabel("No message or notification, connect to the server and start chatting", this);

    /// set the list to hidden if it's empty
    _messageList->hide();
    /// defining props for list empty
    _emptyListLabel->setStyleSheet("font-size: 20px;");
    _emptyListLabel->setAlignment(Qt::AlignCenter);

    /// add widgets to layout
    _main->addWidget(_emptyListLabel);
    _main->addWidget(_messageList);

    /// set the layout of the class
    setLayout(_main);
}

/**
 * called to add new item to the list
 * @param message
 */
void ListWidget::AddItem(const QString& message) {

    /// if the list is hidden, show it
    if (_messageList->isHidden())
        _messageList->show();

    /// if the empty list label is not hidden hide it
    if (!_emptyListLabel->isHidden())
        _emptyListLabel->hide();

    /// add the item to the list
    _messageList->addItem(message);
    _messageList->scrollToBottom();
}