#include "binaryTree.h"

BSTNode::BSTNode()
{
    Key=0;
    Left=Right=Parent=nullptr;
}


 BST::BST()
{
    root=nullptr;
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
     else
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
 }

 void BST::initializer(QGraphicsScene* mainScene,double height,double width)
 {
    treeScene=mainScene;
    treeSceneHeight=height;
    treeSceneWidth=width;
 }

 void BST::draw(int key)
 {
     this->Insert(key);
//     if(this->root!=nullptr)
//     {
//         treeScene->addEllipse(QRectF(QPointF(treeSceneWidth/2,50),QPointF(treeSceneWidth/2+50,50+50)),QPen(QColor(0,0,0)),QBrush(QColor(255,255,255)));
//         QGraphicsTextItem* text;
//         text=treeScene->addText(QString::number(key),QFont("Times"));
//         text->setPos(QPointF(treeSceneWidth/2+10,50+10));

//     }
     double rectX1=treeSceneWidth/2;
     double rectX2=treeSceneWidth/2+50;
     double rectY1=50;
     double rectY2=100;
    recursiveDraw(this->root,key,rectX1,rectY1,rectX2,rectY2);
 }

 void BST::recursiveDraw(BSTNode* node,int key,double x1,double y1,double x2,double y2)
 {
     if(node!=nullptr)
     {
//         treeScene->addEllipse(QRectF(QPointF(x1,y1),QPointF(x2,y2)),QPen(QColor(0,0,0)),QBrush(QColor(255,255,255)));
//         treeScene->addRect(QRectF(QPointF(x1,y1),QPointF(x2,y2)),QPen(QColor(0,0,0)),QBrush(QColor(255,255,255)));
         QGraphicsTextItem* text;
         text=treeScene->addText(QString::number(node->Key),QFont("Times"));
         text->setPos(QPointF(x1+10,y1+10));

     if(node->Key>key)
     {
         recursiveDraw(node->Left,key,x1-100,y2+50,x1-120,y2+80);
     }
     else if(node->Key<key)
     {
         recursiveDraw(node->Right,key,x2+100,y2+50,x2+120,y2+80);
     }
     }


 }
