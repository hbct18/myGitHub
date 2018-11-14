#include <iostream>
#include <list>
using namespace std;

class Company
{
public:
    Company(string name) { m_name = name; }
    virtual ~Company() {}
    virtual void Add(Company *pCom) {}
    virtual void Show(int depth) {}
protected:
    string m_name;
};

// 具体公司
class ConcreteCompany : public Company
{
public:
    ConcreteCompany(string name) : Company(name) {}
    virtual ~ConcreteCompany() {}
    void Add(Company *pCom) { m_listCompany.push_back(pCom); }
    void Show(int depth)
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << m_name << endl;
        list<Company*>::iterator iter = m_listCompany.begin();
        for (; iter != m_listCompany.end(); ++iter)
            (*iter)->Show(depth + 2);
    }
private:
    list<Company*> m_listCompany;
};

// 具体部门，财务部
class FinanceDepartment : public Company
{
public:
    FinanceDepartment(string name) : Company(name) {}
    virtual ~FinanceDepartment() {}
    virtual void Show(int depth)
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << m_name << endl;
    }
};

// 具体部门，人力资源部
class HRDepartment : public Company
{
public:
    HRDepartment(string name) : Company(name) {}
    virtual ~HRDepartment() {}
    virtual void Show(int depth)
    {
        for (int i = 0; i < depth; ++i)
            cout << "-";
        cout << m_name << endl;
    }
};