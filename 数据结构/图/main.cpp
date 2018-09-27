#include <iostream>
#include "CMap.h"

using namespace std;

int main()
{
    CMap *pMap = new CMap(6);

    Node *pNodeA = new Node('A');
    Node *pNodeB = new Node('B');
    Node *pNodeC = new Node('C');
    Node *pNodeD = new Node('D');
    Node *pNodeE = new Node('E');
    Node *pNodeF = new Node('F');

    pMap->addNode(pNodeA);
    pMap->addNode(pNodeB);
    pMap->addNode(pNodeC);
    pMap->addNode(pNodeD);
    pMap->addNode(pNodeE);
    pMap->addNode(pNodeF);

    //无向图对称位置也会有值，相当于双向链接
    pMap->serValueToMatrixForUndirectedGraph(0, 1, 6);
    pMap->serValueToMatrixForUndirectedGraph(0, 4, 5);
    pMap->serValueToMatrixForUndirectedGraph(0, 5, 1);
    pMap->serValueToMatrixForUndirectedGraph(1, 2, 3);
    pMap->serValueToMatrixForUndirectedGraph(1, 5, 2);
    pMap->serValueToMatrixForUndirectedGraph(2, 5, 8);
    pMap->serValueToMatrixForUndirectedGraph(2, 3, 7);
    pMap->serValueToMatrixForUndirectedGraph(3, 5, 4);
    pMap->serValueToMatrixForUndirectedGraph(3, 4, 2);
    pMap->serValueToMatrixForUndirectedGraph(4, 5, 9);

    pMap->primTree(0);

    return 0;
}