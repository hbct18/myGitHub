#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    vector<int> iVec = {1,2,3,4,5,6,7,8,9};
    list<int> vec1, vec2, vec3;
    copy(iVec.begin(), iVec.end(), inserter(vec1, vec1.begin()));
    copy(iVec.begin(), iVec.end(), back_inserter(vec2));
    copy(iVec.begin(), iVec.end(), front_inserter(vec3));

    //list<int>::iterator itr;
    ostream_iterator<int> out_itr(cout, " ");

    /*for (itr = vec1.begin(); itr != vec1.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    for (itr = vec2.begin(); itr != vec2.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    for (itr = vec3.begin(); itr != vec3.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;*/
    copy(vec1.begin(), vec1.end(), out_itr);
    cout << endl;
    copy(vec2.begin(), vec2.end(), out_itr);
    cout << endl;
    copy(vec3.begin(), vec3.end(), out_itr);
    cout << endl;

    return 0;
}