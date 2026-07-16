#ifndef BTFORM_H
#define BTFORM_H
#include<QPropertyAnimation>
#include <QWidget>

namespace Ui {
class BtForm;
}

class BtForm : public QWidget
{
    Q_OBJECT

public:
    explicit BtForm(QWidget *parent = nullptr);
    ~BtForm();
    //设置图片文字id
    void setIcon(const QString btIcon,const QString btText,const int pageid);
    //清除上次选中的样式
    void clearBg();

         // 获取id
     int getId();
    void animalShow();


protected:
     // 鼠标标点击事件
        virtual void mousePressEvent(QMouseEvent *event);

signals:
        void click(int  id);
private:
    Ui::BtForm *ui;
    int pageid;
    //添加动画效果
    QPropertyAnimation * animationLine1;
    QPropertyAnimation * animationLine2;
    QPropertyAnimation * animationLine3;
    QPropertyAnimation * animationLine4;
};

#endif // BTFORM_H
