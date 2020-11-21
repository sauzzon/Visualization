#include "binaryTree.h"
#include<math.h>

#define SKYBLUE QColor(135,235,231)
#define RED QColor(255,0,0)
#define GREEN QColor(0,255,0)
#define BLACK QColor(0,0,0)

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
         draw(node->Key,true);
         processEvents();

         node->Right = Insert(node->Right, key);
         node->Right->Parent = node;
     }
     // If the given key is smaller than
     // node's key then go to left subtree
     else if(node->Key > key)
     {
         draw(node->Key,true);
         processEvents();

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
     draw(key,false);
 }


 void BST::Search(int key)
 {
     Search(root,key);
 }


 void BST::Search(BSTNode* node,int key)
 {
     if(node==nullptr)
     {
         return;
     }

     else
     {
         draw(node->Key,true);
         processEvents();

         if(node->Key>key)
         {
             Search(node->Left,key);

         }
         else if(node->Key<key)
         {
             Search(node->Right,key);

         }
         else if(node->Key==key)
         {
             isNodeFound = true;
             draw(node->Key,true);
         }
     }
 }


 void BST::initializer(QGraphicsScene* mainScene,double width,double height)
 {
    treeScene=mainScene;
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
             nodeColor = SKYBLUE;
             isNodeFound = false;
         }
         else {
             nodeColor = RED;
             isNodeToBeColored = false;
         }
     }
     else if(!isNodeToBeColored and keyToBeColored ==node->Key){
         nodeColor = SKYBLUE;
     }
     else nodeColor = GREEN;

     treeScene->addRect(textRect,QPen(QColor(nodeColor)),QBrush(QColor(nodeColor)));
     QGraphicsTextItem* textNumber;
     textNumber=treeScene->addText(QString::number(node->Key),QFont("Times"));
     textNumber->setPos(QPointF(x,y));


     if(node->Left!=nullptr)
      {
      QColor edgeColor;

      if(isNodeToBeColored and keyToBeColored == node->Left->Key) edgeColor=RED;
      else edgeColor=BLACK;
       treeScene->addLine(textRect.bottomLeft().x(),textRect.bottomLeft().y(),x-widthDiff+textRect.width(),y+heightDiff,QPen(edgeColor));
      }

      if(node->Right!=nullptr)
      {
          QColor edgeColor;

      if(isNodeToBeColored and keyToBeColored == node->Right->Key) edgeColor =RED;
      else edgeColor = BLACK;
       treeScene->addLine(textRect.bottomRight().x(),textRect.bottomRight().y(),x+widthDiff,y+heightDiff,QPen(edgeColor));

       }


     drawNode(node->Left,x-widthDiff,y+heightDiff,widthDiff/2,heightDiff,keyToBeColored,isNodeToBeColored);
     drawNode(node->Right,x+widthDiff,y+heightDiff,widthDiff/2,heightDiff,keyToBeColored,isNodeToBeColored);
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
