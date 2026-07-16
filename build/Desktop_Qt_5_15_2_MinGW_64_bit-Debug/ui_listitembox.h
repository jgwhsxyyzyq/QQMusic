/********************************************************************************
** Form generated from reading UI file 'listitembox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTITEMBOX_H
#define UI_LISTITEMBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListItemBox
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *musicNameBox;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *likeBtn;
    QLabel *musicNameLabel;
    QLabel *VIPLabel;
    QLabel *SQLabel;
    QSpacerItem *horizontalSpacer;
    QWidget *musicSingerBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *musicSingerLabel;
    QWidget *musicAlbumBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *albumNameLabel;

    void setupUi(QWidget *ListItemBox)
    {
        if (ListItemBox->objectName().isEmpty())
            ListItemBox->setObjectName(QString::fromUtf8("ListItemBox"));
        ListItemBox->resize(800, 45);
        horizontalLayout = new QHBoxLayout(ListItemBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        musicNameBox = new QWidget(ListItemBox);
        musicNameBox->setObjectName(QString::fromUtf8("musicNameBox"));
        musicNameBox->setMinimumSize(QSize(380, 0));
        musicNameBox->setMaximumSize(QSize(380, 16777215));
        horizontalLayout_4 = new QHBoxLayout(musicNameBox);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        likeBtn = new QPushButton(musicNameBox);
        likeBtn->setObjectName(QString::fromUtf8("likeBtn"));
        likeBtn->setMinimumSize(QSize(25, 25));
        likeBtn->setMaximumSize(QSize(25, 25));
        likeBtn->setStyleSheet(QString::fromUtf8("#likeBtn\n"
"{\n"
" border:none;\n"
"}"));

        horizontalLayout_4->addWidget(likeBtn);

        musicNameLabel = new QLabel(musicNameBox);
        musicNameLabel->setObjectName(QString::fromUtf8("musicNameLabel"));
        musicNameLabel->setMinimumSize(QSize(130, 0));

        horizontalLayout_4->addWidget(musicNameLabel);

        VIPLabel = new QLabel(musicNameBox);
        VIPLabel->setObjectName(QString::fromUtf8("VIPLabel"));
        VIPLabel->setMinimumSize(QSize(30, 0));
        VIPLabel->setMaximumSize(QSize(30, 15));
        VIPLabel->setStyleSheet(QString::fromUtf8("#VIPLabel\n"
"{\n"
" border:1px solid #1ECD96;\n"
"color:#1ECD96;\n"
" border-radius:2px;\n"
" }"));

        horizontalLayout_4->addWidget(VIPLabel);

        SQLabel = new QLabel(musicNameBox);
        SQLabel->setObjectName(QString::fromUtf8("SQLabel"));
        SQLabel->setMinimumSize(QSize(25, 0));
        SQLabel->setMaximumSize(QSize(25, 15));
        SQLabel->setStyleSheet(QString::fromUtf8("#SQLabel\n"
" {\n"
" border:1px solid #FF6600;\n"
" color:#FF6600;\n"
" border-radius:2px;\n"
"}"));

        horizontalLayout_4->addWidget(SQLabel);

        horizontalSpacer = new QSpacerItem(139, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        horizontalLayout->addWidget(musicNameBox);

        musicSingerBox = new QWidget(ListItemBox);
        musicSingerBox->setObjectName(QString::fromUtf8("musicSingerBox"));
        musicSingerBox->setMinimumSize(QSize(200, 0));
        musicSingerBox->setMaximumSize(QSize(200, 16777215));
        horizontalLayout_2 = new QHBoxLayout(musicSingerBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        musicSingerLabel = new QLabel(musicSingerBox);
        musicSingerLabel->setObjectName(QString::fromUtf8("musicSingerLabel"));

        horizontalLayout_2->addWidget(musicSingerLabel);


        horizontalLayout->addWidget(musicSingerBox);

        musicAlbumBox = new QWidget(ListItemBox);
        musicAlbumBox->setObjectName(QString::fromUtf8("musicAlbumBox"));
        horizontalLayout_3 = new QHBoxLayout(musicAlbumBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        albumNameLabel = new QLabel(musicAlbumBox);
        albumNameLabel->setObjectName(QString::fromUtf8("albumNameLabel"));

        horizontalLayout_3->addWidget(albumNameLabel);


        horizontalLayout->addWidget(musicAlbumBox);


        retranslateUi(ListItemBox);

        QMetaObject::connectSlotsByName(ListItemBox);
    } // setupUi

    void retranslateUi(QWidget *ListItemBox)
    {
        ListItemBox->setWindowTitle(QCoreApplication::translate("ListItemBox", "Form", nullptr));
        likeBtn->setText(QString());
        musicNameLabel->setText(QCoreApplication::translate("ListItemBox", "\346\235\216\347\231\275", nullptr));
        VIPLabel->setText(QCoreApplication::translate("ListItemBox", "VIP", nullptr));
        SQLabel->setText(QCoreApplication::translate("ListItemBox", "SQ", nullptr));
        musicSingerLabel->setText(QCoreApplication::translate("ListItemBox", "\346\235\216\350\215\243\346\265\251", nullptr));
        albumNameLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ListItemBox: public Ui_ListItemBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTITEMBOX_H
