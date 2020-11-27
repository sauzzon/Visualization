#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    readJSON();
}

void MainWidget::readJSON(){

        QNetworkAccessManager* man = new QNetworkAccessManager(this);
        connect(man,&QNetworkAccessManager::finished,this,&MainWidget::dataDownloadFinished);
        const QUrl url = QUrl(myURL);
        QNetworkRequest request(url);
        man->get(request);
}

void MainWidget::dataDownloadFinished(QNetworkReply* reply){
    QByteArray jsonData;

//reading reply
    jsonData = reply->readAll();

//creating JSON object and initializing to json array
      QJsonDocument myDoc=QJsonDocument::fromJson(jsonData);
      QJsonObject myObj=myDoc.object();
      QJsonValue standingsValue = myObj.value("standings");
      QJsonObject standings =standingsValue.toObject();
      QJsonValue resultValue = standings.value("results");
      QJsonArray array = resultValue.toArray();

// iterating through json array and putting the name of country and its population in vector
       foreach (const QJsonValue & v, array){
                weeklyPoints.push_back(v.toObject().value("event_total").toDouble());
                totalPoints.push_back(v.toObject().value("total").toDouble());
                playerNames.push_back(v.toObject().value("player_name").toString());
       }

       sortWidget = new SortWidget(weeklyPoints,totalPoints,playerNames);
//printing the data in console
     QTextStream out(stdout);

     for (auto i: playerNames)
          out<<i<<Qt::endl;

     for(auto i:weeklyPoints)
          out<<i<<Qt::endl;

     for(auto i:totalPoints)
          out<<i<<Qt::endl;

}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_sortPushButton_clicked()
{
    sortWidget->show();
}

void MainWidget::on_treePushButton_clicked()
{
    treeWidget = new TreeWidget(this);
    treeWidget->show();
}
