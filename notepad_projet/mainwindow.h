#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actionsave_as_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPalse_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionNEW_triggered();

    void on_newbuttom_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_undoButton_4_clicked();

    void on_OPENButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QString file_name;
};
#endif // MAINWINDOW_H
