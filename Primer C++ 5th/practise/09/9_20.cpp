#include <iostream>
#include <list>
#include <deque>
using namespace std;

int main()
{
    list<int> iList;
    deque<int> iD1, iD2;
    for (int i = 0; i != 10; ++i)
        iList.push_back(i);
    
    list<int>::iterator iter = iList.begin();
    for (; iter != iList.end(); ++iter)
    {
        if ((*iter) % 2 == 0)
            iD1.push_back(*iter);
        else
            iD2.push_back(*iter);
    }

    deque<int>::iterator it1 = iD1.begin();
    deque<int>::iterator it2 = iD2.begin();
    cout << "偶数：";
    for (; it1 != iD1.end(); ++it1)
        cout << *it1 << ' ';

    cout << "\n奇数：";
    for (; it2 != iD2.end(); ++it2)
        cout << *it2 << ' ';
    cout << endl;
    
    return 0;
}