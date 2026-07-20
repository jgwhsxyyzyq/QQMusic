#ifndef MUSICSLIDE_H
#define MUSICSLIDE_H

#include <QWidget>

namespace Ui {
class MusicSlide;
}

class MusicSlide : public QWidget
{
    Q_OBJECT

public:
    explicit MusicSlide(QWidget *parent = nullptr);
    ~MusicSlide();

    // 根据播放器的当前位置和总时长更新进度条。
    void setProgress(qint64 position, qint64 duration);

signals:
    // 用户释放鼠标后，请求播放器跳转到0.0～1.0之间的位置。
    void seekRequested(double ratio);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void moveSlider();

    Ui::MusicSlide *ui;
    int currentPos;
    bool isDragging;
};

#endif // MUSICSLIDE_H
