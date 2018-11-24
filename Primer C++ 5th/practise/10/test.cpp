#include <iostream>
using namespace std;

class MyClass
{
public:
    MyClass(int i) : b(i){}
    void init(int i)
    {
        a = i;
    }
    void show()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }

private:
    int a;
    int b;
};

int main(int argc, char const *argv[])
{
    MyClass *mc;
    mc = new MyClass(8);
    mc->init(10);
    mc->show();
    return 0;
    if (-1)
        cout << "abc" << endl;
}
