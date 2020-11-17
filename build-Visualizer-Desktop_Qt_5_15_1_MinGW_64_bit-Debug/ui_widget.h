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
#include <QtWidgets/QComboBox>
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
    QPushButton *resetButton;
    QLabel *delayLabel;
    QSlider *delaySlider;
    QPushButton *stopButton;
    QComboBox *comboBox;
    QLabel *label_2;

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
        slider->setGeometry(QRect(1120, 170, 171, 31));
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
        label->setGeometry(QRect(1140, 130, 141, 21));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1070, 310, 81, 51));
        pushButton->setFlat(false);
        resetButton = new QPushButton(Widget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(1160, 310, 81, 51));
        delayLabel = new QLabel(Widget);
        delayLabel->setObjectName(QString::fromUtf8("delayLabel"));
        delayLabel->setGeometry(QRect(1180, 220, 81, 21));
        delaySlider = new QSlider(Widget);
        delaySlider->setObjectName(QString::fromUtf8("delaySlider"));
        delaySlider->setGeometry(QRect(1120, 250, 171, 31));
        delaySlider->setMinimum(0);
        delaySlider->setMaximum(100);
        delaySlider->setSingleStep(10);
        delaySlider->setValue(10);
        delaySlider->setOrientation(Qt::Horizontal);
        stopButton = new QPushButton(Widget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(1250, 310, 81, 51));
        comboBox = new QComboBox(Widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(1170, 50, 111, 22));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1080, 50, 81, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Number Of Elements = 125", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Click to Sort ", nullptr));
        resetButton->setText(QCoreApplication::translate("Widget", "Reset", nullptr));
        delayLabel->setText(QCoreApplication::translate("Widget", "Delay = 10ms", nullptr));
        stopButton->setText(QCoreApplication::translate("Widget", "Stop", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "Selection Sort", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "Quick Sort", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Widget", "Merge Sort", nullptr));

        label_2->setText(QCoreApplication::translate("Widget", "Select Algorithm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
