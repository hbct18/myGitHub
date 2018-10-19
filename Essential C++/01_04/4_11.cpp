#include <iostream>
#include <vector>
using namespace std;

class num_sequence
{
public:
    typedef void (num_sequence::*PtrType)(int);

    // _pmf 可寻址下列任何一个函数
    void fibonacci(int);
    void pell(int);
    void lucas(int);
    void triangular(int);
    void sequare(int);
    void pentagonal(int);

private:
    vector<int> *_elem;                 // 指向目前所用的 vector
    PtrType _pmf;                       // 指向目前所用的算法（用以计算数列元素）
    static const int num_seq = 7;
    static PtrType func_tbl[num_seq];
    static vector<vector<int> > seq;
};