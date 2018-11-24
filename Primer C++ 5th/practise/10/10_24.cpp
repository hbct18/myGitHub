#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

bool check_size(const string &s, string::size_type sz)
{
    return s.length() < sz;
}

int main(int argc, char const *argv[])
{
    string str = "abc";
    vector<int> iVec = {1, 2, 3, 4, 5};
    vector<int>::iterator itr = find_if(iVec.begin(), iVec.end(),
            bind(check_size, str, placeholders::_1));
    
    if (itr != iVec.end())
        cout << *itr << endl;
    return 0;
}
