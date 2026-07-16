/********************************************************************************
** Form generated from reading UI file 'recbox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECBOX_H
#define UI_RECBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecBox
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *leftPage;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btUp;
    QWidget *musicContent;
    QVBoxLayout *verticalLayout;
    QWidget *recListUp;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *recListUpHLayout;
    QWidget *recListDown;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *recListDownHLayout;
    QWidget *rightPage;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btDown;

    void setupUi(QWidget *RecBox)
    {
        if (RecBox->objectName().isEmpty())
            RecBox->setObjectName(QString::fromUtf8("RecBox"));
        RecBox->resize(685, 440);
        horizontalLayout = new QHBoxLayout(RecBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leftPage = new QWidget(RecBox);
        leftPage->setObjectName(QString::fromUtf8("leftPage"));
        leftPage->setMinimumSize(QSize(30, 0));
        leftPage->setMaximumSize(QSize(30, 16777215));
        leftPage->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" background-repeat:no-repeat;\n"
" border:none;\n"
" background-image : url(:/images/up_page.png);\n"
" background-position:center center;\n"
"}\n"
"QPushButton:hover\n"
"{background-color: #1ECD97;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(leftPage);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btUp = new QPushButton(leftPage);
        btUp->setObjectName(QString::fromUtf8("btUp"));
        btUp->setMinimumSize(QSize(0, 220));
        btUp->setMaximumSize(QSize(25, 16777215));

        horizontalLayout_2->addWidget(btUp);


        horizontalLayout->addWidget(leftPage);

        musicContent = new QWidget(RecBox);
        musicContent->setObjectName(QString::fromUtf8("musicContent"));
        verticalLayout = new QVBoxLayout(musicContent);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        recListUp = new QWidget(musicContent);
        recListUp->setObjectName(QString::fromUtf8("recListUp"));
        horizontalLayout_5 = new QHBoxLayout(recListUp);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        recListUpHLayout = new QHBoxLayout();
        recListUpHLayout->setObjectName(QString::fromUtf8("recListUpHLayout"));

        horizontalLayout_5->addLayout(recListUpHLayout);


        verticalLayout->addWidget(recListUp);

        recListDown = new QWidget(musicContent);
        recListDown->setObjectName(QString::fromUtf8("recListDown"));
        horizontalLayout_4 = new QHBoxLayout(recListDown);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        recListDownHLayout = new QHBoxLayout();
        recListDownHLayout->setObjectName(QString::fromUtf8("recListDownHLayout"));

        horizontalLayout_4->addLayout(recListDownHLayout);


        verticalLayout->addWidget(recListDown);


        horizontalLayout->addWidget(musicContent);

        rightPage = new QWidget(RecBox);
        rightPage->setObjectName(QString::fromUtf8("rightPage"));
        rightPage->setMinimumSize(QSize(30, 0));
        rightPage->setMaximumSize(QSize(30, 16777215));
        rightPage->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
" background-repeat:no-repeat;\n"
" border:none;\n"
" background-image : url(:/images/down_page.png);\n"
" background-position:center center;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
" background-color: #1ECD97;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(rightPage);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btDown = new QPushButton(rightPage);
        btDown->setObjectName(QString::fromUtf8("btDown"));
        btDown->setMinimumSize(QSize(25, 220));
        btDown->setMaximumSize(QSize(25, 16777215));

        horizontalLayout_3->addWidget(btDown);


        horizontalLayout->addWidget(rightPage);


        retranslateUi(RecBox);

        QMetaObject::connectSlotsByName(RecBox);
    } // setupUi

    void retranslateUi(QWidget *RecBox)
    {
        RecBox->setWindowTitle(QCoreApplication::translate("RecBox", "Form", nullptr));
        btUp->setText(QString());
        btDown->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RecBox: public Ui_RecBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECBOX_H
