#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

bool bFunc(const string &str, size_t sz)
{
    return str.size() <= sz;
}

int main(int argc, char const *argv[])
{
    vector<string> vec1 = {"diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d"};
    
    int n = count_if(vec1.begin(), vec1.end(), bind(bFunc, placeholders::_1, 6));
    cout << n << endl;
    return 0;
}
