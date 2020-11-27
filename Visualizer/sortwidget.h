#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QWidget>
#include<QtWidgets>
#include"sorting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SortWidget; }
QT_END_NAMESPACE

class SortWidget : public QWidget
{
    Q_OBJECT

public:
    SortWidget(QWidget *parent = nullptr);
    ~SortWidget();

private slots:
    void on_slider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_resetButton_clicked();

    void on_delaySlider_valueChanged(int value);

    void on_stopButton_clicked();

    void on_quitButton_clicked();

    void on_chooseData_currentIndexChanged(int index);

    void on_choosePoints_currentIndexChanged(int index);

private:
    Ui::SortWidget *ui;
    QGraphicsScene *visualizingScene;
    Sorting *sorting;
};
#endif // SORTWIDGET_H
