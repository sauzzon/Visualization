#include "widget.h"
#include "ui_widget.h"

#define GREY QColor(220,220,220)


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//creating visualizing scene and setting it to visualizing background
    visualizingScene = new QGraphicsScene(this);
    ui->visualizingBackground->setScene(visualizingScene);
    visualizingScene->setBackgroundBrush(QBrush(GREY));

    double sceneHeight = ui->visualizingBackground->size().height();
    double sceneWidth = ui->visualizingBackground->size().width();

    sorting = new Sorting;
    sorting->initialize(sceneHeight,sceneWidth,visualizingScene);

}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_slider_valueChanged(int value)
{
    ui->label->setText("Number Of Elements = "+ QString::number(value));
    sorting->setRectangles(value);
    sorting->resetRectangles();

}

void Widget::on_pushButton_clicked()
{
    if(ui->comboBox->currentIndex()==0)
       sorting->selectionSort();
    else if(ui->comboBox->currentIndex()==1)
        sorting->switchToQuickSort();
    else if(ui->comboBox->currentIndex()==2)
       sorting->switchToMergeSort();
}

void Widget::on_resetButton_clicked()
{
   sorting->resetRectangles();
}

void Widget::on_delaySlider_valueChanged(int value)
{
    ui->delayLabel->setText("Delay = "+ QString::number(value)+"ms");
    sorting->setDelay(value);
}

void Widget::on_stopButton_clicked()
{
    sorting->setStopButton();
}

