#ifndef NODE_H
#define NODE_H
#include "Person.h"

class Node
{
public:
    Person data;           //数据域
    Node *next;         //指针域，指向下一个节点
    void printNode();   //节点的打印函数
};

#endif // !NODE_H