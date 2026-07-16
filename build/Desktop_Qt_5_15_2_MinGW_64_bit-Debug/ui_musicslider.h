/********************************************************************************
** Form generated from reading UI file 'musicslider.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICSLIDER_H
#define UI_MUSICSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicSlider
{
public:

    void setupUi(QWidget *MusicSlider)
    {
        if (MusicSlider->objectName().isEmpty())
            MusicSlider->setObjectName(QString::fromUtf8("MusicSlider"));
        MusicSlider->resize(400, 300);

        retranslateUi(MusicSlider);

        QMetaObject::connectSlotsByName(MusicSlider);
    } // setupUi

    void retranslateUi(QWidget *MusicSlider)
    {
        MusicSlider->setWindowTitle(QCoreApplication::translate("MusicSlider", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicSlider: public Ui_MusicSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICSLIDER_H
