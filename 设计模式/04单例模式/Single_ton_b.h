#ifndef _SINGLE_TON_B_H_
#define _SINGLE_TON_B_H_

#include "single_ton.h"

class SingletonB : public Singleton
{
    friend class Singleton; // 必须为友元类，否则父类无法访问子类的构造函数
public:
    void Show() { std::cout << "SingletonB" << std::endl; }
private:
    SingletonB() {}
};

#endif // !_SINGLE_TON_B_H_