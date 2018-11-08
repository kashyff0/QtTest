#include <QtTest>
#include "testgui.h"
#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QtTest/QtTest>

TestGui::TestGui(QObject *parent) : QObject(parent)
{
    w = (MainWindow *) QApplication::activeWindow();
    ui = w->ui;

}

void TestGui::testEncodeDecode()
{

   qDebug() << "Starting testEncodeDecode";
   QString text1 = "kashif";
   QString text2 =  w->encodeBase64(text1);
   QString text3 = w->decodeBase64(text2);

   QVERIFY2(text3 ==  text1, "Fail");
   qDebug() << "finished testEncodeDecode";
   QTest::qSleep(1000);
}
void TestGui::testGui()
{
    qDebug() << "Starting testGui";
    QPushButton *p1 = ui->pushButton;
    QPushButton *p2 =ui->pushButton_2;
    QLineEdit *le = ui->lineEdit;
    QString testStr = "A Randm Text";
    le->clear();
    QTest::keyClicks(le,testStr);
    QString leText = le->text();
     QTest::qSleep(1000);
    QVERIFY2(leText == testStr,"Line Edit set text not working");
    QTest::mouseClick(p1,Qt::LeftButton);
    QString leText2 = le->text();
    QVERIFY2(leText != leText2,"set encoded not working");
    QTest::mouseClick(p2,Qt::LeftButton);
    QString leText3 = le->text();
    QCOMPARE(leText3 ,leText);
   qDebug() << "Finished testGui";
   QTest::qSleep(1000);
}
void TestGui::init()
{
    qDebug() << "====I N I T I A L I Z I N G====";
}



void TestGui::testGui2()
{

    QFETCH(QString,Str);
    QFETCH(QString,B64Encoded);
    QFETCH(QString,B64Decoded);
    QPushButton *p1 = ui->pushButton;
    QPushButton *p2 =ui->pushButton_2;
    QLineEdit *le = ui->lineEdit;
    le->clear();
    QTest::keyClicks(le,Str);
     QTest::qSleep(1000);
    QTest::mouseClick(p1,Qt::LeftButton);
    QString enc = le->text();
    QCOMPARE(enc ,B64Encoded );
    QTest::mouseClick(p2,Qt::LeftButton);
    QString dec = le->text();
    QCOMPARE(dec , Str);
    QTest::qSleep(1500);
}
void TestGui::testGui2_data()
{
    QTest::addColumn<QString>("Str");
    QTest::addColumn<QString>("B64Encoded");
    QTest::addColumn<QString>("B64Decoded");
    QTest::newRow("1") <<  "quick" << "cXVpY2s=" << "quick";
    QTest::newRow("2") <<  "Brown" << "QnJvd24=" << "Brown";
    QTest::newRow("3") <<  "Fox" << "Rm94" << "Fox";
    QTest::newRow("4") <<  "Jumps" << "SnVtcHM=" << "Jumps";
    QTest::newRow("5") <<  "over" << "b3Zlcg==" << "over";
    QTest::newRow("6") <<  "The" << "VGhl" << "The";
    QTest::newRow("7") <<  "lazy" << "bGF6eQ==" << "lazy";
    QTest::newRow("8") <<  "dog" << "ZG9n" << "dog";
    QTest::newRow("9") <<  "A quick brown fox" << "QSBxdWljayBicm93biBmb3g=" << "A quick brown fox";
}
//#include "testgui.moc"

