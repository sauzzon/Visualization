#include "treewidget.h"
#include "ui_treewidget.h"

TreeWidget::TreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeWidget)
{
    ui->setupUi(this);
    tree=new BST;
    mainScene=new QGraphicsScene();
    mainSceneHeight=ui->sceneFrame->size().height();
    mainSceneWidth=ui->sceneFrame->size().width();
    ui->sceneFrame->setScene(mainScene);
    tree->initializer(mainScene,mainSceneWidth,mainSceneHeight);
}

TreeWidget::~TreeWidget()
{
    delete ui;
}

void TreeWidget::on_quitButton_clicked()
{
    hide();
}

void TreeWidget::on_insertButton_clicked()
{
    QString textToInsert=ui->insertValue->text();
    int num=textToInsert.toInt();
    tree->Insert(num);
    ui->insertValue->setText("");
}

void TreeWidget::on_searchButton_clicked()
{
    QString textToInsert=ui->searchValue->text();
    int num=textToInsert.toInt();
    tree->Search(num);
    ui->searchValue->setText("");
}
