#include "myeventdemo.h"

MyEventDemo::MyEventDemo(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    timer.setInterval(1000);
    initFrame();
    initConnect();
}

void MyEventDemo::initFrame()
{
    m_pCentralWidget = new QWidget(this);
	setCentralWidget(m_pCentralWidget);

    m_pVLayout = new QVBoxLayout(this);
    m_pPushButton = new QPushButton();
    m_pLabel = new QLabel("123");

    m_pVLayout->addWidget(m_pLabel, 5);
    m_pVLayout->addWidget(m_pPushButton, 5);

    m_pCentralWidget->setLayout(m_pVLayout);
}

void MyEventDemo::initConnect()
{
    (void)connect(m_pPushButton, &QPushButton::clicked, this, &MyEventDemo::pushButtonClick);
    (void)connect(&timer, &QTimer::timeout, this, &MyEventDemo::addCount);
}

void MyEventDemo::pushButtonClick()
{
    count = 0;
    timer.start();
}

void MyEventDemo::addCount()
{
    count++;
    m_pLabel->setText(QString::number(count));

    if (count == 5)
    {
        timer.stop();
        count = 0;
        QApplication::postEvent(this, new QEvent(MY_BTN_EVENT));
    }
}

void MyEventDemo::customEvent(QEvent* event)
{
    if (event->type() == MY_BTN_EVENT)
    {
        m_pLabel->setText("time out");
    }
}
