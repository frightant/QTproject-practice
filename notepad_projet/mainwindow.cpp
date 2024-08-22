#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionopen_triggered()
{
    QString file_open = QFileDialog::getOpenFileName(
        this,  // 父窗口指针
        "Open the file",  // 对话框标题
        "",  // 初始目录
        "txt Files (*.txt);;All Files (*)"  // 文件过滤器
    );
    QFile file(file_open);
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"warning","file not open!");
        return;
    }
    file_name = file_open;
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionsave_triggered()
{
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly |QFile::Text)){
        QMessageBox::warning(this,"warning","file not save!");
        return;
    }
    QTextStream out(&file);
    QString text =  ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionsave_as_triggered()
{
    QString file_open = QFileDialog::getSaveFileName(this,"save as the file");
    QFile file(file_open);
    if(!file.open(QFile::WriteOnly |QFile::Text)){
        QMessageBox::warning(this,"warning","file not save!");
        return;
    }
    file_name = file_open;
    QTextStream out(&file);
    QString text =  ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPalse_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionNEW_triggered()
{
    file_name = "";
    ui->textEdit->setText("");
}

void MainWindow::on_newbuttom_clicked()
{
    file_name = "";
    ui->textEdit->setText("");
}

void MainWindow::on_pushButton_clicked()
{
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly |QFile::Text)){
        QMessageBox::warning(this,"warning","file not save!");
        return;
    }
    QTextStream out(&file);
    QString text =  ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit->redo();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString file_open = QFileDialog::getSaveFileName(this,"save as the file");
    QFile file(file_open);
    if(!file.open(QFile::WriteOnly |QFile::Text)){
        QMessageBox::warning(this,"warning","file not save!");
        return;
    }
    file_name = file_open;
    QTextStream out(&file);
    QString text =  ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_undoButton_4_clicked()
{
    ui->textEdit->undo();
}

void MainWindow::on_OPENButton_4_clicked()
{
    QString file_open = QFileDialog::getOpenFileName(
        this,  // 父窗口指针
        "Open the file",  // 对话框标题
        "",  // 初始目录
        "txt Files (*.txt);;All Files (*)"  // 文件过滤器
    );
    QFile file(file_open);
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"warning","file not open!");
        return;
    }
    file_name = file_open;
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}
