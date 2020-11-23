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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
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
    QSlider *horizontalSlider;
    QLabel *delayLabel;
    QLineEdit *deleteValue;
    QPushButton *deleteButton;
    QLabel *treeStatus;

    void setupUi(QWidget *TreeWidget)
    {
        if (TreeWidget->objectName().isEmpty())
            TreeWidget->setObjectName(QString::fromUtf8("TreeWidget"));
        TreeWidget->resize(1374, 720);
        sceneFrame = new QGraphicsView(TreeWidget);
        sceneFrame->setObjectName(QString::fromUtf8("sceneFrame"));
        sceneFrame->setGeometry(QRect(30, 40, 1161, 641));
        sceneFrame->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sceneFrame->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        quitButton = new QPushButton(TreeWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(1250, 350, 75, 31));
        insertValue = new QLineEdit(TreeWidget);
        insertValue->setObjectName(QString::fromUtf8("insertValue"));
        insertValue->setGeometry(QRect(1230, 60, 121, 21));
        insertButton = new QPushButton(TreeWidget);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));
        insertButton->setGeometry(QRect(1250, 90, 81, 23));
        searchValue = new QLineEdit(TreeWidget);
        searchValue->setObjectName(QString::fromUtf8("searchValue"));
        searchValue->setGeometry(QRect(1230, 130, 121, 20));
        searchButton = new QPushButton(TreeWidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(1250, 160, 81, 23));
        horizontalSlider = new QSlider(TreeWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(1230, 310, 121, 22));
        horizontalSlider->setMinimum(100);
        horizontalSlider->setMaximum(3000);
        horizontalSlider->setSingleStep(100);
        horizontalSlider->setPageStep(100);
        horizontalSlider->setValue(1000);
        horizontalSlider->setOrientation(Qt::Horizontal);
        delayLabel = new QLabel(TreeWidget);
        delayLabel->setObjectName(QString::fromUtf8("delayLabel"));
        delayLabel->setGeometry(QRect(1250, 290, 101, 16));
        deleteValue = new QLineEdit(TreeWidget);
        deleteValue->setObjectName(QString::fromUtf8("deleteValue"));
        deleteValue->setGeometry(QRect(1230, 200, 121, 20));
        deleteButton = new QPushButton(TreeWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(1250, 230, 75, 23));
        treeStatus = new QLabel(TreeWidget);
        treeStatus->setObjectName(QString::fromUtf8("treeStatus"));
        treeStatus->setGeometry(QRect(990, 10, 171, 21));
        QFont font;
        font.setPointSize(14);
        treeStatus->setFont(font);

        retranslateUi(TreeWidget);

        QMetaObject::connectSlotsByName(TreeWidget);
    } // setupUi

    void retranslateUi(QWidget *TreeWidget)
    {
        TreeWidget->setWindowTitle(QCoreApplication::translate("TreeWidget", "Form", nullptr));
        quitButton->setText(QCoreApplication::translate("TreeWidget", "Quit", nullptr));
        insertButton->setText(QCoreApplication::translate("TreeWidget", "Insert", nullptr));
        searchButton->setText(QCoreApplication::translate("TreeWidget", "Search", nullptr));
        delayLabel->setText(QCoreApplication::translate("TreeWidget", "Delay = 1000 ms", nullptr));
        deleteButton->setText(QCoreApplication::translate("TreeWidget", "Delete", nullptr));
        treeStatus->setText(QCoreApplication::translate("TreeWidget", "Binary Search Tree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreeWidget: public Ui_TreeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEWIDGET_H
