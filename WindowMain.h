#ifndef WINDOWMAIN_H
#define WINDOWMAIN_H

#include "WindowBase.h"
#include <QWidget>

#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTableWidget>
#include <QListWidget>
#include <QTabWidget>
#include <QMenu>
#include <QGroupBox>
#include <QCheckBox>
#include <QPoint>
#include <QAction>

class WindowMain : public WindowBase
{
    Q_OBJECT

public:
    explicit WindowMain(WindowBase *parent = nullptr);

private slots:
    void onBtnPoped(void);
    void onProbed(void);

private:
    QPushButton *m_btnRemote;
    QTabWidget *m_tab;

    QWidget *initPagePrinter(void);
    QWidget *initPageSetting(void);
};

#endif // WINDOWMAIN_H
