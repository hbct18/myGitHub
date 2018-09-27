#ifndef MyStack_H
#define MyStack_H

#include <iostream>

template <typename T>
class MyStack
{
public:
    MyStack(int size);                      //分配内存，初始化栈空间，设定栈容量，栈顶
    ~MyStack();                             //回收栈空间内存
    bool stackEmpty();                      //判断栈是否为空
    bool stackFull();                       //判断栈是否已满
    void clearStack();                      //清空栈
    int stackLength();                      //栈中元素个数
    bool push(T elem);                      //将元素压入栈中，栈顶上升
    bool pop(T &elem);                      //将元素推出栈，栈顶下降
    void stackTraverse(bool isFromButtom);  //遍历栈中元素并输出
private:
    int m_iTop;                             //栈顶，栈中元素个数
    int m_iSize;                            //栈容量
    T *m_pBuffer;                           //栈空间指针
};

template <typename T>
MyStack<T>::MyStack(int size)
{
    m_iSize = size;
    m_pBuffer = new T[size];
    m_iTop = 0;
}

template <typename T>
MyStack<T>::~MyStack()
{
    delete[] m_pBuffer;
    m_pBuffer = NULL;
}

template <typename T>
bool MyStack<T>::stackEmpty()
{
    if (m_iTop == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
bool MyStack<T>::stackFull()
{
    if (m_iTop == m_iSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
void MyStack<T>::clearStack()
{
    m_iTop = 0;
}

template <typename T>
int MyStack<T>::stackLength()
{
    return m_iTop;
}

template <typename T>
bool MyStack<T>::push(T elem)
{
    if (stackFull())
    {
        return false;
    }
    m_pBuffer[m_iTop] = elem;
    m_iTop++;
    return true;
}

template <typename T>
bool MyStack<T>::pop(T &elem)
{
    if (stackEmpty())
    {
        return false;
    }
    m_iTop--;
    elem = m_pBuffer[m_iTop];
    return true;
}

template <typename T>
void MyStack<T>::stackTraverse(bool isFromButtom)
{
    if (isFromButtom)
    {
        for (int i = 0; i < m_iTop; ++i)
        {
            std::cout << m_pBuffer[i];
        }
    }
    else
    {
        for (int i = m_iTop - 1; i >= 0; --i)
        {
            std::cout << m_pBuffer[i];
        }
    }
}

#endif // !MyStack_H