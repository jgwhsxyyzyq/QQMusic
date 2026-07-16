/********************************************************************************
** Form generated from reading UI file 'musicslide.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICSLIDE_H
#define UI_MUSICSLIDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicSlide
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *outLine;
    QFrame *inLine;

    void setupUi(QWidget *MusicSlide)
    {
        if (MusicSlide->objectName().isEmpty())
            MusicSlide->setObjectName(QString::fromUtf8("MusicSlide"));
        MusicSlide->resize(800, 20);
        horizontalLayout = new QHBoxLayout(MusicSlide);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        outLine = new QFrame(MusicSlide);
        outLine->setObjectName(QString::fromUtf8("outLine"));
        outLine->setStyleSheet(QString::fromUtf8("#outLine{\n"
"background-color:#1ECC94;\n"
"}"));
        outLine->setFrameShape(QFrame::StyledPanel);
        outLine->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(outLine);

        inLine = new QFrame(MusicSlide);
        inLine->setObjectName(QString::fromUtf8("inLine"));
        inLine->setStyleSheet(QString::fromUtf8("#inLine\n"
"{\n"
" background-color:#EBEEF5;\n"
"}"));
        inLine->setFrameShape(QFrame::StyledPanel);
        inLine->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(inLine);


        retranslateUi(MusicSlide);

        QMetaObject::connectSlotsByName(MusicSlide);
    } // setupUi

    void retranslateUi(QWidget *MusicSlide)
    {
        MusicSlide->setWindowTitle(QCoreApplication::translate("MusicSlide", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicSlide: public Ui_MusicSlide {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICSLIDE_H
