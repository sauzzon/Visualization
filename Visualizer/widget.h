#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QtWidgets>

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

private:
    Ui::Widget *ui;
    QGraphicsScene *visualizingScene;

    void createRectangles();

    int noOfRectangles;

    std::vector<QGraphicsRectItem*> rectangles;
    std::vector<double> rectHeight;
    double rectWidth;
    size_t findMinimum(size_t startingIndex);
    double sceneHeight;
    double sceneWidth;

    double heightDiff;
    void selectionSort();
    void updateDisplay();

};
#endif // WIDGET_H
