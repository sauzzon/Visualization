#include "binaryTree.h"
#include<math.h>

BSTNode::BSTNode()
{
    Key=0;
    Left=Right=Parent=nullptr;
}


 BST::BST()
{
    root=nullptr;
}

 int BST::treeHeight(BSTNode* root) {
     // Get the height of the tree
     if (root == nullptr)
         return 0;
     else {
         // Find the height of both subtrees
         // and use the larger one
         int leftHeight = treeHeight(root->Left);
         int rightHeight = treeHeight(root->Right);
         if (leftHeight >= rightHeight)
             return leftHeight + 1;
         else
             return rightHeight + 1;
     }
 }


//  treescene/2 = x + x/2 + x/4  + ...
 // treescene/2 = x/2^0  + x/2^1 + x/2^2  + ... x/2^(n-1)
 // solving for x which is the required value of widthDiff


 double BST::findWidthDiff(double initPos){
     double height = treeHeight(root);
     double sum=0;
     for(int i=0;i<=height-2;i++){
         sum+=(1/(pow(2,i)));
     }
     return (initPos/sum);
 }

 BSTNode* BST::Insert(BSTNode* node, int key)
 {
     // If BST doesn't exist
     // create a new node as root
     // or it's reached when
     // there's no any child node
     // so we can insert a new node here
     if(node == NULL)
     {
         node = new BSTNode;
         node->Key = key;
         node->Left = NULL;
         node->Right = NULL;
         node->Parent = NULL;
     }
     // If the given key is greater than
     // node's key then go to right subtree
     else if(node->Key < key)
     {
         node->Right = Insert(node->Right, key);
         node->Right->Parent = node;
     }
     // If the given key is smaller than
     // node's key then go to left subtree
     else if(node->Key > key)
     {
         node->Left = Insert(node->Left, key);
         node->Left->Parent = node;
     }

     return node;
 }

 void BST::Insert(int key)
 {
     // Invoking Insert() function
     // and passing root node and given key
     root = Insert(root, key);
     draw(0,false);
 }

 void BST::Search(int key)
 {
     setStatus("Searching for "+QString::number(key)+" in the tree");
     Search(root,key);


 }

 void BST::Search(BSTNode* node,int key)
 {
     if(node==nullptr)
     {
         setStatus("Node Not found");
         return;
     }
     else
     {
         draw(node->Key,true);
         setStatus("Comparing search key "+QString::number(key)+" with root node "+QString::number(node->Key));
         if(node->Key>key)
         {
             setStatus("Search Key"+QString::number(key)+"  <  "+QString::number(node->Key));
             if(node->Left!=nullptr)
             {
             setStatus("Moving to left Branch of node "+QString::number(node->Key));
             }
             Search(node->Left,key);


         }
         else if(node->Key<key)
         {
             setStatus("Search Key"+QString::number(key)+"  >  "+QString::number(node->Key));
             if(node->Right!=nullptr)
             {
              setStatus("Moving to Right Branch of node "+QString::number(node->Key));
             }
             Search(node->Right,key);


         }
         else if(node->Key==key)
         {
             setStatus("Node found");
             isNodeFound = true;
             draw(node->Key,true);
         }
     }

 }

 void BST::initializer(QGraphicsScene* mainScene,double width,double height,QLabel* treeStatus)
 {
    treeScene=mainScene;
    treeStats=treeStatus;
    treeSceneHeight=height;
    treeSceneWidth=width-50;
    setDelay(1000);
 }

 void BST::draw(int coloringKey,bool toColor)
 {
    if(!toColor) treeScene->clear();
    double xCo = treeSceneWidth/2;
    double yCo = 0;

    double heightDiff = treeSceneHeight/treeHeight(root);

    double widthDiff = findWidthDiff(xCo);
    drawNode(root,xCo,yCo,widthDiff,heightDiff,coloringKey,toColor);

 }

 void BST::drawNode(BSTNode *node, double x, double y,double widthDiff,double heightDiff,int keyToBeColored, bool isNodeToBeColored)
 {
     if(node == nullptr) return;

     QGraphicsTextItem text(QString::number(node->Key),nullptr);
     QRectF textRect;
     textRect=text.boundingRect();
     textRect.moveTo(QPointF(x,y));
     QColor nodeColor;

     if(isNodeToBeColored and keyToBeColored == node->Key){
         if(isNodeFound){
             nodeColor.setRgb(144,238,144);
             isNodeFound = false;
         }
         else {
             nodeColor.setRgb(255,0,0);
             isNodeToBeColored = false;
         }

     }
     else nodeColor.setRgb(135,206,235);

     treeScene->addRect(textRect,QPen(QColor(nodeColor)),QBrush(QColor(nodeColor)));
     QGraphicsTextItem* textNumber;
     textNumber=treeScene->addText(QString::number(node->Key),QFont("Times"));
     textNumber->setPos(QPointF(x,y));
     if(node->Left!=nullptr)
      {
      treeScene->addLine(textRect.bottomLeft().x(),textRect.bottomLeft().y(),x-widthDiff+textRect.width(),y+heightDiff,QPen(QColor(0,0,0)));
      if(isNodeToBeColored and keyToBeColored == node->Left->Key){

           treeScene->addLine(textRect.bottomLeft().x(),textRect.bottomLeft().y(),x-widthDiff+textRect.width(),y+heightDiff,QPen(QColor(255,0,0)));
           processEvents();
      }
      }
      if(node->Right!=nullptr)
      {
      treeScene->addLine(textRect.bottomRight().x(),textRect.bottomRight().y(),x+widthDiff,y+heightDiff,QPen(QColor(0,0,0)));
      if(isNodeToBeColored and keyToBeColored == node->Right->Key){

           treeScene->addLine(textRect.bottomRight().x(),textRect.bottomRight().y(),x+widthDiff,y+heightDiff,QPen(QColor(255,0,0)));
           processEvents();
        }
       }


     drawNode(node->Left,x-widthDiff,y+heightDiff,widthDiff/2,heightDiff,keyToBeColored,isNodeToBeColored);
     drawNode(node->Right,x+widthDiff,y+heightDiff,widthDiff/2,heightDiff,keyToBeColored,isNodeToBeColored);
 }


 void BST::setStatus(QString status)
 {
     treeStats->clear();
     treeStats->setText(status);
     processEvents();

 }

 void BST::setDelay(int value)
 {
     delayTime=value;
 }

 void BST::processEvents()
 {
     QApplication::processEvents();
     QThread::msleep(delayTime);
 }
