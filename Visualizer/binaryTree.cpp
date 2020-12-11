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
     setTreeStatus(QString::number(key)+" INSERTED");
     draw(key,false);
 }


 void BST::Search(int key)
 {
     Search(root,key);
     draw(key,false);
     processEvents();
 }


 void BST::Search(BSTNode* node,int key)
 {
     if(node==nullptr)
     {
         setTreeStatus(QString::number(key)+" NOT FOUND");
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
             isDeleteNodeFound = true;
             setTreeStatus(QString::number(key)+" FOUND");
             draw(node->Key,true);
         }
     }
 }

 void BST::Delete(int key)
 {
     isDeleteNodeFound = false;
     Search(key);
     if(isDeleteNodeFound){
     root=Delete(root,key);
     setTreeStatus(QString::number(key)+" DELETED");
     draw(0,false);
     }
 }

 BSTNode* BST::Delete(BSTNode* node,int key)
 {
     if(node==nullptr)return nullptr;

     else
     {
         if(node->Key==key)
         {

             if(node->Left==nullptr and node->Right==nullptr)
             {

                 node=nullptr;

             }

             else if(node->Left!=nullptr and node->Right==nullptr)
             {
                 node->Left->Parent=node->Parent;
                 node=node->Left;


             }

             else if(node->Left==nullptr and node->Right!=nullptr)
             {
                 node->Right->Parent=node->Parent;
                 node=node->Right;


             }
             else if(node->Left!=nullptr and node->Right!=nullptr)
             {
                 setTreeStatus("FINDING MINIMUM IN RIGHT SUBTREE");
                 int minimum = findMin(node->Right);
                 Search(node->Right,minimum);
                 node->Key =minimum;
                 //draw(0,false);
                 processEvents();
                 node->Right=Delete(node->Right,node->Key);


             }


         }
         else if(node->Key>key)
         {
             node->Left=Delete(node->Left,key);

         }
         else if(node->Key<key)
         {
             node->Right=Delete(node->Right,key);

         }
         return node;
     }


 }

 int BST::findMin(BSTNode* node)
 {
     if(node == NULL)
     {
            return -1;
     }
     else if(node->Left == NULL)
     {
           return node->Key;
     }
     else
     {
          return findMin(node->Left);
     }
 }

 void BST::preorderTraversalHelper(BSTNode* node)
 {
     if(node==nullptr)
         return;
     draw(node->Key,true,true);
     processEvents();
     preorderTraversalHelper(node->Left);
     preorderTraversalHelper(node->Right);
 }

 void BST::postorderTraversalHelper(BSTNode* node)
 {
     if(node==nullptr)
         return;
     postorderTraversalHelper(node->Left);
     postorderTraversalHelper(node->Right);
     draw(node->Key,true,true);
     processEvents();
 }
 void BST::inorderTraversalHelper(BSTNode* node)
 {
     if(node==nullptr)
         return;
     inorderTraversalHelper(node->Left);
     draw(node->Key,true,true);
     processEvents();
     inorderTraversalHelper(node->Right);
 }
 void BST::preorderTraversal()
 {
     setTreeStatus("PREORDER TRAVERSAL");
     preorderTraversalHelper(root);
     draw(0,false,true);
 }
 void BST::postorderTraversal()
 {
     setTreeStatus("POSTORDER TRAVERSAL");
     postorderTraversalHelper(root);
     draw(0,false,true);

 }
 void BST::inorderTraversal()
 {
     setTreeStatus("INORDER TRAVERSAL");
     inorderTraversalHelper(root);
     draw(0,false,true);
 }
 void BST::initializer(QGraphicsScene* mainScene,double width,double height,QLabel* status)
 {
    treeScene=mainScene;
    treeSceneHeight=height;
    treeSceneWidth=width-50;
    treeStatus = status;
//    setDelay(0);
//    Insert(10);
//    Insert(5);
//    Insert(20);
//    Insert(4);
//    Insert(6);
//    Insert(25);
//    Insert(17);
    setDelay(1000);
 }

 void BST::setTreeStatus(QString message){
     treeStatus->setText(message);
 }

 void BST::draw(int coloringKey,bool toColor,bool traversal)
 {
    if(!toColor) treeScene->clear();
    double xCo = treeSceneWidth/2;
    double yCo = 0;

    double heightDiff = treeSceneHeight/treeHeight(root);

    double widthDiff = findWidthDiff(xCo);
    drawNode(root,xCo,yCo,widthDiff,heightDiff,coloringKey,toColor,traversal);

 }


 void BST::drawNode(BSTNode *node, double x, double y,double widthDiff,double heightDiff,int keyToBeColored, bool isNodeToBeColored,bool isTraversalDone)
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

      if(isTraversalDone) edgeColor = BLACK;


       treeScene->addLine(textRect.bottomLeft().x(),textRect.bottomLeft().y(),x-widthDiff+textRect.width(),y+heightDiff,QPen(edgeColor));
      }

      if(node->Right!=nullptr)
      {
          QColor edgeColor;

      if(isNodeToBeColored and keyToBeColored == node->Right->Key) edgeColor =RED;
      else edgeColor = BLACK;

      if(isTraversalDone) edgeColor = BLACK;


       treeScene->addLine(textRect.bottomRight().x(),textRect.bottomRight().y(),x+widthDiff,y+heightDiff,QPen(edgeColor));

       }


     drawNode(node->Left,x-widthDiff,y+heightDiff,widthDiff/2,heightDiff,keyToBeColored,isNodeToBeColored,isTraversalDone);
     drawNode(node->Right,x+widthDiff,y+heightDiff,widthDiff/2,heightDiff,keyToBeColored,isNodeToBeColored,isTraversalDone);
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
