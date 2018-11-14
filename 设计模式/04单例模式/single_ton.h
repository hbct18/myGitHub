#ifndef _SINGLE_TON_H_
#define _SINGLE_TON_H_

#include <iostream>

class Singleton
{
public:
    static Singleton* GetInstance(const char* name);
    virtual void Show() {}
protected:
    Singleton(){}
private:
    static Singleton *singleton;
};

#endif // !_SINGLE_TON_H_