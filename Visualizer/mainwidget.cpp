#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_sortPushButton_clicked()
{
    sortWidget = new SortWidget(this);
    sortWidget->show();

}

void MainWidget::on_treePushButton_clicked()
{

}
