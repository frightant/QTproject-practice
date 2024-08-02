#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    server = new QTcpServer;
    server->listen(QHostAddress::AnyIPv4,port);
    //监听之后，让客户端发起连接;
    connect(server,&QTcpServer::newConnection,&Widget::newclint);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newclint(){
    QTcpSocket *socket = server->nextPendingConnection();
    ui->ipEdit->setText(socket->peerAddress().toString());
    ui->portEdit->setText(QString::number( socket->peerPort()));

}
