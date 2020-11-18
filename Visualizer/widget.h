#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QtWidgets>
#include"sorting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_slider_valueChanged(int value);

    void on_pushButton_clicked();

    void on_resetButton_clicked();

    void on_delaySlider_valueChanged(int value);

    void on_stopButton_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *visualizingScene;
    Sorting *sorting;
};
#endif // WIDGET_H
