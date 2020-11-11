#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    visualizingScene = new QGraphicsScene(this);
    ui->visualizingBackground->setScene(visualizingScene);

}

Widget::~Widget()
{
    delete ui;
}

