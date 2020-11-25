#include "sorting.h"
#include <QTextStream>


#define SKYBLUE QColor(135,235,231)
#define GREY QColor(220,220,220)
#define BLACK QColor(0,0,0)
#define RED QColor(255,0,0)
#define GREEN QColor(0,255,0)


Sorting::Sorting()
{
   getPopulationData();
}

void Sorting::getPopulationData(){
    popu = new PopulationData;
    countryPopulation = popu->getCountryPopulation();
    countryNames = popu->getCountryNames();

//printing the data in console
    QTextStream out(stdout);

    for (auto i: countryNames)
        out<<i<<Qt::endl;

    for(auto i:countryPopulation)
        out<<i<<Qt::endl;
}

void Sorting::initialize(double height,double width,QGraphicsScene* visualizingScene){
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

// The sorted rectHeight is mixed

//This is a random number engine class that generates pseudo-random numbers. (Found From StackOverflow)
    auto rng = std::default_random_engine {};
    std::shuffle(rectHeight.begin(), rectHeight.end(), rng);
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

        updateDisplay(i,i,minIndex,true);
        processEvents();

    }
}


void Sorting::switchToQuickSort(){
    quickSort(rectHeight,0,rectHeight.size()-1);
}


void Sorting::switchToMergeSort(){
     mergeSort(rectHeight,0,rectHeight.size()-1);
}


void Sorting::setRectangles(int value){
    noOfRectangles = value;
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

        updateDisplay(low,i,high,true);
        processEvents();
        if(vec[i]<pivot)
        {
            std::swap(vec[i],vec[pIndex]);
            updateDisplay(low,i,high,true);
            processEvents();
            pIndex+=1;
        }
    }
    std::swap(vec[pIndex],vec[high]);
    updateDisplay(low,low,high,true);
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

    }
    else
    {
        while(i<=midIdx)
        {
            temp.push_back(rectangleHeight[i]);
            i+=1;
            index+=1;
        }
    }

    int k=0;
    for(k=0;k<index;k++)
    {
        rectangleHeight[startIdx]=temp[k];
        startIdx++;
    }

    mergeSortDisplay(endIdx);
    processEvents();

}


//updateDisplay for mergeSort test purpose
void Sorting::mergeSortDisplay(int sorted)
{
    sortingScene->clear();

    //displaying the rectangles in scene
        auto j = 0;
        auto k = 0.0;

    for(auto &p:rectangles)
    {
        p=new QGraphicsRectItem;
        p->setRect(k, (sceneHeight - rectHeight[j]), rectWidth , rectHeight[j]);
        if(j<=sorted)
        {
        p->setBrush(QBrush(GREEN));
        }
        else
        {
        p->setBrush(QBrush(SKYBLUE));
        }
        p->setPen(QPen(BLACK));

        sortingScene->addItem(p);
        j++;
        k += rectWidth;

    }
}


void Sorting::updateDisplay(int sortedIntegers,int comp1,int comp2,bool toColor)
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

            if((j ==comp1 or j == comp2) and toColor == true)
                p->setBrush(QBrush(RED));
            if(j<sortedIntegers and toColor ==true)
                 p->setBrush(QBrush(GREEN));


            p->setPen(QPen(BLACK));

            sortingScene->addItem(p);
            j++;
            k += rectWidth;

        }

}


void Sorting::processEvents()
{
    QApplication::processEvents();
    QThread::msleep(delayTime);
}
