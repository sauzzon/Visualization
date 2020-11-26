#include "sortwidget.h"
#include "ui_sortwidget.h"

#define GREY QColor(220,220,220)


SortWidget::SortWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SortWidget)
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


SortWidget::~SortWidget()
{
    delete ui;
}


void SortWidget::on_slider_valueChanged(int value)
{
    ui->label->setText("Number Of Elements = "+ QString::number(value));
    sorting->setRectangles(value);
    sorting->resetRectangles();

}

void SortWidget::on_pushButton_clicked()
{
    if(ui->chooseData->currentIndex()==1)
        sorting->selectionSort();
    else
    {
        if(ui->comboBox->currentIndex()==0)
           sorting->selectionSort();
        else if(ui->comboBox->currentIndex()==1)
            sorting->switchToQuickSort();
        else if(ui->comboBox->currentIndex()==2)
           sorting->switchToMergeSort();
    }
}

void SortWidget::on_resetButton_clicked()
{
   if(ui->chooseData->currentIndex()==0)
    sorting->resetRectangles();
   else if(ui->chooseData->currentIndex()==1)
    sorting->resetRectanglesFantasy();
}

void SortWidget::on_delaySlider_valueChanged(int value)
{
    ui->delayLabel->setText("Delay = "+ QString::number(value)+"ms");
    sorting->setDelay(value);
}

void SortWidget::on_stopButton_clicked()
{
    sorting->setStopButton();
}


void SortWidget::on_quitButton_clicked()
{
    hide();
}

void SortWidget::on_chooseData_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->label->show();
        ui->label_2->show();
        ui->comboBox->show();
        ui->slider->show();
        ui->delaySlider->setGeometry(1120,250,1171,31);
        ui->delayLabel->setGeometry(1180,220,81,21);
        sorting->setFantasySelected(false);
        sorting->resetRectangles();
    }
    else if(index==1)
    {
        ui->label->hide();
        ui->label_2->hide();
        ui->comboBox->hide();
        ui->slider->hide();
        ui->delayLabel->setGeometry(1150,140,141,21);
        ui->delaySlider->setGeometry(1120,180,171,31);
        sorting->setFantasySelected(true);
        sorting->switchToFantasy();
    }
}
