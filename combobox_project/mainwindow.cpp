#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem(QIcon(":/picture/1.png"),"美女1");
    ui->comboBox->addItem(QIcon(":/picture/2.png"),"美女22");
    ui->comboBox->addItem(QIcon(":/picture/3.png"),"美女333");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked()){
        QMessageBox::information(this,"message",ui->comboBox->currentText());
    }else{
        QMessageBox::warning(this,"warning","请按确认");
    }

}
