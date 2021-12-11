//
// Created by Abdoulkader Haidara on 06.12.2021.
//

#include <QtTest/QtTest>
#include <QDebug>
#include <QSignalSpy>
#include "../headers/bottom_widget.h"
#include "../headers/top_widget.h"
#include "../headers/list_widget.h"

class Test: public QObject
{
Q_OBJECT
private slots:
    static void TopTest();
    static void ListTest();
    static void BottomTest();
};

void Test::ListTest() {
    ListWidget listWidget;
    listWidget.AddItem("Hello world !");
    QCOMPARE(listWidget.GetMessageList()->count(), 1);
}

/**
 * Test the top widget server and port and related signals and slots
 */
void Test::TopTest() {
    TopWidget topWidget;
    QSignalSpy spy(&topWidget, SIGNAL(OnConnect(QString, int)));

    /// simulate button click
    topWidget.GetConnectionButton()->click();

    /// check if the signal was emitted after clicking the button
    QCOMPARE(spy.count(), 1);

    QList<QVariant> arguments = spy.takeFirst();

    /// check on connect first argument
    QCOMPARE(arguments.at(0).toString(), "127.0.0.1");

    /// check on connect first second argument
    QCOMPARE(arguments.at(1).toInt(), 50885);

    topWidget.GetServerIP()->clear();
    topWidget.GetServerPort()->clear();

    QTest::keyClicks(topWidget.GetServerIP(), "198.168.0.100");
    QTest::keyClicks(topWidget.GetServerPort(), "60000");

    /// compare username and message after changing values
    QCOMPARE(topWidget.GetServerIP()->text(), QString("198.168.0.100"));
    QCOMPARE(topWidget.GetServerPort()->text(), "60000");

    topWidget.GetConnectionButton()->click();

    /// connection button was not enabled shouldn't be clicked
    QCOMPARE(spy.count(), 0);
}

/**
 * Test the bottom part of the app (message and username)
 */
void Test::BottomTest() {
    BottomWidget bottomWidget;

    QSignalSpy spy(&bottomWidget, SIGNAL(OnSendMessage(const QString)));

    /// file the input field for message and username
    QTest::keyClicks(bottomWidget.GetUsername(), "nickname");
    QTest::keyClicks(bottomWidget.GetMessage(), "message");

    bottomWidget.SetConnected(true);
    bottomWidget.GetSendButton()->click();

    /// check if the signal was emitted after clicking the button
    QCOMPARE(spy.count(), 1);

    QList<QVariant> arguments = spy.takeFirst();

    /// check send message signal argument
    QCOMPARE(arguments.at(0).toString(), "from nickname : message");

    /// compare username and message after send message
    QCOMPARE(bottomWidget.GetUsername()->text(), QString("nickname"));
    QCOMPARE(bottomWidget.GetMessage()->text(), "");

    /// check if the click will emit send message signal
    bottomWidget.GetSendButton()->click();
    QCOMPARE(spy.count(), 0);
}

QTEST_MAIN(Test)
#include "test.moc"