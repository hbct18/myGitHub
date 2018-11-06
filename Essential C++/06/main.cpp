#include <iostream>

using namespace std;

class Test
{
public:
    virtual int ReInit();
    virtual int run();
};

int Test::ReInit()
{
    cout << "ReInit" << endl;
    return 0;
}

int Test::run()
{
    cout << "run" << endl;
    return 0;
}

int main(int argc, char *argv[])
{
    Test *tt = new Test();
    tt->run();

    return 0;
}
