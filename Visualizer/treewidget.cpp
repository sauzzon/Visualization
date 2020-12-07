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
    treeStatus = ui->treeStatus;
    tree->initializer(mainScene,mainSceneWidth,mainSceneHeight,treeStatus);
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
    ui->treeStatus->setText("INSERTING");
    QString values = ui->insertValue->text();
    QStringList valueList = values.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    QStringListIterator iterator(valueList);

    while (iterator.hasNext())
    {
        tree->Insert(iterator.next().toInt()); // inserts 0 if text isn't an int
    }
//    QString textToInsert=ui->insertValue->text();
//    int num=textToInsert.toInt();
//    tree->Insert(num);
    ui->insertValue->setText("");
}

void TreeWidget::on_searchButton_clicked()
{
    ui->treeStatus->setText("SEARCHING");
    QString textToInsert=ui->searchValue->text();
    int num=textToInsert.toInt();
    tree->Search(num);
    ui->searchValue->setText("");
}

void TreeWidget::on_horizontalSlider_valueChanged(int value)
{
    ui->delayLabel->setText("Delay = "+ QString::number(value)+" ms");
    tree->setDelay(value);
}

void TreeWidget::on_deleteButton_clicked()
{
    ui->treeStatus->setText("DELETING");
    QString textToInsert=ui->deleteValue->text();
    int num=textToInsert.toInt();
    tree->Delete(num);
    ui->deleteValue->setText("");

}

void TreeWidget::on_preorderButton_clicked()
{
    tree->preorderTraversal();
}

void TreeWidget::on_postorderButton_clicked()
{
    tree->postorderTraversal();
}

void TreeWidget::on_inorderButton_clicked()
{
    tree->inorderTraversal();
}
