#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QPixmap>
//用于插入图片
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pix(":/img/1.jpg");
    int w = ui->lebpix->width();
    int h = ui->lebpix->height();
    ui->lebpix->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_loginbutton_clicked()
{
    QString username=ui->nameEdit->text();
    QString password=ui->psswordEdit_2->text();
    if(username=="admin"&&password=="123456"){

        QMessageBox::information(this,"登录","登录成功！！！");
        hide();
        dialog = new secondDialog;
        dialog->show();
    }else{
        QMessageBox::warning(this,"警告","账号或者密码错误！！！");
    }
}
