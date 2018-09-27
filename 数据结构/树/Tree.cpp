#include <iostream>
#include "Tree.h"
using namespace std;

Tree::Tree()
{
    m_pRoot = new Node();   //第一个节点
}

Tree::~Tree()
{
    DeleteNode(0, NULL);
}

Node *Tree::SearchNode(int nodeIndex)
{
    return m_pRoot->SearchNode(nodeIndex);
}

bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
    Node *temp = SearchNode(nodeIndex);
    if (temp == NULL)
    {
        return false;
    }

    Node *node = new Node();
    if (node == NULL)
    {
        return false;
    }
    //要把pNode值保存下来
    node->index = pNode->index;
    node->data = pNode->data;
    node->pParent = temp;   //注意，要在添加时把父节点登记上
    
    //0挂左，1挂右
    if (direction == 0)
    {
        temp->pLChild = node;
    }
    if (direction == 1)
    {
        temp->pRChild = node;
    }

    return true;
}

bool Tree::DeleteNode(int nodeIndex, Node *pNode)
{
    Node *temp = SearchNode(nodeIndex);
    if (temp == NULL)
    {
        return false;
    }
    if (pNode != NULL)
    {
        pNode->data = temp->data;
    }
    //把树中删除节点的操作下移到node中来
    temp->DeleteNode();

    return true;
}

void Tree::PreorderTraversal()
{
    m_pRoot->PreorderTraversal();
}

void Tree::InorderTraversal()
{
    m_pRoot->InorderTraversal();
}

void Tree::PostorderTraversal()
{
    m_pRoot->PostorderTraversal();
}