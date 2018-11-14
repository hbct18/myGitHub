#include <iostream>
using namespace std;

enum CTYPE {COREA, COREB};

/**
 * 简单工厂模式 
 */
class SingleCore
{
public:
    virtual void Show() = 0;
};

// 单核A
class SingleCoreA : public SingleCore
{
public:
    void Show() { cout << "SingleCore A" << endl; }
};

// 单核B
class SingleCoreB : public SingleCore
{
public:
    void Show() { cout << "SingleCore B" << endl; }
};

// 唯一的工厂，可以生产两种型号的处理器，在内部判断
class Factory
{
public:
    SingleCore* CreateSingleCore(enum CTYPE ctype)
    {
        if (ctype == COREA)
            return new SingleCoreA();
        else if (ctype == COREB)
            return new SingleCoreB();
        else
            return NULL;
    }
};