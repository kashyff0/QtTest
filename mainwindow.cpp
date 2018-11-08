#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include <testgui.h>
#include <QTimer>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




connect (ui->pushButton_2,SIGNAL(clicked(bool)),this, SLOT(slotDecode()));

  QTimer::singleShot(2000, this, SLOT(update()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    QString text2=encodeBase64(text);
    ui->lineEdit->setText(text2);
}
void MainWindow::update()
{
     TestGui *tg = new TestGui();
    QTest::qExec(tg);

}
QString MainWindow::encodeBase64(QString text)
{
    if(text.isEmpty())
        return text;
    QByteArray b;
    b.append(text);
   return  b.toBase64();

}

QString MainWindow::decodeBase64(QString text)
{
    if(text.isEmpty())
        return text;
    QByteArray b;
    b = b.append(text);
    b = QByteArray::fromBase64(b);
    return b;
}

void MainWindow::slotDecode()
{
    QString text = ui->lineEdit->text();
    QString text2=decodeBase64(text);
    ui->lineEdit->setText(text2);
}
