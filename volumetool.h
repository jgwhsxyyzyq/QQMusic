#ifndef VOLUMETOOL_H
#define VOLUMETOOL_H

#include <QWidget>

namespace Ui {
class VolumeTool;
}

class VolumeTool : public QWidget
{
    Q_OBJECT

public:
    explicit VolumeTool(QWidget *parent = nullptr);
    ~VolumeTool();
    void paintEvent(QPaintEvent *event) override;

    //静音按钮槽函数
    void onSilenceBtnClicked();



    //过滤事件
    bool eventFilter(QObject* object, QEvent* event) override;
   // 根据鼠标在滑竿上滑动更新滑动界面，并按照比例计算音量大小
   void  setVolume();


signals:
    //设置静音信号
    void setSilence(bool);
    //发射修改音量大小的槽函数
    void setMusicVolume(int);


private:
    Ui::VolumeTool *ui;
    bool isMuted;// 记录静音或非静音，当点击静音按钮时，在true和false之间切换

    int volumeRatio; // 标记音量大小
};

#endif // VOLUMETOOL_H
