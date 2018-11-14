#include <iostream>
using namespace std;

class Mediator;

// 抽象人
class Person
{
protected:
    Mediator *m_mediator;   // 中介
public:
    virtual void SetMediator(Mediator *mediator) {} // 设置中介
    virtual void SendMessage(string messages) {}    // 向中介发送信息
    virtual void GetMessage(string messages) {}     // 从中介获取信息
};

// 抽象中介机构
class Mediator
{
public:
    virtual void Send(string message, Person *person) {}
    virtual void SetA(Person *A) {}     // 设置其中一方
    virtual void SetB(Person *B) {}
};

// 租房者
class Renter : public Person
{
public:
    void SetMediator(Mediator *mediator) { m_mediator = mediator; }
    void SendMessage(string message) { m_mediator->Send(message, this); }
    void GetMessage(string message) { cout << "租房者收到信息：" << message << endl; }
};

// 房东
class Landlord : public Person
{
public:
    void SetMediator(Mediator *mediator) { m_mediator = mediator; }
    void SendMessage(string message) { m_mediator->Send(message, this); }
    void GetMessage(string message) { cout << "房东收到信息：" << message << endl; }
};

// 房屋中介
class HoseMediator : public Mediator
{
private:
    Person *m_A;    // 租房者
    Person *m_B;    // 房东
public:
    HoseMediator() : m_A(0), m_B(0) {}
    void SetA(Person *A) { m_A = A; }
    void SetB(Person *B) { m_B = B; }
    void Send(string message, Person *person)
    {
        if (person == m_A)  // 租房者给房东发信息
            m_B->GetMessage(message);   // 房东收到信息
        else
            m_A->GetMessage(message);
    }
};