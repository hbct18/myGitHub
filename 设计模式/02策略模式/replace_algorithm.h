#include <iostream>

// 抽象接口
class ReplaceAlgorithm
{
public:
    virtual void Replace() = 0;
};

// 三种具体的替换算法
class LRU_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
    void Replace() 
    { 
        std::cout << "Least Recently Used replace algorithm" << std::endl; 
    }
};

class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
    void Replace()
    {
        std::cout << "First in First out replace algorithm" << std::endl;
    }
};

class Random_ReplaceAlgorithm : public ReplaceAlgorithm
{
public:
    void Replace()
    {
        std::cout << "Random replace algorithm" << std::endl;
    }
};