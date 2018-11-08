#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class TestGui;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
friend class TestGui;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
QString encodeBase64(QString text);
QString decodeBase64(QString text);
private slots:
    void on_pushButton_clicked();
    void slotDecode();
void update();
private:
    Ui::MainWindow *ui;
    int i=0;
};

#endif // MAINWINDOW_H
