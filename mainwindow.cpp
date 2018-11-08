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

connect (ui->pushButton_3,SIGNAL(clicked(bool)),this, SLOT(liveTest()));

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
    QString res;
    QString result = b.toBase64();
    res = QString("Base64 encode of %1 is %2"). arg(text).arg(result);

    ui->textEdit->setText(ui->textEdit->toPlainText()+ "\n" + res );
   return  b.toBase64();

}

QString MainWindow::decodeBase64(QString text)
{
    if(text.isEmpty())
        return text;
    QByteArray b;
    b = b.append(text);
    b = QByteArray::fromBase64(b);
    QString result = b;
    QString res = QString("Base64 decode  of %1 is %2"). arg(text).arg(result);

    ui->textEdit->setText(ui->textEdit->toPlainText() + "\n" + res );
    return b;
}

void MainWindow::slotDecode()
{
    QString text = ui->lineEdit->text();
    QString text2=decodeBase64(text);
    ui->lineEdit->setText(text2);
}
void MainWindow::liveTest()
{
      QTimer::singleShot(2000, this, SLOT(update()));
}
