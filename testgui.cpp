#include <QtTest>
#include "testgui.h"
#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"
#include <QPushButton>

TestGui::TestGui(QObject *parent) : QObject(parent)
{
    w = (MainWindow *) QApplication::activeWindow();
    ui = w->ui;

}

void TestGui::testGuiClick()
{

   QPushButton *p = ui->pushButton;
   int x = p->x();
   QTest::mouseClick(p,Qt::LeftButton);
    QVERIFY2(x != p->x(), "window not set");
}

//#include "testgui.moc"
