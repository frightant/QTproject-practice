#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->newAction,&QAction::triggered,this,&MainWindow::newActionslots);//第一个参数选择按钮，第二个参数是触发的方式，第三个是在哪里触发父类是谁，第四个是槽函数
    connect(ui->openAction,&QAction::triggered,this,&MainWindow::openActionslots);
    connect(ui->saveAction,&QAction::triggered,this,&MainWindow::saveActionslots);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openActionslots(){
    QString filename= QFileDialog::getOpenFileName(this, tr("选择一个文件"),QCoreApplication::applicationFilePath(),"*.cpp");//别人已经写好的文件框，直接调用来使用就行，在帮助里面搜索关键词getopenfile第一个就是。
    if(filename.isEmpty())
    {
        QMessageBox::warning(this,"警告","已返回内容没保存");//QMessageBox是一个弹窗类
    }
    else {
//        qDebug()<<filename;
        QFile file(filename);
        file.open(QIODevice::ReadOnly);
        QByteArray f = file.readAll();
        ui->textEdit->setText(QString(f));
        file.close();
    }

}
void MainWindow::saveActionslots(){
    QString filen = QFileDialog::getSaveFileName(this,"选择保存的位置",QCoreApplication::applicationFilePath());
    if(filen.isEmpty()){
        QMessageBox::warning(this,"警告","你没有保存");
    }else {
        QFile file(filen);
        file.open(QIODevice::WriteOnly);
        QByteArray ba;
        ba.append(ui->textEdit->toPlainText());//append就是吧Qstring接在ba后面，约等于吧Qstring转换成QBArray;
        file.write(ba);
        file.close();
}
}

void MainWindow::keyPressEvent(QKeyEvent *k){
    if(k->modifiers()==Qt::ControlModifier && k->key()==Qt::Key_S){
        saveActionslots();
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event){
    QPoint pt = event->pos();
    qDebug()<<pt;
    if(event->button()==Qt::LeftButton){
        qDebug()<<"左键被按下";
    }else if(event->button()==Qt::RightButton){
        qDebug()<<"右键被按下";
    }
}

void MainWindow::newActionslots(){
    ui->textEdit->clear();
    this->setWindowTitle("新建笔记.txt");
}

