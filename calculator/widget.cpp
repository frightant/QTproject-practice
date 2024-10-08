#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("YU");
    QFont f("微软雅黑",12);
    ui->mainLineEdit->setFont(f);
    //按钮上放图片
    QIcon con("E:\\qtprojects_all\\calculator\\back.png");
    ui->delButton->setIcon(con);
    //改变按钮颜色
    ui->equalButton->setStyleSheet("background:pink");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_oneButton_clicked()
{
    expression += "1";
    ui->mainLineEdit->setText(expression);

}

void Widget::on_twoBotton_clicked()
{
    expression += "2";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_threeButton_clicked()
{
    expression += "3";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_fourButton_clicked()
{
    expression += "4";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_fiveButton_clicked()
{
    expression += "5";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_sixButton_clicked()
{
    expression += "6";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_sevenButton_clicked()
{
    expression += "7";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_eightButton_clicked()
{
    expression += "8";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_nineButton_clicked()
{
    expression += "9";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_leftButton_clicked()
{
    expression += "(";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_zeroButton_clicked()
{
    expression += "0";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_rightButton_clicked()
{
    expression += ")";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_multiplyButton_clicked()
{
    expression += "*";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_divisionButton_clicked()
{
    expression += "/";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_subButton_clicked()
{
    expression += "-";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_plusButton_clicked()
{
    expression += "+";
    ui->mainLineEdit->setText(expression);
}

void Widget::on_clearButton_clicked()
{
    expression.clear();
    ui->mainLineEdit->clear();
}


void Widget::on_delButton_clicked()
{
    expression.chop(1);
    ui->mainLineEdit->setText(expression);
}
int Priority(char ch){
    switch(ch){
    case '/':
    case'*' : return 2;
    case'(' : return 3;
    case '+':
    case '-': return 1;
    default:return 0;
    }
}
void Widget::on_equalButton_clicked()
{
    QStack<int> s_num,s_opt;
    char opt[128]={0};
    int i = 0,temp=0,num1,num2;
    QByteArray ba;
    ba.append(expression);//把QString转换成QByteArray
    strcpy(opt,ba.data());//data可以把QByteArray转换为const char *
    while (opt[i]!='\0'||s_opt.empty()!=true){
        if(opt[i]>='0'&&opt[i]<='9'){
            temp = temp*10 + opt[i] - '0';
            i++;
            if(opt[i]<'0'||opt[i]>'9'){//如果下一个字符是操作符就把之前的数字入栈
                s_num.push(temp);
                temp=0;
            }
        }
        else {//操作符
            if(s_opt.empty()==true||Priority(opt[i])>Priority(s_opt.top())||(s_opt.top()=='('&&opt[i]!=')')){
                s_opt.push(opt[i]);
                i++;
                continue;
            }
            if(s_opt.top()=='('&&opt[i]==')'){
                s_opt.pop();
                i++;
                continue;
            }
            if(Priority(opt[i])<=Priority(s_opt.top())||(opt[i]==')'&&s_opt.top())||(opt[i]=='\0'&&s_opt.empty()!=true)){
                char ch = s_opt.top();
                s_opt.pop();
                switch (ch) {
                case '+':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1+num2);
                    break;
                case '-':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num2-num1);
                    break;
                case '*':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1*num2);
                    break;
                case '/':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num2/num1);
                    break;
                }
            }
        }
    }
            ui->mainLineEdit->setText(QString::number(s_num.top()));
            expression.clear();
}


