#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> vec1 = {"diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d"};
    int n = count_if(vec1.begin(), vec1.end(),
            [](const string &str){return str.size() > 6;});
    cout << n << endl;
    return 0;
}
