#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sales_data
{
public:
    Sales_data();
    Sales_data(string s) : _isbn(s){}
    string isbn()
    {
        return _isbn;
    }
    string _isbn;
};

int main(int argc, char const *argv[])
{
    Sales_data a("because");
    Sales_data b("I");
    Sales_data c("Like");
    Sales_data d("your");
    Sales_data e("beautiful");
    Sales_data f("eyes");

    vector<Sales_data> vecSd = {a, b, c, d, e, f};

    stable_sort(vecSd.begin(), vecSd.end(),
                [](Sales_data s1, Sales_data s2){return s1.isbn().size() < s2.isbn().size();});
    cout << "排序后的vector: ";
    for (int i = 0; i < vecSd.size(); ++i)
        cout << vecSd[i].isbn() << " ";
    cout << endl;

    return 0;
}
