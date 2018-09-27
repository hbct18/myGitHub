#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    Node *node1 = new Node();
    node1->index = 1;
    node1->data = 5;

    Node *node2 = new Node();
    node2->index = 2;
    node2->data = 8;

    Node *node3 = new Node();
    node3->index = 3;
    node3->data = 2;

    Node *node4 = new Node();
    node4->index = 4;
    node4->data = 6;

    Node *node5 = new Node();
    node5->index = 5;
    node5->data = 9;

    Node *node6 = new Node();
    node6->index = 6;
    node6->data = 7;

    Tree *pTree = new Tree();
    pTree->AddNode(0, 0, node1);
    pTree->AddNode(0, 1, node2);
    pTree->AddNode(1, 0, node3);
    pTree->AddNode(1, 1, node4);
    pTree->AddNode(2, 0, node5);
    pTree->AddNode(2, 1, node6);

    cout << "前序遍历" << endl;
    pTree->PreorderTraversal();
    cout << "中序遍历" << endl;
    pTree->InorderTraversal();
    cout << "后序遍历" << endl;
    pTree->PostorderTraversal();
    
    delete pTree;
    pTree = NULL;
    return 0;
}