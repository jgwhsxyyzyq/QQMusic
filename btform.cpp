#include "btform.h"
#include "ui_btform.h"

BtForm::BtForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BtForm)
{
    ui->setupUi(this);

    ui->lineBox->hide();
    //对linBox中的label设置动画效果
    animationLine1=new QPropertyAnimation(ui->line1,"geometry",this);
    animationLine1->setDuration(1500);
    animationLine1->setKeyValueAt(0, QRect(0, 20, 2, 0));
    animationLine1->setKeyValueAt(0.5, QRect(0, 0, 2, 20));
    animationLine1->setKeyValueAt(1, QRect(0, 20, 2, 0));
    animationLine1->setLoopCount(-1);
    animationLine1->start();

    animationLine2=new QPropertyAnimation(ui->line2,"geometry",this);
    animationLine2->setDuration(1600);
    animationLine2->setKeyValueAt(0, QRect(10, 20, 2, 0));
    animationLine2->setKeyValueAt(0.5, QRect(10, 0, 2, 20));
    animationLine2->setKeyValueAt(1, QRect(10, 20, 2, 0));
    animationLine2->setLoopCount(-1);
    animationLine2->start();

    animationLine3=new QPropertyAnimation(ui->line3,"geometry",this);
    animationLine3->setDuration(1700);
    animationLine3->setKeyValueAt(0, QRect(16, 20, 2, 0));
    animationLine3->setKeyValueAt(0.5, QRect(16, 0, 2, 20));
    animationLine3->setKeyValueAt(1, QRect(16, 20, 2, 0));
    animationLine3->setLoopCount(-1);
    animationLine3->start();

    animationLine4=new QPropertyAnimation(ui->line4,"geometry",this);
    animationLine4->setDuration(1800);
    animationLine4->setKeyValueAt(0, QRect(22, 20, 2, 0));
    animationLine4->setKeyValueAt(0.5, QRect(22, 0, 2, 20));
    animationLine4->setKeyValueAt(1, QRect(22, 20, 2, 0));
    animationLine4->setLoopCount(-1);
    animationLine4->start();

}

BtForm::~BtForm()
{
    delete ui;
}

void BtForm::setIcon(const QString btIcon, const QString btText, const int pageid)
{
    ui->btIcon->setPixmap(QPixmap(btIcon));
     ui->btText->setText(btText);
    this->pageid=pageid;
}

void BtForm::clearBg()
{
    ui->btStyle->setStyleSheet("#btStyle:hover{ background:#D8D8D8;} ");

}

int BtForm::getId()
{
    return pageid;
}

void BtForm::animalShow()
{
    ui->lineBox->show();
}

void BtForm::mousePressEvent(QMouseEvent *event)
{
    (void)event;
       ui->btStyle->setStyleSheet("#btStyle{background:rgb(30,206,154);color:#F6F6F6;}");
    emit click(pageid);
}