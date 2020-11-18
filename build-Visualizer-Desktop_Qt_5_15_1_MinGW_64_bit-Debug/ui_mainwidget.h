/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QPushButton *sortPushButton;
    QPushButton *treePushButton;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(1374, 720);
        sortPushButton = new QPushButton(MainWidget);
        sortPushButton->setObjectName(QString::fromUtf8("sortPushButton"));
        sortPushButton->setGeometry(QRect(640, 210, 181, 71));
        treePushButton = new QPushButton(MainWidget);
        treePushButton->setObjectName(QString::fromUtf8("treePushButton"));
        treePushButton->setGeometry(QRect(640, 360, 181, 71));

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "Form", nullptr));
        sortPushButton->setText(QCoreApplication::translate("MainWidget", "Sort", nullptr));
        treePushButton->setText(QCoreApplication::translate("MainWidget", "Tree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
