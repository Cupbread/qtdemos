#pragma once

#include <QtWidgets/QMainWindow>

#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QEvent>
#include "ui_myeventdemo.h"

#define MY_BTN_EVENT QEvent::Type(QEvent::User+53)

class MyEventDemo : public QMainWindow
{
    Q_OBJECT

public:
    MyEventDemo(QWidget *parent = Q_NULLPTR);

    void initFrame();
    void initConnect();
    void customEvent(QEvent* event);

private slots:
    void pushButtonClick();
    void addCount();

private:
    Ui::MyEventDemoClass ui;

    QWidget* m_pCentralWidget;
    QPushButton* m_pPushButton;
    QLabel* m_pLabel;
    QVBoxLayout* m_pVLayout;

    QTimer timer;
    int count;
};
