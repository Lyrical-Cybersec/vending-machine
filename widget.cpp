#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money>=200);
    ui->pbMilk->setEnabled(money>=100);
    ui->pbTea->setEnabled(money>=150);
}

void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
   // money +=500;
   // ui->lcdNumber->display(money);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
//    money +=100;
//    ui->lcdNumber->display(money);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
//    money +=50;
//    ui->lcdNumber->display(money);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
//    money +=10;
//    ui->lcdNumber->display(money);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
//    money -=200;
//    ui->lcdNumber->display(money);

}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
//    money -=150;
//    ui->lcdNumber->display(money);

}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
//    money -=100;
//    ui->lcdNumber->display(money);

}


void Widget::on_pbReset_clicked()
{
    int remain500 = 0;
    int remain100 = 0;
    int remain50 = 0;
    int remain10 = 0;

    QString r500;
    QString r100;
    QString r50;
    QString r10;

    remain500 = money / 500;
    money = money % 500;

    remain100 = money / 100;
    money = money % 100;

    remain50 = money / 50;
    money = money % 50;

    remain10 = money / 10;

    r500 = r500.setNum(remain500);
    r100 = r100.setNum(remain100);
    r50 = r50.setNum(remain50);
    r10 = r10.setNum(remain10);

    MsgBox.setInformativeText("잔돈은 500원 " + r500 + "개" + "100원 " + r100 + "개" +"50원 " + r50 + "개" +"10원 " + r10 + "개" + "입니다.");
    MsgBox.setStandardButtons(QMessageBox::Ok |QMessageBox::Cancel);
    MsgBox.setDefaultButton(QMessageBox::Ok);

    if ( MsgBox.exec() == QMessageBox::Ok )
    {
        this->close();
    }
    money=0;
    ui->lcdNumber->display(money);
    //setControl();
}



