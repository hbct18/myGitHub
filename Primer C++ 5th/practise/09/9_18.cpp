#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    deque<string> dstr;
    while (cin >> str)
        dstr.push_back(str);

    deque<string>::iterator iter = dstr.begin();
    while (iter != dstr.end())
    {
        cout << *iter << endl;
        ++iter;
    }
    return 0;
}
