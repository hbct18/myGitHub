#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> iVec;
    istream_iterator<int> in_itr(cin), end;

    copy(in_itr, end, back_inserter(iVec));
    sort(iVec.begin(), iVec.end());

    for (vector<int>::iterator itr = iVec.begin();
         itr != iVec.end(); ++itr)
    {
        cout << *itr << endl;
    }

    return 0;

}