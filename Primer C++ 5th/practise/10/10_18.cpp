#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void elimDups(vector<string> &s)
{
    sort(s.begin(), s.end());   // sort排序
    vector<string>::iterator itr = unique(s.begin(), s.end());  // unique 去重排序
    s.erase(itr, s.end());
}

void biggis(vector<string> &s, vector<string>::size_type sz)
{
    elimDups(s);    // 字典排序，删除重复
    stable_sort(s.begin(), s.end(), 
        [](const string &a, const string &b){return a.size() < b.size();});

    // partition 返回最后一个使谓词为 true 的元素的后一个位置的迭代器
    // 使用小于 sz 得到的是第一个大于等于 sz 的指针
    auto it1 = stable_partition(s.begin(), s.end(), 
               [sz](const string &s){return s.size() < sz;});
    for (; it1 != s.end(); ++it1)
        cout << *it1 << " ";
}

int main(int argc, char const *argv[])
{
    vector<string> vec1 = {"diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d"};
    biggis(vec1, 4);
    return 0;
}
