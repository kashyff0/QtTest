#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include <testgui.h>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



       QTimer::singleShot(2000, this, SLOT(update()));




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{i++;
    qDebug() << "Gotcha";

    int x = rand() % width();
     int y = rand() % height();
     ui->pushButton->move(x,y);
}
void MainWindow::update()
{
     TestGui *tg = new TestGui();
    QTest::qExec(tg);

}


