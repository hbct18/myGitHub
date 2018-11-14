#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    // 问题初始化
    list<char*> list1;
    vector<string> vecstr;
    vecstr.assign(list1.cbegin(), list1.cend());
    return 0;
}
