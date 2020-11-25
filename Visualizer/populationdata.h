#ifndef POPULATIONDATA_H
#define POPULATIONDATA_H

#include<vector>
#include<iostream>
#include<QWidget>

#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QByteArray>
#include<QFile>

class PopulationData
{
public:
    PopulationData();
    void readJSON();
    std::vector<double> getCountryPopulation();
    std::vector<QString> getCountryNames();

private:
    std::vector<double> countryPopulation;
    std::vector<QString> countryName;
};

#endif // POPULATIONDATA_H
