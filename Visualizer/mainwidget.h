#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "sortwidget.h"
#include "treewidget.h"

#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkReply>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void on_sortPushButton_clicked();

    void on_treePushButton_clicked();

    void dataDownloadFinished(QNetworkReply*);

private:
    Ui::MainWidget *ui;
    SortWidget* sortWidget;
    TreeWidget* treeWidget;

    void connectServer();
    QString myURL ="https://fantasy.premierleague.com/api/leagues-classic/196371/standings/";
};

#endif // MAINWIDGET_H
