#ifndef RECBOXITEM_H
#define RECBOXITEM_H
#include <QPropertyAnimation>
#include <QWidget>
#include<QDebug>
namespace Ui {
// 把 Designer 改成 RecBoxItem，匹配ui自动生成的类名
class RecBoxItem;
}

class RecBoxItem : public QWidget
{
    Q_OBJECT
public:
    explicit RecBoxItem(QWidget *parent = nullptr);
    ~RecBoxItem();

    bool eventFilter(QObject *watched, QEvent *event);
    //设置推荐文本
    void steText(const QString& text);
    void setImage(const QString & Imagepath);


private:
    // 指针类型改成Ui命名空间下的UI结构体
    Ui::RecBoxItem *ui;
};

#endif // RECBOXITEM_H