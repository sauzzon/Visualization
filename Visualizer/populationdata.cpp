#include "populationdata.h"

PopulationData::PopulationData()
{
    readJSON();
}

void PopulationData::readJSON(){

// opening json file
    QString fileName = ":/resources/Resources/data.json";
    QFile myFile(fileName);

    if(myFile.exists()){
        if(myFile.open(QIODevice::ReadOnly | QIODevice::Text)){

//reading from file
            QByteArray jsonData = myFile.readAll();
            myFile.close();

//creating JSON object and initializing to json array
            QJsonDocument myDoc=QJsonDocument::fromJson(jsonData);
            QJsonObject myObj=myDoc.object();
            QJsonValue value = myObj.value("populationData");
            QJsonArray array = value.toArray();

// iterating through json array and putting the name of country and its population in vector
              foreach (const QJsonValue & v, array){
                       countryPopulation.push_back(v.toObject().value("population").toDouble());
                       countryName.push_back(v.toObject().value("country").toString());
            }
        }
    }
}

std::vector<double> PopulationData::getCountryPopulation(){
    return countryPopulation;
}

std::vector<QString> PopulationData::getCountryNames(){
    return countryName;
}
