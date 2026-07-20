#include "volumetool.h"
#include "qicon.h"
#include "ui_volumetool.h"
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include<QPainter>
VolumeTool::VolumeTool(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VolumeTool)
    ,isMuted(false)//默认静音
    ,volumeRatio(20)//音量为20
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
    ui->silenceBtn->setIconSize(QSize(20,20));
    QRect rect=ui->outLine->geometry();
    ui->outLine->setGeometry(rect.x(),180-36+25,rect.width(),36);
    ui->sliderBtn->move(ui->sliderBtn->x(),
                        ui->outLine->y()-ui->sliderBtn->height()/2);

   ui->silenceBtn->move(ui->silenceBtn->x(),ui->silenceBtn->y()-ui->silenceBtn->height()/2);
    ui->volumeRatio->setText("20%");
   //关联静音信号槽
   connect(ui->silenceBtn,&QPushButton::clicked,this,&VolumeTool::onSilenceBtnClicked);

   // 在音量轨道和圆形滑块上安装事件过滤器，支持点击和拖动。
   ui->sliderBox->installEventFilter(this);
   ui->sliderBtn->installEventFilter(this);
   ui->sliderBox->setMouseTracking(true);
   ui->sliderBtn->setMouseTracking(true);

   // 轨道线只负责显示，不拦截sliderBox的鼠标事件。
   ui->inLine->setAttribute(Qt::WA_TransparentForMouseEvents);
   ui->outLine->setAttribute(Qt::WA_TransparentForMouseEvents);
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

void VolumeTool::onSilenceBtnClicked()
{
    isMuted=!isMuted;
    if(isMuted)
    {
        ui->silenceBtn->setIcon(QIcon((":/images/silent.png")));

    }
    else{
        ui->silenceBtn->setIcon(QIcon(":/images/volumn.png"));
    }
    emit setSilence(isMuted);
}

bool VolumeTool::eventFilter(QObject *object, QEvent *event)
{
    if(object==ui->sliderBox || object==ui->sliderBtn)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent=static_cast<QMouseEvent *>(event);
            if(mouseEvent->button()==Qt::LeftButton)
            {
                setVolume();
                emit setMusicVolume(volumeRatio);
                return true;
            }
        }
        else if(event->type() == QEvent::MouseMove)
        {
            QMouseEvent *mouseEvent=static_cast<QMouseEvent *>(event);
            if(mouseEvent->buttons() & Qt::LeftButton)
            {
                setVolume();
                emit setMusicVolume(volumeRatio);
                return true;
            }
        }
        else if(event->type() == QEvent::MouseButtonRelease)
        {
            QMouseEvent *mouseEvent=static_cast<QMouseEvent *>(event);
            if(mouseEvent->button()==Qt::LeftButton)
            {
                setVolume();
                emit setMusicVolume(volumeRatio);
                return true;
            }
        }
    }
    return QWidget::eventFilter(object, event);
}

void VolumeTool::setVolume()
{
    // 1. 将鼠标的位置转换为sloderBox上的相对坐标，此处只要获取y坐标
    int height = ui->sliderBox->mapFromGlobal(QCursor().pos()).y();

    //2. 鼠标在volumeBoheight = height < 25? 25 : height;中可移动的y范围在[25, 205之间]
    height=qBound(25,height,205);
    // 3. 调整sloderBt的位置
    ui->sliderBtn->move(ui->sliderBtn->x(),height-ui->sliderBtn->height()/2);

    // 4. 更新outline的位置和大小

    ui->outLine->setGeometry(ui->outLine->x(), height, ui->outLine->width(),  205 - height);

    // 5. 计算音量比率
    volumeRatio=qRound(ui->outLine->height()/180.0*100);

    // 6. 设置label
    ui->volumeRatio->setText(QString::number(volumeRatio)+"%");
}
