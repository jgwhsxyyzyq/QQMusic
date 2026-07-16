#include "commonpage.h"
#include "ui_commonpage.h"
#include "listitembox.h"
CommonPage::CommonPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommonPage)
{
    ui->setupUi(this);
}

CommonPage::~CommonPage()
{
    delete ui;
}

void CommonPage::setCommonPageUI(const QString &text, const QString &imagePath)
{
    //设置文本
    ui->pageTittle->setText(text);
    //设置推荐页面
    ui->musicImageLabel->setPixmap(imagePath);
    //设置缩放
    ui->musicImageLabel->setScaledContents(true);
    //测试
    ListItemBox* listItemBox = new ListItemBox(this);
     QListWidgetItem* listWidgetItem = new QListWidgetItem(ui->pageMusicList);
     listWidgetItem->setSizeHint(QSize(ui->pageMusicList->width(), 45));
     ui->pageMusicList->setItemWidget(listWidgetItem, listItemBox);

}
