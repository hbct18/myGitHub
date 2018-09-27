#include <vector>
#include "Node.h"
#include "Edge.h"

class CMap
{
public:
    CMap(int capacity);
    ~CMap();
    bool addNode(Node *pNode);      //向图中加入顶点
    void resetNode();               //重置顶点都没访问过
    bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);
    bool serValueToMatrixForUndirectedGraph(int row, int col, int val = 1);

    void printMatrix();             //打印邻接矩阵

    void depthFirstTraverse(int nodeIndex); //深度优先遍历
    void breadthFirstTraverse(int nodeIndex);//广度优先遍历
    void primTree(int nodeIndex);//普里姆生成树指定的第一个点，找出与它相连的最小边

private:
    bool getValueFromMatrix(int row, int col, int &val);    //从矩阵中获取权值
    void breadthFirstTraverseImpl(std::vector<int> preVec); //广度优先遍历实现函数

    int getMinEdge(std::vector<Edge> edgeVec);

private:
    int m_iCapacity;        //图中最多可以容纳的顶点数
    int m_iNodeCount;       //已经添加的顶点数
    Node *m_pNodeArray;     //用来存放顶点数组
    int *m_pMatrix;         //用来存放邻接矩阵

    Edge *m_pEdge;//边，map.cpp中分配内存
};