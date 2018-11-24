#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[])
{
    //vector<int> iVec = {1,2,3,2,1,4,2,6,8,9,7,5,6};
    //list<int> iList;

    vector<string> iVec = {"love","love8","love","love","love","h","diuw","diuwudhg257","love","d"};  
	list<string> iList;

    // unique_copy 删除相邻的重复值，需要先排序才能删重
    sort(iVec.begin(), iVec.end());
    unique_copy(iVec.begin(), iVec.end(), back_inserter(iList));
    list<string>::iterator itr = iList.begin();

    for (; itr != iList.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
    return 0;
}
