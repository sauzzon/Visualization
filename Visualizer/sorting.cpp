#include "sorting.h"
#include <QTextStream>


#define SKYBLUE QColor(135,235,231)
#define GREY QColor(220,220,220)
#define BLACK QColor(0,0,0)
#define RED QColor(255,0,0)
#define GREEN QColor(0,255,0)
#define BLUE QColor(0,0,255)

Sorting::Sorting()
{
}

void Sorting::initialize(double height,double width,QGraphicsScene* visualizingScene,std::vector<double> gwPoints,std::vector<double>totPoints,std::vector<QString>names){

    fantasyPoints = gwPoints;
    totalPoints = totPoints;
    playerNames = names;

    sortingScene = visualizingScene;
    //height and width of main scene
        sceneHeight = height-20;
        sceneWidth = width-50;

    //creating columns for sorting
        noOfRectangles = 125;
        createRectangles();

    //default value for delayTime
        delayTime = 10;
}

void Sorting::createRectangles(){
    rectWidth = sceneWidth / noOfRectangles;

//resize sets the std::vector size
    rectangles.resize(noOfRectangles);

//heightDiff is the difference in height between two consecutive sorted rectangles
    heightDiff = sceneHeight / noOfRectangles;

//putting height of rectangles in vector called rectHeight
//push_back is a method in std::vector to insert elements from back

        double height = heightDiff;
    for(int i=0;i<noOfRectangles;i++){
        rectHeight.push_back(height);
        height += heightDiff;
    }

 //The sorted rectHeight is mixed

//This is a random number engine class that generates pseudo-random numbers. (Found From StackOverflow)
    auto rng = std::default_random_engine {};
    std::shuffle(rectHeight.begin(), rectHeight.end(), rng);
    updateDisplay(0,0,0,false);
}

void Sorting::createRectanglesFantasy(std::vector<double>&points)
{
    players = playerNames;
    rectPointHeight =points;

    rectWidth = sceneWidth / points.size();

//resize sets the std::vector size
    rectangles.resize(points.size());

//creating rectangles of height of screen for highest point and
//  25% of screen for lowest point and interpolating intermediate values

    double maxPoint = *std::max_element(points.begin(),points.end());
    double minPoint = *std::min_element(points.begin(),points.end());
    double maxHeight = sceneHeight;
    double minHeight = 0.25*sceneHeight;

//case when gameweek is just started and everbody has same points

    if(maxPoint == minPoint){
        for(size_t i=0;i<points.size();i++){
            rectHeight.push_back(0.5*sceneHeight);
        }
    }
    else{

        for(size_t i=0;i<points.size();i++){
            double pointHeight =minHeight+((points.at(i)-minPoint)/(maxPoint-minPoint))*(maxHeight-minHeight);
            rectHeight.push_back(pointHeight);
        }
    }


 //arranging data alphabetically
    for (size_t i= 0; i <players.size();i++)
           {
               for (size_t j = i+1; j < players.size(); j++)
               {
                   if (QString::compare(players[i], players[j]) > 0)
                   {
                       std::swap(players[i],players[j]);
                       std::swap(rectHeight[i],rectHeight[j]);
                       std::swap(rectPointHeight[i],rectPointHeight[j]);
                   }
               }
           }
    updateDisplay(0,0,0,false);
}


void Sorting::selectionSort()
{
    for(size_t i=0;i<rectHeight.size();i++)
    {

        if(isStopButtonPressed){
            break;
        }

        size_t minIndex = findMinimum(i);

        updateDisplay(i,i,minIndex,true);
        //Processes all pending events for the calling thread  until there are no more events to process.
        processEvents();

        std::swap(rectHeight[i],rectHeight[minIndex]);
        if(isFantasySelected){
            std::swap(players[i],players[minIndex]);
            std::swap(rectPointHeight[i],rectPointHeight[minIndex]);
        }

        updateDisplay(i,i,minIndex,true);
        processEvents();

    }
    if(!isStopButtonPressed){
        isSortingCompleted = true;
        updateDisplay(0,0,0,false);
        isSortingCompleted = false;
    }
}


void Sorting::switchToQuickSort(){
    quickSort(rectHeight,0,rectHeight.size()-1);
    if(!isStopButtonPressed){
        isSortingCompleted = true;
        updateDisplay(0,0,0,false);
        isSortingCompleted = false;
    }
}


void Sorting::switchToMergeSort(){
     mergeSort(rectHeight,0,rectHeight.size()-1);
     if(!isStopButtonPressed){
         isSortingCompleted = true;
         updateDisplay(0,0,0,false);
         isSortingCompleted = false;
     }
}

void Sorting::switchToFantasy()
{
    //default when switching to fantasy is weekly points so, pass 0
    resetRectanglesFantasy(0);
}


void Sorting::setRectangles(int value){
    noOfRectangles = value;
}

void Sorting::resetRectanglesFantasy(int index)
{
    rectHeight.clear();
    rectPointHeight.clear();

    if(index==0)
        createRectanglesFantasy(totalPoints);
    else if(index==1)
        createRectanglesFantasy(fantasyPoints);

    isStopButtonPressed = false;
}

void Sorting::resetRectangles(){
    rectHeight.clear();
    createRectangles();
    isStopButtonPressed = false;
}

void Sorting::setDelay(int value){
    delayTime=value;
}

void Sorting::setStopButton(){
    isStopButtonPressed = true;
}

size_t Sorting::findMinimum(size_t startingIndex)
{
    int min=rectHeight.at(startingIndex);
    size_t minIndex =startingIndex;
    for(size_t i=startingIndex;i<rectHeight.size();i++)
    {
        if(isStopButtonPressed){
            break;
        }
        if(rectHeight.at(i)<min)
        {
            minIndex=i;
            min=rectHeight.at(i);

        }
        updateDisplay(startingIndex,i,minIndex,true);
        processEvents();
    }
    return minIndex;
}


void Sorting::quickSort(std::vector<double>&vec,int low,int high)
{

    if(isStopButtonPressed)
    {
        return;
    }

    if(low<high)
    {
        int pIndex = partition(vec,low,high);
        quickSort(vec,low,pIndex-1);
        quickSort(vec,pIndex+1,high);
    }

}


int Sorting::partition(std::vector<double>&vec,int low,int high)
{
    int pivot = vec[high];
    int pIndex=low;
    for(int i=low;i<high+1;i++)
    {
        if(isStopButtonPressed){
            return 5;
        }

        updateDisplay(low,i,pIndex,true,high);
        processEvents();
        if(vec[i]<pivot)
        {
            std::swap(vec[i],vec[pIndex]);         
            updateDisplay(low,i,pIndex,true,high);
            processEvents();
            pIndex+=1;
        }
    }
    std::swap(vec[pIndex],vec[high]);
    updateDisplay(low,pIndex,high,true,high);
    processEvents();

    return pIndex;

}



//Mergesort main function
void Sorting::mergeSort(std::vector<double> &rectangleHeight,int startIdx,int endIdx)
{
    if(isStopButtonPressed){
        return;
    }

    if(startIdx<endIdx)
    {
        int midIdx=(startIdx+endIdx)/2;
        mergeSort(rectangleHeight,startIdx,midIdx);
        mergeSort(rectangleHeight,midIdx+1,endIdx);
        mergeSortCombiner(rectangleHeight,startIdx,midIdx,endIdx);

    }
}


//Mergesort helper function
void Sorting::mergeSortCombiner(std::vector<double> &rectangleHeight,int startIdx,int midIdx,int endIdx)
{
    if(isStopButtonPressed){
        return;
    }

    int i=startIdx;
    int j=midIdx+1;
    int index=0;
    std::vector<double> temp;
    while(i<=midIdx && j<=endIdx)
    {
        if(rectangleHeight[i]<rectangleHeight[j])
        {
            temp.push_back(rectangleHeight[i]);
            i+=1;

        }
        else
        {
            temp.push_back(rectangleHeight[j]);
            j+=1;
        }
        updateDisplay(startIdx,i,j,true);
        processEvents();
        index=index+1;
    }

    if(i>midIdx)
    {
        while(j<=endIdx)
        {
            temp.push_back(rectangleHeight[j]);
            j+=1;
            index+=1;
        }
        updateDisplay(startIdx,i,j,true);
        processEvents();

    }
    else
    {
        while(i<=midIdx)
        {
            temp.push_back(rectangleHeight[i]);
            i+=1;
            index+=1;
        }
        updateDisplay(startIdx,i,j,true);
        processEvents();
    }

    int k=0;
    for(k=0;k<index;k++)
    {
        rectangleHeight[startIdx]=temp[k];
        updateDisplay(startIdx,0,0,true);
        processEvents();
        startIdx++;
    }

}

void Sorting::updateDisplay(int sortedIntegers,int comp1,int comp2,bool toColor,int qSortPivot)
{
    sortingScene->clear();
    //displaying the rectangles in scene
        auto j = 0;
        auto k = 0.0;

    //easiest way of iterating in std::vector
        for(auto &p :rectangles)
        {
            p = new QGraphicsRectItem;
            p->setRect(k, (sceneHeight - rectHeight[j]), rectWidth , rectHeight[j]);
            p->setBrush(QBrush(SKYBLUE));
            if(qSortPivot<noOfRectangles)
                rectangles.at(qSortPivot)->setBrush(QBrush(BLUE));

            if((j ==comp1 or j == comp2) and toColor == true)
                p->setBrush(QBrush(RED));
            if(j<sortedIntegers and toColor ==true)
                 p->setBrush(QBrush(GREEN));

            if(isSortingCompleted){
                p->setBrush(QBrush(GREEN));
            }

            p->setPen(QPen(BLACK));

            sortingScene->addItem(p);
            if(isFantasySelected)
            {
                QGraphicsTextItem *text = sortingScene->addText(players[j]+"\n\nPoints: "+QString::number(rectPointHeight[j]));
                text->setTextWidth(rectWidth);
                text->setPos(k,(sceneHeight-rectHeight[j]));
            }
            j++;
            k += rectWidth;

        }

}

void Sorting::setFantasySelected(bool value)
{
    isFantasySelected = value;
}


void Sorting::processEvents()
{
    QApplication::processEvents();
    QThread::msleep(delayTime);
}
