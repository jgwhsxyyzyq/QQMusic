#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QGraphicsDropShadowEffect>
#include<QJsonObject>

#include <QJsonArray>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;
    void initUI();
    QJsonArray randomPiction();

protected:
    void mousePressEvent(QMouseEvent*event)override;
     void mouseMoveEvent(QMouseEvent*event)override;
    void connectSignalAdnSlot();




private slots:
    void on_quit_clicked();
    void onBtFormClick(int pageid);

    void on_volume_clicked();

private:
    Ui::Widget *ui;
    QPoint dragPosition;
};
#endif // WIDGET_H
