#include "WindowBase.h"
#include <QApplication>
#include <QGuiApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QList>
#include <QRect>
#include <QTimer>

#include <QVBoxLayout>

#include <QListWidget>
#include <QPushButton>


WindowBase::WindowBase(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint)
{
    m_helper = new FramelessHelper(this);
    m_helper->setDraggableMargins(5, 5, 5, 5);
    m_helper->setMaximizedMargins(0, 0, 0, 0);
    m_helper->setTitleBarHeight(32);

    QPushButton *btn_logo = new QPushButton(this);
    btn_logo->setIcon(QIcon("logo.png"));
    btn_logo->setContentsMargins(0, 0, 0, 0);
    btn_logo->setFixedSize(QSize(60, 24));
    btn_logo->setIconSize(QSize(60, 24));
    btn_logo->setFlat(true);

    m_btnMinimize = new QPushButton(this);
    m_btnMaximize = new QPushButton(this);
    m_btnClose = new QPushButton(this);
    m_btnMinimize->setIcon(QIcon("icon_minimize.svg"));
    m_btnMaximize->setIcon(QIcon("icon_maximize_1.svg"));
    m_btnClose->setIcon(QIcon("icon_close.svg"));

    QHBoxLayout *layout_bar = new QHBoxLayout;
    layout_bar->addWidget(btn_logo);
    layout_bar->addStretch();
    layout_bar->addWidget(m_btnMinimize);
    layout_bar->addWidget(m_btnMaximize);
    layout_bar->addWidget(m_btnClose);
    layout_bar->setContentsMargins(0, 0, 0, 0);

    m_helper->addExcludeItem(m_btnMinimize);
    m_helper->addExcludeItem(m_btnMaximize);
    m_helper->addExcludeItem(m_btnClose);

    connect(m_btnMinimize, &QPushButton::clicked,
            m_helper, &FramelessHelper::triggerMinimizeButtonAction);
    connect(m_btnMaximize, &QPushButton::clicked,
            m_helper, &FramelessHelper::triggerMaximizeButtonAction);
    connect(m_btnClose, &QPushButton::clicked,
            m_helper, &FramelessHelper::triggerCloseButtonAction);
    connect(m_helper, &FramelessHelper::maximizedChanged,
            this, &WindowBase::updateMaximizeButton);

    QVBoxLayout *layout_main = new QVBoxLayout(this);
    m_widget = new QWidget(this);
    layout_main->addLayout(layout_bar);
    layout_main->addWidget(m_widget);
    layout_main->setContentsMargins(5, 5, 5, 5);

    QTimer::singleShot(10, this, SLOT(syncPosition()));
}

void WindowBase::updateMaximizeButton(bool maximized)
{
    if (maximized)
    {
        m_btnMaximize->setIcon(QIcon("icon_maximize_0.svg"));
    }
    else
    {
        m_btnMaximize->setIcon(QIcon("icon_maximize_1.svg"));
    }
}

void WindowBase::syncPosition()
{
    QDesktopWidget *desktop = QApplication::desktop();
    QList <QScreen *> scs= QGuiApplication::screens();
    QRect sc_rect = scs.at(desktop->screenNumber(this))->geometry();
    move((sc_rect.width() - width())/ 2, (sc_rect.height() - height()) /2);

}
