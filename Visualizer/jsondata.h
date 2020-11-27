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
    std::vector<double> getFantasyPoints();
    std::vector<QString> getPlayerNames();

private:
    std::vector<double> fantasyPoints;
    std::vector<QString> playerNames;
};

#endif // JSONDATA_H
