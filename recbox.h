#ifndef RECBOX_H
#define RECBOX_H

#include "qjsonarray.h"
#include <QWidget>
#include<QJsonObject>

namespace Ui {
class RecBox;
}

class RecBox : public QWidget
{
    Q_OBJECT

public:
    explicit RecBox(QWidget *parent = nullptr);
    ~RecBox();

    void initRecBoxUi(QJsonArray data,int row);

private slots:
    void on_btUp_clicked();

    void on_btDown_clicked();


private:
    void createRecBoxItem();

private:
    Ui::RecBox *ui;
    int row;

    int col;
    QJsonArray imageList;

    int currentIndex;//标记当前显示的第一组元素
    int count;//记录图片的总组数
};

#endif // RECBOX_H
