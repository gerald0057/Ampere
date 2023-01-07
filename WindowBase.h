#ifndef WINDOWBASE_H
#define WINDOWBASE_H

#include <QWidget>
#include <QPushButton>
#include "FramelessHelper.h"
#include "framelessbar.h"

class WindowBase : public QWidget
{
    Q_OBJECT
public:
    explicit WindowBase(QWidget *parent = nullptr);

signals:

public slots:
    void updateMaximizeButton(bool maximized);
    void syncPosition(void);

protected:
    QWidget *m_widget;
    QPushButton *m_btnMinimize, *m_btnMaximize, *m_btnClose;
    FramelessHelper *m_helper;
    FramelessBar *m_bar;

private:
};

#endif // WINDOWBASE_H
