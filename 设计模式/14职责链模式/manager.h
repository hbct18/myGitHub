#include <iostream>
using namespace std;

// 抽象管理者
class Manager
{
protected:
    Manager *m_manager;
    string m_name;
public:
    Manager(Manager *manager, string name)
        : m_manager(manager), m_name(name) {}
    virtual void DealWithRequest(string name, int num) {}
    string getName() { return m_name; }
};

// 经理
class CommonManager : public Manager
{
public:
    CommonManager(Manager *manager, string name)
        : Manager(manager, name) {}
    void DealWithRequest(string name, int num)
    {
        if (num < 500)  // 经理职权范围内
        {
            cout << "经理" << m_name << "批准" 
                 << name << "加薪" << num << endl;
        }
        else
        {
            cout << "经理" << m_name << "无法处理，交由总监"
                 << m_manager->getName() << "处理" << endl;
            m_manager->DealWithRequest(name, num);
        }
    }
};

// 总监
class Majordomo : public Manager
{
public:
    Majordomo(Manager *manager, string name)
        : Manager(manager, name) {}
    void DealWithRequest(string name, int num)
    {
        if (num < 1000)  // 经理职权范围内
        {
            cout << "总监" << m_name << "批准" 
                 << name << "加薪" << num << endl;
        }
        else
        {
            cout << "总监" << m_name << "无法处理，交由总经理"
                 << m_manager->getName() << "处理" << endl;
            m_manager->DealWithRequest(name, num);
        }
    }
};

// 总经理
class GeneralManager : public Manager
{
public:
    GeneralManager(Manager *manager, string name)
        : Manager(manager, name) {}
    void DealWithRequest(string name, int num)
    {
        cout << "总经理" << m_name << "批准" 
             << name << "加薪" << num << endl;
    }
};