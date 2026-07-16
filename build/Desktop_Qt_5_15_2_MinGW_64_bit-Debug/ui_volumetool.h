/********************************************************************************
** Form generated from reading UI file 'volumetool.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLUMETOOL_H
#define UI_VOLUMETOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VolumeTool
{
public:
    QWidget *volumeWidget;
    QPushButton *silenceBtn;
    QLabel *volumeRatio;
    QWidget *sliderBox;
    QFrame *inLine;
    QFrame *outLine;
    QPushButton *sliderBtn;

    void setupUi(QWidget *VolumeTool)
    {
        if (VolumeTool->objectName().isEmpty())
            VolumeTool->setObjectName(QString::fromUtf8("VolumeTool"));
        VolumeTool->resize(100, 350);
        volumeWidget = new QWidget(VolumeTool);
        volumeWidget->setObjectName(QString::fromUtf8("volumeWidget"));
        volumeWidget->setGeometry(QRect(10, 40, 80, 300));
        volumeWidget->setStyleSheet(QString::fromUtf8("#volumeWidget{\n"
" background-color:#ffffff;\n"
" border-radius:5px;\n"
"}"));
        silenceBtn = new QPushButton(volumeWidget);
        silenceBtn->setObjectName(QString::fromUtf8("silenceBtn"));
        silenceBtn->setGeometry(QRect(0, 250, 80, 45));
        silenceBtn->setMinimumSize(QSize(80, 45));
        silenceBtn->setMaximumSize(QSize(80, 46));
        silenceBtn->setStyleSheet(QString::fromUtf8("#silenceBtn\n"
"{\n"
" border:none;\n"
"}\n"
"#silenceBtn:hover{\n"
" background-color:#F0F0F0;\n"
"}"));
        volumeRatio = new QLabel(volumeWidget);
        volumeRatio->setObjectName(QString::fromUtf8("volumeRatio"));
        volumeRatio->setGeometry(QRect(20, 210, 40, 30));
        volumeRatio->setMinimumSize(QSize(0, 30));
        volumeRatio->setMaximumSize(QSize(16777215, 30));
        volumeRatio->setAlignment(Qt::AlignCenter);
        sliderBox = new QWidget(volumeWidget);
        sliderBox->setObjectName(QString::fromUtf8("sliderBox"));
        sliderBox->setGeometry(QRect(0, 0, 80, 255));
        inLine = new QFrame(sliderBox);
        inLine->setObjectName(QString::fromUtf8("inLine"));
        inLine->setGeometry(QRect(38, 25, 4, 180));
        inLine->setStyleSheet(QString::fromUtf8("#inLine\n"
"{\n"
" background-color:#ECECEC;\n"
"}"));
        inLine->setFrameShape(QFrame::StyledPanel);
        inLine->setFrameShadow(QFrame::Raised);
        outLine = new QFrame(sliderBox);
        outLine->setObjectName(QString::fromUtf8("outLine"));
        outLine->setGeometry(QRect(38, 25, 4, 180));
        outLine->setStyleSheet(QString::fromUtf8("#outLine\n"
"{\n"
" background-color:#1ECC94;\n"
"}"));
        outLine->setFrameShape(QFrame::StyledPanel);
        outLine->setFrameShadow(QFrame::Raised);
        sliderBtn = new QPushButton(sliderBox);
        sliderBtn->setObjectName(QString::fromUtf8("sliderBtn"));
        sliderBtn->setGeometry(QRect(33, 20, 14, 14));
        sliderBtn->setStyleSheet(QString::fromUtf8("#sliderBtn\n"
"{\n"
" background-color:#1ECC94;\n"
" border-radius:7px;\n"
"}"));

        retranslateUi(VolumeTool);

        QMetaObject::connectSlotsByName(VolumeTool);
    } // setupUi

    void retranslateUi(QWidget *VolumeTool)
    {
        VolumeTool->setWindowTitle(QCoreApplication::translate("VolumeTool", "Form", nullptr));
        silenceBtn->setText(QString());
        volumeRatio->setText(QCoreApplication::translate("VolumeTool", "25%", nullptr));
        sliderBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VolumeTool: public Ui_VolumeTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLUMETOOL_H
