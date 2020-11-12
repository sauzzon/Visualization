/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGraphicsView *visualizingBackground;
    QSlider *slider;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1374, 720);
        visualizingBackground = new QGraphicsView(Widget);
        visualizingBackground->setObjectName(QString::fromUtf8("visualizingBackground"));
        visualizingBackground->setGeometry(QRect(1, 1, 1000, 700));
        visualizingBackground->setMinimumSize(QSize(1000, 700));
        visualizingBackground->setFrameShape(QFrame::NoFrame);
        visualizingBackground->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        visualizingBackground->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        slider = new QSlider(Widget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setGeometry(QRect(1110, 70, 181, 61));
        slider->setMinimum(10);
        slider->setMaximum(250);
        slider->setSingleStep(10);
        slider->setPageStep(10);
        slider->setValue(125);
        slider->setSliderPosition(125);
        slider->setTracking(true);
        slider->setOrientation(Qt::Horizontal);
        slider->setTickPosition(QSlider::NoTicks);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1130, 30, 141, 21));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1150, 220, 81, 51));
        pushButton->setFlat(false);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Number Of Elements = 125", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Click to Sort ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
