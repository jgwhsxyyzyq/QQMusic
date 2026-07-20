#include "musicslide.h"
#include "ui_musicslide.h"
#include <QMouseEvent>
#include <QtMath>

MusicSlide::MusicSlide(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicSlide)
    , currentPos(0)
    , isDragging(false)
{
    ui->setupUi(this);

    // 让两个进度条无缝连接，并让鼠标事件交给MusicSlide处理。
    ui->horizontalLayout->setContentsMargins(0,0,0,0);
    ui->horizontalLayout->setSpacing(0);
    ui->outLine->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->inLine->setAttribute(Qt::WA_TransparentForMouseEvents);

    moveSlider();
}

MusicSlide::~MusicSlide()
{
    delete ui;
}

void MusicSlide::setProgress(qint64 position, qint64 duration)
{
    // 用户正在拖动时，以鼠标位置为准，避免播放器信号把滑块拉回去。
    if(isDragging)
    {
        return;
    }

    if(duration<=0)
    {
        currentPos=0;
    }
    else
    {
        currentPos=qRound(position/static_cast<double>(duration)*width());
    }

    moveSlider();
}

void MusicSlide::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        isDragging=true;
        currentPos=qBound(0,event->pos().x(),width());
        moveSlider();
        event->accept();
        return;
    }

    QWidget::mousePressEvent(event);
}

void MusicSlide::mouseMoveEvent(QMouseEvent *event)
{
    if(isDragging && (event->buttons() & Qt::LeftButton))
    {
        currentPos=qBound(0,event->pos().x(),width());
        moveSlider();
        event->accept();
        return;
    }

    QWidget::mouseMoveEvent(event);
}

void MusicSlide::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        currentPos=qBound(0,event->pos().x(),width());
        moveSlider();
        isDragging=false;

        const double ratio=width()>0
                                ? currentPos/static_cast<double>(width())
                                : 0.0;
        emit seekRequested(ratio);

        event->accept();
        return;
    }

    QWidget::mouseReleaseEvent(event);
}

void MusicSlide::moveSlider()
{
    const int totalWidth=qMax(0,width());
    currentPos=qBound(0,currentPos,totalWidth);

    ui->outLine->setFixedWidth(currentPos);
    ui->inLine->setMinimumWidth(0);
}
