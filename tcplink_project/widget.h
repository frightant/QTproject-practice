#ifndef WIDGET_H
#define WIDGET_H
#include <QHostAddress>
#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();

    void on_linkButton_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
};
#endif // WIDGET_H
