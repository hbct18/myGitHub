#include <iostream>
#include "List.h"

List::List(int size)
{
    m_iSize = size;
    m_pList = new Coordinate[m_iSize];
    m_iLength = 0;
}

List::~List()
{
    delete []m_pList;
    m_pList = NULL;
}

void List::ClearList()
{
    m_iLength = 0;
}

bool List::ListEmpty()
{
    return m_iLength == 0 ? true : false;
}

int List::ListLength()
{
    return m_iLength;
}

bool List::GetElem(int i, Coordinate *e)
{
    if (i < 0 || i >= m_iSize)
    {
        return false;
    }
    *e = m_pList[i];
    return true;
}

//定位一个元素，找到返回下标
int List::LocateElem(Coordinate *e)
{
    for (int i = 0; i < m_iLength; ++i)
    {
        if (m_pList[i] == *e)
        {
            return i;
        }
    }
    //找不到
    return -1;
}

//获取指定元素前驱
bool List::PriorElem(Coordinate *currentElem, Coordinate *preElem)
{
    int temp = LocateElem(currentElem);
    //没有这个元素，或者这个元素是第一个元素，没有前驱
    if (temp == -1 || temp == 0)
    {
        return false;
    }
    else
    {
        *preElem = m_pList[--temp];
        return true;
    }
}

//找到指定元素的后继
bool List::NextElem(Coordinate *currentElem, Coordinate *nextElem)
{
    int temp = LocateElem(currentElem);
    //没有这个元素，或者这个元素是最后一个元素，没有后继
    if (temp == -1 || temp == --m_iLength)
    {
        return false;
    }
    else
    {
        *nextElem = m_pList[++temp];
        return true;
    }
}

//遍历整张线性表
void List::ListTraverse()
{
    for (int i = 0; i < m_iLength; ++i)
    {
        std::cout << m_pList[i] << std::endl;
    }
}

//插入元素e作为数组的第i个元素，要记得后移其他元素
bool List::ListInsert(int i, Coordinate *e)
{
    if (i < 0 || i >= m_iSize)
    {
        std::cout << "Warning: 插入未完成，请输入合法的下标" << std::endl;
        return false;
    }
    
    for (int k = m_iLength - 1; k >= i; --k)
    {
        m_pList[k + 1] = m_pList[k];
    }

    m_pList[i] = *e;

    //判断是否已满
    if (m_iLength >= m_iSize)
    {
        std::cout << "Warning: 插入成功，容量有限，最后的元素被抛弃" << std::endl;
    }
    else
    {
        m_iLength++;
    }
    return true;
}

//删除数组第i个元素
bool List::ListDelete(int i, Coordinate *e)
{
    if (i < 0 || i >= m_iSize)
    {
        std::cout << "Warning: 删除的下标非法" << std::endl;
        return false;
    }

    *e = m_pList[i];
    for (int k = i + 1; k < m_iLength; ++k)
    {
        m_pList[k - 1] = m_pList[k];
    }

    //判断是否为空
    if (m_iLength <= 0)
    {
        std::cout << "Warning: List已空，删除失败" << std::endl;
    }
    else
    {
        m_iLength--;
    }
    return true;
}