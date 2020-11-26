#include "jsondata.h"

JSONData::JSONData()
{
    readJSON();
}

void JSONData::readJSON(){

// opening json file
    QString fileName = ":/resource/Resources/data.json";
    QFile myFile(fileName);

    if(myFile.exists()){
        if(myFile.open(QIODevice::ReadOnly | QIODevice::Text)){

//reading from file
            QByteArray jsonData = myFile.readAll();
            myFile.close();

//creating JSON object and initializing to json array
            QJsonDocument myDoc=QJsonDocument::fromJson(jsonData);
            QJsonObject myObj=myDoc.object();
            QJsonValue standingsValue = myObj.value("standings");
            QJsonObject standings =standingsValue.toObject();
            QJsonValue resultValue = standings.value("results");
            QJsonArray array = resultValue.toArray();

// iterating through json array and putting the name of country and its population in vector
              foreach (const QJsonValue & v, array){
                       fantasyPoints.push_back(v.toObject().value("event_total").toDouble());
                       playerNames.push_back(v.toObject().value("player_name").toString());
            }
        }
    }
}

std::vector<double> JSONData::getFantasyPoints(){
    return fantasyPoints;
}

std::vector<QString> JSONData::getPlayerNames(){
    return playerNames;
}
