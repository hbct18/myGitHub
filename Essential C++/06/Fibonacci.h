#include "num_sequence.h"

// 带有默认参数的 Fibonacci class template
template <int length, int beg_pos = 1>
class Fibonacci : public num_sequence<length, beg_pos>
{
public:
    Fibonacci() : num_sequence<length, beg_pos>(&_elems){}

protected:
    virtual void gen_elems(int pos) const;
    static std::vector<int> _elems;
};


// 声明 Fibonacci 的 static data member template
template <int length, int beg_pos>
std::vector<int> Fibonacci<length, beg_pos>::_elems;


template <int length, int beg_pos>
void Fibonacci<length, beg_pos>::gen_elems(int pos) const
{
    if (pos <= 0 || pos > num_sequence<length, beg_pos>::max_elems())
        return;
    
    if (_elems.empty())
    {
        _elems.push_back(1);
        _elems.push_back(1);
    }

    if (_elems.size() <= pos)
    {
        int ix = _elems.size();
        int n_2 = _elems[ix - 2];
        int n_1 = _elems[ix - 1];

        int elem;
        for (; ix <= pos; ++ix)
        {
            elem = n_2 + n_1;
            _elems.push_back(elem);
            n_2 = n_1;
            n_1 = elem;
        }
    }
}