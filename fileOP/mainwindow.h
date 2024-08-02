#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QtDebug>
//QtDebug用于调试在控制台输出结果，使用方式类似c++，qDebug<<***。
#include <QKeyEvent>
#include <QMouseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *k);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void newActionslots();
    void openActionslots();
    void saveActionslots();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
