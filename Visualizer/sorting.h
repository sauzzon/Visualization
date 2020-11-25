#ifndef SORTING_H
#define SORTING_H
#include<iostream>
#include<vector>
#include<QtWidgets>
#include<QWidget>

#include<populationdata.h>

class Sorting
{

public:
    Sorting();
    void initialize(double,double,QGraphicsScene*);
    void createRectangles();
    void selectionSort();
    void switchToQuickSort();
    void switchToMergeSort();
    void setRectangles(int);
    void resetRectangles();
    void setDelay(int);
    void setStopButton();


private:
     QGraphicsScene* sortingScene;

     PopulationData* popu;
     void getPopulationData();
     std::vector<double> countryPopulation;
     std::vector<QString> countryNames;

     std::vector<QGraphicsRectItem*> rectangles;
     std::vector<double> rectHeight;
     double sceneHeight;
     double sceneWidth;
     double heightDiff;
     double rectWidth;

     int delayTime;
     int noOfRectangles;

     bool isStopButtonPressed = false;

     size_t findMinimum(size_t startingIndex);

     void quickSort(std::vector<double>& vec,int low,int high );
     int partition(std::vector<double>& vec,int low,int high);

     void mergeSort(std::vector<double> &rectHeight,int startIdx,int endIdx);
     void mergeSortCombiner(std::vector<double> &rectHeight,int startIdx,int midIdx,int endIdx);
     void mergeSortDisplay(int sorted);

     void updateDisplay(int,int,int,bool);
     void processEvents();

};

#endif // SORTING_H
