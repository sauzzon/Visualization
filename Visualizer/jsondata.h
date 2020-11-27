#ifndef JSONDATA_H
#define JSONDATA_H

#include<vector>
#include<iostream>
#include<QWidget>

#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QByteArray>
#include<QFile>

class JSONData
{
public:
    JSONData();
    void readJSON();
    std::vector<double> getWeekPoints();
    std::vector<double> getTotalPoints();
    std::vector<QString> getPlayerNames();

private:
    std::vector<double> weekPoints;
    std::vector<double> totalPoints;
    std::vector<QString> playerNames;
};

#endif // JSONDATA_H
