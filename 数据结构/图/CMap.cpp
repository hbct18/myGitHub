#include <iostream>
#include <vector>
#include "CMap.h"

CMap::CMap(int capacity)
{
    m_iCapacity = capacity;
    m_iNodeCount = 0;
    m_pNodeArray = new Node[m_iCapacity];
    m_pMatrix = new int[m_iCapacity * m_iCapacity];

    for (int i = 0; i < m_iCapacity * m_iCapacity; ++i)
    {
        m_pMatrix[i] = 0;
    }

    m_pEdge = new Edge[m_iCapacity - 1];
}

CMap::~CMap()
{
    delete []m_pNodeArray;
    delete []m_pMatrix;
}

bool CMap::addNode(Node *pNode)
{
    if (pNode == NULL)
    {
        return false;
    }
    m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;
    m_iNodeCount++;
    return true;
}

void CMap::resetNode()
{
    for (int i = 0; i < m_iNodeCount; ++i)
    {
        m_pNodeArray[i].m_bIsVisited = false;
    }
}

bool CMap::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
    if (row < 0 || row >= m_iCapacity)
    {
        return false;
    }
    if (col < 0 || col >= m_iCapacity)
    {
        return false;
    }
    m_pMatrix[row * m_iCapacity + col] = val;//有向图设置对应坐标位置的值就行了
    return true;
}

bool CMap::serValueToMatrixForUndirectedGraph(int row, int col, int val)
{
    if (row < 0 || row >= m_iCapacity)
    {
        return false;
    }
    if (col < 0 || col >= m_iCapacity)
    {
        return false;
    }
    m_pMatrix[row * m_iCapacity + col] = val;//无向图得设置对称位置的值
    m_pMatrix[col * m_iCapacity + row] = val;
    return true;
}

bool CMap::getValueFromMatrix(int row, int col, int &val)
{
    if (row < 0 || row >= m_iCapacity)
    {
        return false;
    }
    if (col < 0 || col >= m_iCapacity)
    {
        return false;
    }
    val = m_pMatrix[row * m_iCapacity + col];
    return true;
}

void CMap::printMatrix()
{
    for (int i = 0; i < m_iCapacity; ++i)
    {
        for (int k = 0; k < m_iCapacity; ++k)
        {
            std::cout << m_pMatrix[i * m_iCapacity + k] << " ";
        }
        std::cout << std::endl;
    }
}

//深度优先
void CMap::depthFirstTraverse(int nodeIndex)
{
    //访问根左右，把子树延展的所有节点访问完才会回到根
    int value;
    std::cout << m_pNodeArray[nodeIndex].m_cData << " ";
    m_pNodeArray[nodeIndex].m_bIsVisited = true;

    //通过邻接矩阵判断是否与其他的顶点有连接
    for (int i = 0; i < m_iCapacity; ++i)
    {
        //取出相应的弧
        getValueFromMatrix(nodeIndex, i, value);
        if (value != 0)//判断有弧连接其他顶点
        {
            if (m_pNodeArray[i].m_bIsVisited)
            {
                continue;
            }
            else
            {
                //当前没有访问过，调用递归函数
                depthFirstTraverse(i);
            }
        }
        else
        {
            continue;
        }
    }
}

//每一层放在一个数组中
void CMap::breadthFirstTraverse(int nodeIndex)
{
    std::cout << m_pNodeArray[nodeIndex].m_cData << " ";
    m_pNodeArray[nodeIndex].m_bIsVisited = true;

    //将节点索引保存在数组中
    std::vector<int> curVec;
    curVec.push_back(nodeIndex);

    breadthFirstTraverseImpl(curVec);//真正实现广度优先的函数
}

void CMap::breadthFirstTraverseImpl(std::vector<int> preVec)
{
    int value = 0;
    std::vector<int> curVec;

    //preVec为上一层节点
    for (int j = 0; j < (int)preVec.size(); j++)
    {
        for (int i = 0; i < m_iCapacity; ++i)
        {
            //查询当前节点与其他节点的连接
            getValueFromMatrix(preVec[j], i, value);
            if (value != 0)
            {
                //连接相邻的点有没有被访问过
                if (m_pNodeArray[i].m_bIsVisited)
                {
                    continue;
                }
                else
                {
                    std::cout << m_pNodeArray[i].m_cData << " ";
                    m_pNodeArray[i].m_bIsVisited = true;
                    curVec.push_back(i);
                }
            }
        }
    }
    //本层不存在被访问的点
    if (curVec.size() == 0)
    {
        return;
    }
    else
    {
        breadthFirstTraverseImpl(curVec);
    }
}

//普里姆生成树
void CMap::primTree(int nodeIndex)
{
    int value = 0;
    int edgeCount = 0;
    
    std::vector<int> nodeVec;
    std::vector<Edge> edgeVec;

    std::cout << m_pNodeArray[nodeIndex].m_cData << std::endl;

    nodeVec.push_back(nodeIndex);
    m_pNodeArray[nodeIndex].m_bIsVisited = true;

    //什么时候停下来，边数等于点数-1时，edgeCount计数边
    while (edgeCount < m_iCapacity - 1)
    {
        int temp = nodeVec.back();//取出最尾部的元素
        //寻找与该节点连接的所有边
        for (int i = 0; i < m_iCapacity; ++i)
        {
            //取相应的边
            getValueFromMatrix(temp, i, value);
            if (value != 0)
            {
                if (m_pNodeArray[i].m_bIsVisited)
                {
                    continue;
                }
                else
                {
                    //没被访问过的放入备选边
                    Edge edge(temp, i, value);
                    edgeVec.push_back(edge);
                }
            }
        }

        //在可选边集合中找出最小的
        int edgeIndex = getMinEdge(edgeVec);
        edgeVec[edgeIndex].m_bSelected = true;

        std::cout << edgeVec[edgeIndex].m_iNodeIndexA << "-----" 
            << edgeVec[edgeIndex].m_iNodeIndexB << " ";
        std::cout << edgeVec[edgeIndex].m_iWeightValue << std::endl;

        //放入最小生成树边的集合
        m_pEdge[edgeCount] = edgeVec[edgeIndex];
        edgeCount++;

        //找到与当前边的连接点
        int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;

        //放入点集合
        nodeVec.push_back(nextNodeIndex);
        m_pNodeArray[nextNodeIndex].m_bIsVisited = true;

        std::cout << m_pNodeArray[nextNodeIndex].m_cData << std::endl;
    }
}

int CMap::getMinEdge(std::vector<Edge> edgeVec)
{
    //找到第一条边而且是没有被选出去的边
    int minWeight = 0;
    int edgeIndex = 0;
    int i = 0;
    for (; i < edgeVec.size(); ++i)
    {
        if (!edgeVec[i].m_bSelected)
        {
            //该边还没有被选过
            minWeight = edgeVec[i].m_iWeightValue;
            edgeIndex = i;
            break;
        }
    }

    if (minWeight == 0)
    {
        return -1;
    }

    for (; i < edgeVec.size(); ++i)
    {
        if (edgeVec[i].m_bSelected)
        {
            continue;
        }
        else
        {
            if (minWeight > edgeVec[i].m_iWeightValue)
            {
                minWeight = edgeVec[i].m_iWeightValue;
                edgeIndex = i;
            }
        }
    }
    return edgeIndex;
}