//
// Created by Abdoulkader Haidara on 02.12.2021.
//

#ifndef CLIENT_LIST_WIDGET_H
#define CLIENT_LIST_WIDGET_H

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
    void AddItem(const QString& message);
    /// the following method will be used during tests
    QListWidget* GetMessageList();

private:
    QVBoxLayout* _main;
    QListWidget* _messageList;
    QLabel* _emptyListLabel;
};

#endif //CLIENT_LIST_WIDGET_H
