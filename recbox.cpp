#include "recbox.h"
#include "RecBoxItem.h"
#include "ui_recbox.h"
#include <cmath>
RecBox::RecBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecBox)
    ,row(1)
    ,col(4)
{
    ui->setupUi(this);


}

RecBox::~RecBox()
{
    delete ui;
}

void RecBox::initRecBoxUi(QJsonArray data, int row)
{
    if(row==2)
    {
        this->row=row;
       col=8;
    }
    else
    {
        ui->recListDown->hide();
    }
    imageList=data;
    currentIndex=0;
    count=ceil(imageList.size()/col);


    createRecBoxItem();
}




void RecBox::createRecBoxItem()
{
    //删除内部之前的元素
    const QList<RecBoxItem*>recUpList= ui->recListUp->findChildren<RecBoxItem*>();
    for(auto e:recUpList)
    {
        ui->recListUpHLayout->removeWidget(e);
        delete e;

    }

    const QList<RecBoxItem*>recDownList=ui->recListDown->findChildren<RecBoxItem*>();

    for(auto e:recDownList)
    {
        ui->recListDownHLayout->removeWidget(e);
        delete e;
    }
    //创建RecBoxItem对象，
    int index=0;
    for(int i=currentIndex*col;i<col+currentIndex*col;i++)
    {
        RecBoxItem *item=new RecBoxItem();
        QJsonObject obj=imageList[i].toObject();
        item->steText(obj.value("text").toString());
        item->setImage(obj.value("path").toString());

        if(index >= col/2 && row == 2)
        {
         ui->recListDownHLayout->addWidget(item);
        }
        else
          ui->recListUpHLayout->addWidget(item);
        index++;
    }
}

void RecBox::on_btUp_clicked()
{
    //点击之后显示上一组
    //如果已经是第0组，显示最后的一组
    if (count == 0) return;
    currentIndex = (currentIndex - 1 + count) % count;
    createRecBoxItem();
}



void RecBox::on_btDown_clicked()
{
    //点击之后显示下一组
    //如果已经是最后一组显示第0组
    currentIndex++;
     if(currentIndex >= count)
     {
         currentIndex = 0;
         }


     createRecBoxItem();
}

