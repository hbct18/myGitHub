#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

//前置声明
extern bool grow_vec(vector<int>&, int);

//检查给定的值是否在数列中
bool is_elem(vector<int> &vec, int elem)
{
    //max_element 返回最大值位置指针
    int max_value = *(max_element(vec.begin(), vec.end()));
    if (max_value < elem)
        return grow_vec(vec, elem);
    
    if (max_value == elem)
        return true;

    //binary_search 要求对象经过排序
    vector<int> temp(vec.size());
    copy(vec.begin(), vec.end(), temp.begin());
    sort(temp.begin(), temp.end());

    return binary_search(temp.begin(), temp.end(), elem);
}

bool grow_vec(vector<int> &vec, int elem)
{
    vec.push_back(elem);
    return true;
}

//给予一个整数vector，返回一个新的vector，其中包含原vector中小于10的所有值
vector<int> less_than_10(const vector<int> &vec)
{
    vector<int> nvec;
    for (int ix = 0; ix < vec.size(); ++ix)
        if (vec[ix] < 10)
            nvec.push_back(vec[ix]);
    
    return nvec;
}

bool less_than(int v1, int v2)
{
    return v1 < v2 ? true : false;
}

bool greater_than(int v1, int v2)
{
    return v1 > v2 ? true : false;
}

vector<int> filter_ver1(const vector<int> &vec, int filter_value, bool (*pred)(int, int))
{
    vector<int> nvec;
    for (int ix = 0; ix < vec.size(); ++ix)
        //调用pred所指的函数
        //比较vec[ix]和filter_value
        if (pred(vec[ix], filter_value))
            nvec.push_back(vec[ix]);
    
    return nvec;
}


//挑选出小于指定值的数
template<typename InputIterator, typename OutputInterator, typename ElemType, typename Comp>
OutputInterator filter(InputIterator first, InputIterator last, OutputInterator at, 
    const ElemType &val, Comp pred)
{
    //bind2nd(less<int>, val)
    //会把val绑定于less<int>的第二个参数身上
    //于是，less<int> 会将每个元素拿来和 val 比较
    while ((first = find_if(first, last, bind2nd(pred, val))) != last)
    {
        // 观察进行情况
        cout << "found value: " << *first << endl;
        // 执行 assign 操作，然后令两个 iterator 前进
        *at++ = *first++;
    }
    return at;
}



int main()
{
    const int elem_size = 8;
    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia + elem_size);

    //下面这个容器用来存储过滤结果
    int ia2[elem_size];
    vector<int> ivec2;

    cout << "filtering integer array for values less then 8\n";
    filter(ia, ia + elem_size, ia2, elem_size, less<int>());

    cout << "filtering integer array for values greater than 8\n";
    filter(ivec.begin(), ivec.end(), back_inserter(ivec2), elem_size, greater<int>());

    return 0;
}