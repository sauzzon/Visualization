/********************************************************************************
** Form generated from reading UI file 'treewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREEWIDGET_H
#define UI_TREEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreeWidget
{
public:
    QGraphicsView *graphicsView;
    QPushButton *quitButton;

    void setupUi(QWidget *TreeWidget)
    {
        if (TreeWidget->objectName().isEmpty())
            TreeWidget->setObjectName(QString::fromUtf8("TreeWidget"));
        TreeWidget->resize(1374, 720);
        graphicsView = new QGraphicsView(TreeWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(50, 50, 1121, 621));
        quitButton = new QPushButton(TreeWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(1210, 230, 75, 51));

        retranslateUi(TreeWidget);

        QMetaObject::connectSlotsByName(TreeWidget);
    } // setupUi

    void retranslateUi(QWidget *TreeWidget)
    {
        TreeWidget->setWindowTitle(QCoreApplication::translate("TreeWidget", "Form", nullptr));
        quitButton->setText(QCoreApplication::translate("TreeWidget", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreeWidget: public Ui_TreeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEWIDGET_H
