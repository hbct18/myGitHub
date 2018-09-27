#include <iostream>
#include "Node.h"

Node::Node()
{
    index = 0;
    data = 0;
    pLChild = NULL;
    pRChild = NULL;
    pParent = NULL;
}

Node *Node::SearchNode(int nodeIndex)
{
    //看看是不是自己
    if (this->index == nodeIndex)
    {
        return this;
    }
    //左右节点是不是
    Node *temp = NULL;
    if (this->pLChild != NULL)
    {
        if (this->pLChild->index == nodeIndex)
        {
            return this->pLChild;
        }
        //没找到的情况继续往下找
        else
        {
            temp = this->pLChild->SearchNode(nodeIndex);
            if (temp != NULL)
            {
                return temp;
            }
        }
    }
    if (this->pRChild != NULL)
    {
        if (this->pRChild->index == nodeIndex)
        {
            return this->pRChild;
        }
        else
        {
            temp = this->pRChild->SearchNode(nodeIndex);
            if (temp != NULL)
            {
                return temp;
            }
        }
    }
    return NULL;
}

void Node::DeleteNode()
{
    if (this->pLChild != NULL)
    {
        this->pLChild->DeleteNode();
    }
    if (this->pRChild != NULL)
    {
        this->pRChild->DeleteNode();
    }
    if (this->pParent != NULL)
    {
        //判断自己是父节点的左节点还是右节点
        if (this->pParent->pLChild == this)
        {
            this->pParent->pLChild = NULL;
        }
        if (this->pParent->pRChild == this)
        {
            this->pParent->pRChild = NULL;
        }
    }
    delete this;
}

//先自己，然后左边，然后右边
void Node::PreorderTraversal()
{
    std::cout << this->index << " " << this->data << std::endl;
    if (this->pLChild != NULL)
    {
        this->pLChild->PreorderTraversal();
    }
    if (this->pRChild != NULL)
    {
        this->pRChild->PreorderTraversal();
    }
}

void Node::InorderTraversal()
{
    if (this->pLChild != NULL)
    {
        this->pLChild->InorderTraversal();
    }
    std::cout << this->index << " " << this->data << std::endl;
    if (this->pRChild != NULL)
    {
        this->pRChild->InorderTraversal();
    }
}

void Node::PostorderTraversal()
{
    if (this->pLChild != NULL)
    {
        this->pLChild->PostorderTraversal();
    }
    if (this->pRChild != NULL)
    {
        this->pRChild->PostorderTraversal();
    }
    std::cout << this->index << " " << this->data << std::endl;
}