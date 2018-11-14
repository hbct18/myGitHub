#include <iostream>
#include <list>
using namespace std;

class Blog;

// 观察者
class Observer
{
protected:
    string m_name;
public:
    Observer(string name) : m_name(name) {}
    virtual ~Observer() {}
    virtual void Update(Blog *blog) {}
    virtual void Attach(Blog *blog) {}
    virtual void Remove(Blog *blog) {}
};

// 博客
class Blog
{
public:
    Blog(string name) : m_name(name) {}
    virtual ~Blog() {}
    void Attach(Observer *observer) { m_observer.push_back(observer); }
    void Remove(Observer *observer) { m_observer.remove(observer); }
    void Notify()   // 通知观察者
    {
        list<Observer*>::iterator iter = m_observer.begin();
        for (; iter != m_observer.end(); ++iter)
            (*iter)->Update(this);
    }
    virtual void SetStatus(string s) { m_status = s; }  // 设置状态
    virtual string GetStatus() { return m_status; }     // 获得状态

private:
    list<Observer*> m_observer;
protected:
    string m_status;
    string m_name;
};

// 具体博客类
class BlogCSDN : public Blog
{
public:
    BlogCSDN(string name) : Blog(name) {}
    ~BlogCSDN() {}
    void SetStatus(string s) 
    {
        m_status = "CSDN通知：" + m_name + s;
        Notify();
    }
    string GetStatus() { return m_status; }
};

// 具体的观察者
class ObserverBlog : public Observer
{
public:
    ObserverBlog(string name) : Observer(name) {}
    ~ObserverBlog() {}
    void Update(Blog *blog)   // 获得更新状态
    {
        string status = blog->GetStatus();
        cout << m_name << "--------" << status << endl;
    }
    void Attach(Blog *blog) { blog->Attach(this); }
    void Remove(Blog *blog) { blog->Remove(this); }
};