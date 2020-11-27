/********************************************************************************
** Form generated from reading UI file 'sortwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTWIDGET_H
#define UI_SORTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SortWidget
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
    QPushButton *quitButton;
    QLabel *label_3;
    QComboBox *chooseData;
    QComboBox *choosePoints;
    QLabel *choosePointsLabel;

    void setupUi(QWidget *SortWidget)
    {
        if (SortWidget->objectName().isEmpty())
            SortWidget->setObjectName(QString::fromUtf8("SortWidget"));
        SortWidget->resize(1374, 720);
        visualizingBackground = new QGraphicsView(SortWidget);
        visualizingBackground->setObjectName(QString::fromUtf8("visualizingBackground"));
        visualizingBackground->setGeometry(QRect(1, 1, 1000, 700));
        visualizingBackground->setMinimumSize(QSize(1000, 700));
        visualizingBackground->setFrameShape(QFrame::NoFrame);
        visualizingBackground->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        visualizingBackground->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        slider = new QSlider(SortWidget);
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
        label = new QLabel(SortWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1140, 130, 141, 21));
        pushButton = new QPushButton(SortWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1070, 310, 81, 51));
        pushButton->setFlat(false);
        resetButton = new QPushButton(SortWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(1160, 310, 81, 51));
        delayLabel = new QLabel(SortWidget);
        delayLabel->setObjectName(QString::fromUtf8("delayLabel"));
        delayLabel->setGeometry(QRect(1180, 220, 81, 21));
        delaySlider = new QSlider(SortWidget);
        delaySlider->setObjectName(QString::fromUtf8("delaySlider"));
        delaySlider->setGeometry(QRect(1120, 250, 171, 31));
        delaySlider->setMinimum(0);
        delaySlider->setMaximum(100);
        delaySlider->setSingleStep(10);
        delaySlider->setValue(10);
        delaySlider->setOrientation(Qt::Horizontal);
        stopButton = new QPushButton(SortWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(1250, 310, 81, 51));
        comboBox = new QComboBox(SortWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(1170, 90, 111, 22));
        label_2 = new QLabel(SortWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1080, 90, 81, 21));
        quitButton = new QPushButton(SortWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(1160, 390, 81, 41));
        label_3 = new QLabel(SortWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1080, 40, 81, 21));
        chooseData = new QComboBox(SortWidget);
        chooseData->addItem(QString());
        chooseData->addItem(QString());
        chooseData->setObjectName(QString::fromUtf8("chooseData"));
        chooseData->setGeometry(QRect(1170, 40, 111, 22));
        choosePoints = new QComboBox(SortWidget);
        choosePoints->addItem(QString());
        choosePoints->addItem(QString());
        choosePoints->setObjectName(QString::fromUtf8("choosePoints"));
        choosePoints->setGeometry(QRect(1170, 100, 111, 22));
        choosePointsLabel = new QLabel(SortWidget);
        choosePointsLabel->setObjectName(QString::fromUtf8("choosePointsLabel"));
        choosePointsLabel->setGeometry(QRect(1080, 100, 91, 21));

        retranslateUi(SortWidget);

        comboBox->setCurrentIndex(0);
        chooseData->setCurrentIndex(0);
        choosePoints->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SortWidget);
    } // setupUi

    void retranslateUi(QWidget *SortWidget)
    {
        SortWidget->setWindowTitle(QCoreApplication::translate("SortWidget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("SortWidget", "Number Of Elements = 125", nullptr));
        pushButton->setText(QCoreApplication::translate("SortWidget", "Click to Sort ", nullptr));
        resetButton->setText(QCoreApplication::translate("SortWidget", "Reset", nullptr));
        delayLabel->setText(QCoreApplication::translate("SortWidget", "Delay = 10ms", nullptr));
        stopButton->setText(QCoreApplication::translate("SortWidget", "Stop", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("SortWidget", "Selection Sort", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("SortWidget", "Quick Sort", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("SortWidget", "Merge Sort", nullptr));

        label_2->setText(QCoreApplication::translate("SortWidget", "Select Algorithm", nullptr));
        quitButton->setText(QCoreApplication::translate("SortWidget", "Quit", nullptr));
        label_3->setText(QCoreApplication::translate("SortWidget", "Choose Data", nullptr));
        chooseData->setItemText(0, QCoreApplication::translate("SortWidget", "Random Data", nullptr));
        chooseData->setItemText(1, QCoreApplication::translate("SortWidget", "Fantasy", nullptr));

        choosePoints->setItemText(0, QCoreApplication::translate("SortWidget", "Total Points", nullptr));
        choosePoints->setItemText(1, QCoreApplication::translate("SortWidget", "Gameweek Points", nullptr));

        choosePointsLabel->setText(QCoreApplication::translate("SortWidget", "Total/Gameweek", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SortWidget: public Ui_SortWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTWIDGET_H
