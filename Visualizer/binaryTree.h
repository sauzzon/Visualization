#ifndef BINARYTREE_H
#define BINARYTREE_H


#include<QWidget>
#include<QtWidgets>


class BSTNode
{
    friend class BST;
public:
    BSTNode();

private:
    int Key;
    BSTNode* Left;
    BSTNode* Right;
    BSTNode* Parent;

};




class BST
{
public:
     BST();
    ~BST();
    void initializer(QGraphicsScene*,double,double);
    void draw();
    void drawNode(BSTNode* ,double,double,double,double);
    void Insert(int key);
    int treeHeight(BSTNode*);
    double findWidthDiff(double);

private:
    BSTNode* root;
    QGraphicsScene* treeScene;
    BSTNode* Insert(BSTNode* node, int key);
    double treeSceneHeight;
    double treeSceneWidth;

};

#endif // BINARYTREE_H



