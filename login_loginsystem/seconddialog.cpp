#include "seconddialog.h"
#include "ui_seconddialog.h"

secondDialog::secondDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondDialog)
{
    ui->setupUi(this);
}

secondDialog::~secondDialog()
{
    delete ui;
}

void secondDialog::on_pushButton_clicked()
{
    close();
}
