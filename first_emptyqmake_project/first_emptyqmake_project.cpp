#include <QApplication>
#include <QLabel>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QLabel *label;
    label = new QLabel("hello wrold");
    label->setWindowTitle("nihao");
    label->resize(400,400);
    label->show();
    return app.exec();
}
