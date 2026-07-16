#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include "volumetool.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    initUI();
    connectSignalAdnSlot();


}

Widget::~Widget()
{
    delete ui;
}

 VolumeTool* volumeTool;
void Widget::initUI()
{
   setWindowFlag(Qt::WindowType::FramelessWindowHint);


    //设置背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect *shadowEffect =new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(10);//设置模糊半径
    shadowEffect->setOffset(0,0);//设置阴影偏移
    shadowEffect->setColor(QColor(0,0,0));//阴影颜色
   this->setGraphicsEffect(shadowEffect);


   //设置BodyLeft中的btFrom
   ui->rec->setIcon(":/images/rec.png", "推荐", 0);
    ui->radio->setIcon(":/images/radio.png", "电台", 1);
    ui->music->setIcon(":/images/music.png", "⾳乐馆", 2);

    ui->like->setIcon(":/images/like.png", "我喜欢", 3);
    ui->local->setIcon(":/images/local.png", "本地下载", 4);
    ui->recent->setIcon(":/images/recent.png", "最近播放", 5);

    //设置默认选中本地下载
    ui->local->animalShow();
    ui->stackedWidget->setCurrentIndex(4);

    srand(time(NULL));
    ui->recMusicBox->initRecBoxUi(randomPiction(),1);
    ui->supplyMusicBox->initRecBoxUi(randomPiction(),2);

   //设置Commpage的信息
    ui->likePage->setCommonPageUI("我喜欢",":/images/ilikebg.png");
    ui->localPage->setCommonPageUI("本地音乐",":/images/localbg.png");
    ui->recentPage->setCommonPageUI("最近播放，" ,":/images/recentbg.png");

    volumeTool = new VolumeTool(this);

}
QJsonArray Widget::randomPiction()
    {
QVector<QString> vecImageName;
 vecImageName<<"001.png"<<"003.png"<<"004.png"<<"005.png"<<"006.png"<<"007.png"
     <<"008.png"<<"009.png"<<"010.png"<<"011.png"<<"012.png"<<"013.png"
     <<"014.png"<<"015.png"<<"016.png"<<"017.png"<<"018.png" <<"019.png"
     <<"020.png"<<"021.png"<<"022.png"<<"023.png"<<"024.png" <<"025.png"
     <<"026.png"<<"027.png"<<"028.png"<<"029.png"<<"030.png" <<"031.png"
     <<"032.png"<<"033.png"<<"034.png"<<"035.png"<<"036.png"<<"037.png"
     <<"038.png"<<"039.png"<<"040.png";

     std::random_shuffle(vecImageName.begin(), vecImageName.end());


     QJsonArray objArray;
    for(int i = 0; i < vecImageName.size(); ++i)
     {
     QJsonObject obj;
     obj.insert("path", ":/images/rec/"+vecImageName[i]);


         QString strText = QString("推荐-%1").arg(i, 3, 10, QChar('0'));
     obj.insert("text", strText);

         objArray.append(obj);

         }

     return objArray;
     }




void Widget::mousePressEvent(QMouseEvent *event)
{

    //event->globalPos() 获取鼠标全局屏幕坐标
    //frameGeometry().topLeft()取出这个窗口外框矩形的左上角屏幕全局坐标
    //
    if(event->button()==Qt::LeftButton)
    {
        dragPosition=event->globalPos()-frameGeometry().topLeft();

        // qDebug()<<dragPosition;
        return ;
    }

    QWidget::mousePressEvent(event);


}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton)
    {
        move(event->globalPos()-dragPosition);//窗口左上角新全局坐标

        return;

    }
    QWidget::mouseMoveEvent(event);

}

void Widget::connectSignalAdnSlot()
{
    connect(ui->rec,&BtForm::click,this,&Widget::onBtFormClick);
    connect(ui->music,&BtForm::click,this,&Widget::onBtFormClick);
    connect(ui->radio,&BtForm::click,this,&Widget::onBtFormClick);
    connect(ui->like,&BtForm::click,this,&Widget::onBtFormClick);
    connect(ui->local,&BtForm::click,this,&Widget::onBtFormClick);
    connect(ui->recent,&BtForm::click,this,&Widget::onBtFormClick);
}

void Widget::onBtFormClick(int pageid)
{
    //1找到所有BtForm所有按钮对象
    QList<BtForm*>buttonList=this->findChildren<BtForm*>();
    //2.查找对象，如果不是当前Id的对象清楚显示背景颜色
    foreach (BtForm* btitem, buttonList)
         {
        if (pageid != btitem->getId())
             {
                 btitem->clearBg();
             }
        }
    //3显示当前显示的页面
        ui->stackedWidget->setCurrentIndex(pageid);
        qDebug()<<pageid;
}



void Widget::on_quit_clicked()
{
    this->close();
}


void Widget::on_volume_clicked()
{
    QPoint point = ui->volume->mapToGlobal(QPoint(0,0));


         QPoint volumeLeftTop = point - QPoint(volumeTool->width()/2, volumeTool->height());


         volumeLeftTop.setY(volumeLeftTop.y()+30);
     volumeLeftTop.setX(volumeLeftTop.x()+15);


         volumeTool->move(volumeLeftTop);


         volumeTool->show();
}

