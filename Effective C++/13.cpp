#include <atomic>
#include <utility>
#include <iostream>
using namespace std;

atomic<int> a(10);
//assert(++a == 11);

int main()
{
    for (int i = 0; i < 10; ++i)
        cout << i << endl;
    
    return 0;
}