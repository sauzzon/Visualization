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

    double sceneHeight;
    double sceneWidth;

    double heightDiff;
    bool isSorted;

};
#endif // WIDGET_H
