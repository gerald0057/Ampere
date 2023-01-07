#include "WindowRemote.h"
#include <QListWidget>
#include <QVBoxLayout>

WindowRemote::WindowRemote()
{
    QListWidget *list = new QListWidget(m_widget);
    list->addItem(QString("ch340"));
    list->addItem(QString("cp2102"));
    list->addItem(QString("Prolific USB-to-Serial Comm Port"));
    list->addItem(QString("Virtual Serial Port (Eltima Softwate)"));

    QVBoxLayout *layout = new QVBoxLayout(m_widget);
    layout->addWidget(list);

    m_btnMaximize->hide();
}
