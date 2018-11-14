#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<int> vec1;
vector<int> vec2(10);
vector<int> vec3(10, 1);
vector<int> vec4 = {1, 2, 3};
vector<int> vec5(vec1);
vector<int> vec6(vec1.begin(), vec1.end());

int main(int argc, char const *argv[])
{
    // 拷贝用的list和vector
    list<int> list1(7, 8);
    vector<int> vt2(5, 2);

    // 创建的目标容器
    vector<double> vt1(list1.begin(), list1.end());
    vector<double> vt3(vt2.begin(), vt2.end());

    // 验证正确性
    vector<double>::iterator it1 = vt1.begin();
    vector<double>::iterator it2 = vt3.begin();
    for (; it1 != vt1.end(); ++it1)
    {
        cout << *it1 << endl;
    }
    for(; it2 != vt3.end(); ++it2)
    {
        cout << *it2 << endl;
    }

    return 0;
}

