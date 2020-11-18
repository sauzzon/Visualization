#include "treewidget.h"
#include "ui_treewidget.h"

TreeWidget::TreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeWidget)
{
    ui->setupUi(this);
}

TreeWidget::~TreeWidget()
{
    delete ui;
}

void TreeWidget::on_quitButton_clicked()
{
    hide();
}
