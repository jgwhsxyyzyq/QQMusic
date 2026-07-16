#include "RecBoxItem.h"
#include "ui_RecBoxItem.h"


RecBoxItem::RecBoxItem(QWidget *parent)
    : QWidget(parent)

    , ui(new Ui::RecBoxItem)
{
    ui->setupUi(this);
    ui->musicImageBox->installEventFilter(this);
}

RecBoxItem::~RecBoxItem()
{
    delete ui;
}

bool RecBoxItem::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->musicImageBox)
    {
        //获取控件的宽和高
        int ImgWidget=ui->musicImageBox->width();
        int ImgHeight=ui->musicImageBox->height();
        //拦截鼠标进入事件
        //鼠标进入逻辑
        if(event->type()==QEvent::Enter)
        {

            QPropertyAnimation*animation=new QPropertyAnimation(ui->musicImageBox,"geometry");
            animation->setDuration(100);
            animation->setStartValue(QRect(6,6,ImgWidget,ImgHeight));
            animation->setEndValue(QRect(6,0,ImgWidget,ImgHeight));
            animation->start();

            connect(animation,&QPropertyAnimation::finished,this,[=](){delete animation;
                qDebug()<<"图片上移结束";
            });
        }
        //鼠标离开逻辑
        else if(event->type()==QEvent::Leave){

            QPropertyAnimation *animation=new QPropertyAnimation(ui->musicImageBox,"geometry");
            animation->setDuration(150);
            animation->setStartValue(QRect(6,0,ImgWidget,ImgHeight));
            animation->setEndValue(QRect(6,6,ImgWidget,ImgHeight));
            animation->start();

            connect(animation,&QPropertyAnimation::finished,this,[=](){delete animation;
                qDebug()<<"图片下移结束";
            });

        }
        return true;
    }
    return QObject::eventFilter(watched, event);
}

void RecBoxItem::steText(const QString &text)
{
    ui->recBoxItemText->setText(text);
}

void RecBoxItem::setImage(const QString &Imagepath)
{
    QString imgStyle = "border-image:url("+Imagepath+");";
    ui->recMusicImage->setStyleSheet(imgStyle);

}

