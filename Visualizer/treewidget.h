#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>

namespace Ui {
class TreeWidget;
}

class TreeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TreeWidget(QWidget *parent = nullptr);
    ~TreeWidget();

private slots:
    void on_quitButton_clicked();

private:
    Ui::TreeWidget *ui;
};

#endif // TREEWIDGET_H
