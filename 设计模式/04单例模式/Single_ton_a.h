#ifndef _SINGLE_TON_A_H_
#define _SINGLE_TON_A_H_

#include "single_ton.h"

class SingletonA : public Singleton
{
    friend class Singleton; // 必须为友元类，否则父类无法访问子类的构造函数
public:
    void Show() { std::cout << "SingletonA" << std::endl; }
private:
    SingletonA() {}
};

#endif // !_SINGLE_TON_A_H_