#ifndef TESTGUI_H
#define TESTGUI_H

#include <QObject>
#include<QTest>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class TestGui : public QObject
{
    Q_OBJECT
public:
    explicit TestGui(QObject *parent = 0);
//int argc;
//char *argv[];
    MainWindow * w;
    Ui::MainWindow *ui;
signals:

public slots:
private slots:
    void testGuiClick();

};

#endif // TESTGUI_H