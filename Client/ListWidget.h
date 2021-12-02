//
// Created by Abdoulkader Haidara on 02.12.2021.
//

#ifndef CLIENT_LISTWIDGET_H
#define CLIENT_LISTWIDGET_H

/**
 * This class represents the list that will contain the chat messages
 */
#include <QApplication>
#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QVBoxLayout>

class ListWidget : public QWidget {
    Q_OBJECT
public:
    explicit ListWidget(QWidget* parent = nullptr);
    void addItem(const QString& message);

private:
    QVBoxLayout* _main;
    QListWidget* _messageList;
    QLabel* _emptyListLabel;
};

#endif //CLIENT_LISTWIDGET_H
