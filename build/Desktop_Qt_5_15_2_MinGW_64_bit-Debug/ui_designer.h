/********************************************************************************
** Form generated from reading UI file 'designer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGNER_H
#define UI_DESIGNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Designer
{
public:

    void setupUi(QWidget *Designer)
    {
        if (Designer->objectName().isEmpty())
            Designer->setObjectName(QString::fromUtf8("Designer"));
        Designer->resize(150, 200);

        retranslateUi(Designer);

        QMetaObject::connectSlotsByName(Designer);
    } // setupUi

    void retranslateUi(QWidget *Designer)
    {
        Designer->setWindowTitle(QCoreApplication::translate("Designer", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Designer: public Ui_Designer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGNER_H
