#include "widget.h"
#include "ui_widget.h"
#include<iostream>
#include<random>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//creating visualizing scene and setting it to visualizing background
    visualizingScene = new QGraphicsScene(this);
    ui->visualizingBackground->setScene(visualizingScene);
    visualizingScene->setBackgroundBrush(QBrush(QColor(220,220,220)));

//height and width of main scene
    sceneHeight = ui->visualizingBackground->size().height()-20;
    sceneWidth = ui->visualizingBackground->size().width()-50;

//creating columns for sorting
    noOfRectangles = 125;
    createRectangles();

}

void Widget::createRectangles(){


    rectWidth = sceneWidth / noOfRectangles;

//resize sets the std::vector size
    rectangles.resize(noOfRectangles);

//heightDiff is the difference in height between two consecutive sorted rectangles
    heightDiff = sceneHeight / noOfRectangles;

//putting height of rectangles in vector called rectHeight
//push_back is a method in std::vector to insert elements from back

        double height = heightDiff;
    for(int i=0;i<noOfRectangles;i++){
        rectHeight.push_back(height);
        height += heightDiff;

    }

// The sorted rectHeight is mixed

//This is a random number engine class that generates pseudo-random numbers. (Found From StackOverflow)
    auto rng = std::default_random_engine {};
    std::shuffle(rectHeight.begin(), rectHeight.end(), rng);
    updateDisplay();
}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_slider_valueChanged(int value)
{
    ui->label->setText("Number Of Elements = "+ QString::number(value));
    noOfRectangles = value;
    rectHeight.clear();
    createRectangles();
}

void Widget::on_pushButton_clicked()
{
    selectionSort();
}
size_t Widget::findMinimum(size_t startingIndex)
{
    int min=rectHeight.at(startingIndex);
    size_t minIndex =startingIndex;
    for(size_t i=startingIndex;i<rectHeight.size();i++)
    {
        if(rectHeight.at(i)<min)
        {
            minIndex=i;
            min=rectHeight.at(i);
        }
    }
    return minIndex;
}
void Widget::selectionSort()
{
    for(size_t i=0;i<rectHeight.size();i++)
    {
        size_t minIndex = findMinimum(i);
        std::swap(rectHeight[i],rectHeight[minIndex]);
        Sleep(200);
        updateDisplay();


 //Processes all pending events for the calling thread  until there are no more events to process.
        QApplication::processEvents();

    }


}
void Widget::updateDisplay()
{
    visualizingScene->clear();
    //displaying the rectangles in scene
        auto j = 0;
        auto k = 0.0;

    //easiest way of iterating in std::vector
        for(auto &p :rectangles)
        {
            p = new QGraphicsRectItem;
            p->setRect(k, (sceneHeight - rectHeight[j]), rectWidth , rectHeight[j]);
            p->setBrush(QBrush(QColor(135,235,231)));

            p->setPen(QPen(QColor(0,0,0)));

            visualizingScene->addItem(p);
            j++;
            k += rectWidth;

        }

}
