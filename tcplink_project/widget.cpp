#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket = new QTcpSocket;//创建一个socket指针对象。
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    this->close();
}

void Widget::on_linkButton_clicked()
{
    //获取ip地址和端口号;
    QString ip = ui->iplineEdit->text();
    QString post = ui->numbEdit->text();
    socket = connectToHost(QHostAddress(ip),post.toShort());

}
