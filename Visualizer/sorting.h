#ifndef SORTING_H
#define SORTING_H
#include<iostream>
#include<vector>
#include<QtWidgets>
#include<QWidget>

#include<jsondata.h>

class Sorting
{

public:
    Sorting();
    void initialize(double,double,QGraphicsScene*);
    void createRectangles();
    void createRectanglesFantasy(std::vector<double> &);
    void switchToFantasy();
    void selectionSort();
    void switchToQuickSort();
    void switchToMergeSort();
    void setRectangles(int);
    void resetRectangles();
    void resetRectanglesFantasy(int);
    void setDelay(int);
    void setStopButton();
    void setFantasySelected(bool);


private:
     QGraphicsScene* sortingScene;

     JSONData* fantasy;
     void getFantasyData();
     std::vector<double> fantasyPoints;
     std::vector<double> totalPoints;
     std::vector<QString> playerNames;
     std::vector<QString> players;//recreating playerNames so that original is not changed
         //not creating another vector for fantasyPoints because it's copied into rectHeight and is not changed


     std::vector<QGraphicsRectItem*> rectangles;
     std::vector<double> rectHeight;
     std::vector<double> rectPointHeight; //recreating backup as rectHeight is changed according to ratio
     double sceneHeight;
     double sceneWidth;
     double heightDiff;
     double rectWidth;
     bool isSortingCompleted = false;

     int delayTime;
     int noOfRectangles;
     bool isFantasySelected = false;
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
