#ifndef EDGE_H
#define EDGE_H

class Edge
{
public:
    Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightValue = 0);
    int m_iNodeIndexA;//边的两个顶点
    int m_iNodeIndexB;

    int m_iWeightValue;//边上的权值

    bool m_bSelected;//标记已经挑选出来的边
};

#endif // !EDGE_H