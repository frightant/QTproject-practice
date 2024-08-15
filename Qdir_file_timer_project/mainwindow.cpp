#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDir>

#include <QFile>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir dir("c:");
    foreach(QFileInfo var,dir.entryInfoList()){
        ui->comboBox->addItem(var.absoluteFilePath());
    }
    QDir dir1;
    foreach(QFileInfo var,dir1.entryInfoList()){
        ui->listWidget->addItem(var.absoluteFilePath());
    }
//    if(dir.exists()){
//        QMessageBox::information(this,"title","ture");
//    }else {
//        QMessageBox::information(this,"title","ture");
//}
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/img/1.png"),"你好 么么哒");
    QListWidgetItem *item1 = new QListWidgetItem(QIcon(":/img/2.png"),"你好 呵呵哒");
    ui->listWidget->addItem(item);
    ui->listWidget->addItem(item1);
    ui->listWidget->addItem("你好嘻嘻哒");
    ui->listWidget->addItem("你好治治哒");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // 获取当前选中的项目
    QListWidgetItem* currentItem = ui->listWidget->currentItem();

    // 检查是否有项目被选中
    if (currentItem) {
        // 显示选中项目的文本
        QMessageBox::information(this, "提示", currentItem->text());

        // 设置选中项目的背景颜色为红色
        currentItem->QListWidgetItem::setBackground(Qt::red);
    } else {
        // 如果没有项目被选中，则可以给出警告
        QMessageBox::warning(this, "警告", "请先在列表中选择一个项目。");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile file("E:/qtprojects_all/Qdir_file_timer_project/myfile.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"title","file not open");
    }
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
    QMessageBox::information(this,"title","write was ok");
}

void MainWindow::on_pushButton_3_clicked()
{
    QFile file("E:/qtprojects_all/Qdir_file_timer_project/myfile.txt");

    // 确保文件以只读和文本模式打开
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "title", "文件无法打开，请检查文件路径和权限。");
        return; // 如果文件无法打开，直接返回，不执行后续读取操作
    }

    QTextStream in(&file);
    QString text = in.readAll(); // 读取所有内容

    ui->plainTextEdit->setPlainText(text); // 将读取的内容设置到 QPlainTextEdit 控件中

    file.close(); // 关闭文件
    QMessageBox::information(this,"information","reading was ok!");
}
