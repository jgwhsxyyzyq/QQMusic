#include "volumetool.h"
#include "qicon.h"
#include "ui_volumetool.h"
#include <QGraphicsDropShadowEffect>
#include<QPainter>
VolumeTool::VolumeTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VolumeTool)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Popup|Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect* shadowEffect=new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor("#646464");
    shadowEffect->setBlurRadius(10);
    setGraphicsEffect(shadowEffect);

   ui->silenceBtn->setIcon(QIcon(":/images/volumn.png"));
    QRect rect=ui->outLine->geometry();
    ui->outLine->setGeometry(rect.x(),180-36+25,rect.width(),36);

   ui->silenceBtn->move(ui->silenceBtn->x(),ui->silenceBtn->y()-ui->silenceBtn->height()/2);
    ui->volumeRatio->setText("20%");

}
VolumeTool::~VolumeTool()
{
    delete ui;
}

void VolumeTool::paintEvent(QPaintEvent *event)
{
    (void)event;
    // 绘制volumeTool界面下的三角
    QPainter painter(this);

    // 1. 设置画笔
    painter.setPen(Qt::NoPen);

    // 2. 设置画刷
    painter.setBrush(QColor("#1ECC94"));


    // 3. 绘制三角形
    QPolygon polygon;
    polygon << QPoint(35, 338)
            << QPoint(65, 338)
            << QPoint(50, 348);


    painter.drawPolygon(polygon);
}



