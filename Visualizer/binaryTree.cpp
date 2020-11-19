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
     draw();
 }

 void BST::initializer(QGraphicsScene* mainScene,double width,double height)
 {
    treeScene=mainScene;
    treeSceneHeight=height;
    treeSceneWidth=width;
 }

 void BST::draw()
 {
    treeScene->clear();
    double xCo = treeSceneWidth/2;
    double yCo = 50;

    double heightDiff = treeSceneHeight/treeHeight(root);
    drawNode(root,xCo,yCo,200,heightDiff);

 }

 void BST::drawNode(BSTNode *node, double x, double y,double widthDiff,double heightDiff)
 {
     if(node == nullptr) return;

     QGraphicsTextItem* text;
     text=treeScene->addText(QString::number(node->Key),QFont("Times"));
     text->setPos(QPointF(x,y));


     drawNode(node->Left,x-widthDiff,y+heightDiff,widthDiff/2,heightDiff);
     drawNode(node->Right,x+widthDiff,y+heightDiff,widthDiff/2,heightDiff);
 }

