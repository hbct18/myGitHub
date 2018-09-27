#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node();
    Node *SearchNode(int nodeIndex);
    //杀完之后判断自己是左是右，然后自杀
    void DeleteNode();
    void PreorderTraversal();   //前序遍历
    void InorderTraversal();    //中序遍历
    void PostorderTraversal();  //后序遍历
    int index;
    int data;
    Node *pLChild;              //左子节点
    Node *pRChild;              //右子节点
    Node *pParent;              //父节点
};

#endif // !NODE_H