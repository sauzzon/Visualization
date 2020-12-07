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
    void initializer(QGraphicsScene*,double,double,QLabel*);
    void draw(int,bool);
    void drawNode(BSTNode* ,double,double,double,double,int,bool);
    void Insert(int key);
    void Search(int key);
    void Delete(int key);
    int treeHeight(BSTNode*);
    double findWidthDiff(double);
    void setDelay(int);
    void processEvents();
    void preorderTraversal();
    void postorderTraversal();
    void inorderTraversal();

private:
    BSTNode* root;
    QGraphicsScene* treeScene;
    BSTNode* Insert(BSTNode* node, int key);
    void Search(BSTNode* node,int key);
    BSTNode* Delete(BSTNode* node,int key);
    int findMin(BSTNode* node);
    double treeSceneHeight;
    double treeSceneWidth;
    int delayTime;
    bool isNodeFound = false;
    bool isDeleteNodeFound = false;
    QLabel* treeStatus;
    void setTreeStatus(QString);
    void preorderTraversalHelper(BSTNode*);
    void postorderTraversalHelper(BSTNode*);
    void inorderTraversalHelper(BSTNode*);

};

#endif // BINARYTREE_H



