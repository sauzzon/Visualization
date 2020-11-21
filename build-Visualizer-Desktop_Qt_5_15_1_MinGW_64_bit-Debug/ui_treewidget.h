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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreeWidget
{
public:
    QGraphicsView *sceneFrame;
    QPushButton *quitButton;
    QLineEdit *insertValue;
    QPushButton *insertButton;
    QLineEdit *searchValue;
    QPushButton *searchButton;

    void setupUi(QWidget *TreeWidget)
    {
        if (TreeWidget->objectName().isEmpty())
            TreeWidget->setObjectName(QString::fromUtf8("TreeWidget"));
        TreeWidget->resize(1374, 720);
        sceneFrame = new QGraphicsView(TreeWidget);
        sceneFrame->setObjectName(QString::fromUtf8("sceneFrame"));
        sceneFrame->setGeometry(QRect(30, 30, 1161, 651));
        sceneFrame->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sceneFrame->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        quitButton = new QPushButton(TreeWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(1250, 310, 75, 41));
        insertValue = new QLineEdit(TreeWidget);
        insertValue->setObjectName(QString::fromUtf8("insertValue"));
        insertValue->setGeometry(QRect(1250, 89, 81, 21));
        insertButton = new QPushButton(TreeWidget);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));
        insertButton->setGeometry(QRect(1250, 120, 75, 23));
        searchValue = new QLineEdit(TreeWidget);
        searchValue->setObjectName(QString::fromUtf8("searchValue"));
        searchValue->setGeometry(QRect(1250, 150, 81, 20));
        searchButton = new QPushButton(TreeWidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(1250, 180, 71, 23));

        retranslateUi(TreeWidget);

        QMetaObject::connectSlotsByName(TreeWidget);
    } // setupUi

    void retranslateUi(QWidget *TreeWidget)
    {
        TreeWidget->setWindowTitle(QCoreApplication::translate("TreeWidget", "Form", nullptr));
        quitButton->setText(QCoreApplication::translate("TreeWidget", "Quit", nullptr));
        insertButton->setText(QCoreApplication::translate("TreeWidget", "Insert", nullptr));
        searchButton->setText(QCoreApplication::translate("TreeWidget", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreeWidget: public Ui_TreeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEWIDGET_H
