#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> iVec;
    vector<int> iVc;
    istream_iterator<int> in_itr(cin), end;

    copy(in_itr, end, back_inserter(iVec));
    sort(iVec.begin(), iVec.end());

    cout << "----- after sort -----" << endl;
    for (vector<int>::iterator itr = iVec.begin();
         itr != iVec.end(); ++itr)
    {
        cout << *itr << endl;
    }

    unique_copy(iVec.begin(), iVec.end(), back_inserter(iVc));

    cout << "----- after unique_copy -----" << endl;

    for (vector<int>::iterator itr = iVc.begin();
         itr != iVc.end(); ++itr)
    {
        cout << *itr << endl;
    }

    return 0;

}