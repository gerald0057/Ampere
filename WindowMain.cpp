#include "WindowMain.h"
#include "WindowRemote.h"

WindowMain::WindowMain(WindowBase *parent)
{
    Q_UNUSED(parent)

    m_btnRemote = new QPushButton("remote", m_widget);
    connect(m_btnRemote, SIGNAL(clicked()), this, SLOT(onBtnPoped()));

    m_tab = new QTabWidget(m_widget);
    m_tab->addTab(initPagePrinter(), "Printer");
    m_tab->addTab(initPageSetting(), "Setting");

    QListWidget *list = new QListWidget(m_widget);
    list->addItem(QString("Motor"));
    list->addItem(QString("Printer"));

    QGridLayout *layout = new QGridLayout(m_widget);
    layout->addWidget(m_tab, 0, 0);
    layout->addWidget(list, 0, 1);
    layout->setColumnStretch(0, 3);
    layout->setColumnStretch(1, 1);
    QHBoxLayout *l = new QHBoxLayout;
    l->addWidget(m_btnRemote);
    l->addStretch();
    layout->addLayout(l, 1, 0);
    layout->setContentsMargins(5, 5, 5, 5);

    setMinimumSize(QSize(800, 600));
}

void WindowMain::onBtnPoped()
{
    QMenu *menu = new QMenu(this);
    QPoint pos = m_btnRemote->mapToGlobal(QPoint(0, 0));
    QMenu *menu_conn = new QMenu("connect", this);
    menu_conn->addAction(new QAction("CH340", menu_conn));
    menu_conn->addAction(new QAction("CP2102", menu_conn));
    menu_conn->addAction(new QAction("STMicro", menu_conn));
    menu->addMenu(menu_conn);
    QAction *action_probe = new QAction("probe", menu);
    connect(action_probe, SIGNAL(triggered()), this, SLOT(onProbed()));
    menu->addAction(action_probe);
    menu->addAction(new QAction("restart", menu));
    menu->exec(QPoint(pos.x(), pos.y() - menu->sizeHint().height()));
}

void WindowMain::onProbed()
{
    WindowRemote *remote = new WindowRemote;
    remote->show();
}

QWidget *WindowMain::initPagePrinter()
{
    QWidget *page = new QWidget(m_widget);

    QPushButton *btnOpenFile = new QPushButton("Open", page);

    QVBoxLayout *layout_main = new QVBoxLayout(page);
    layout_main->addWidget(btnOpenFile);
    layout_main->addStretch();

    return page;
}

QWidget *WindowMain::initPageSetting()
{
    QWidget *page = new QWidget(m_widget);

    QGroupBox *box_0 = new QGroupBox("General", page);
    QVBoxLayout *box_0_layout = new QVBoxLayout(box_0);
    QCheckBox *cbox_autoconn = new QCheckBox("Auto Connect");
    box_0_layout->addWidget(cbox_autoconn);

    QVBoxLayout *layout_main = new QVBoxLayout(page);
    layout_main->addWidget(box_0);
    layout_main->addStretch();

    return page;
}
