#ifndef _NUM_SEQUENCE_H_
#define _NUM_SEQUENCE_H_

#include <iostream>
#include <vector>
using namespace std;

class num_sequence
{
public:
    virtual ~num_sequence(){}

    virtual const char* what_am_i() const = 0;                  // 返回确切的数列型别
    int                 elem(int pos) const;                // 返回 pos 位置的元素
    ostream&            print(ostream& os = cout) const;    // 将所有元素写入 os
    int                 length() const { return _length; }
    int                 beg_pos() const { return _beg_pos; }
    static int          max_elems(){ return 64; };      // 返回所支持的最大位置值

protected:
    virtual void        gen_elems(int pos) const = 0;           // 产生直到 pos 位置的所有元素
    bool                check_integrity(int pos, int size) const;         // 检查 pos 是否为有效位置

    num_sequence(int len, int bp, vector<int> &re)
        : _length(len), _beg_pos(bp), _relems(re){}
    
    int                 _length;
    int                 _beg_pos;
    vector<int>         &_relems;
};

ostream& operator<<(ostream &os, const num_sequence &ns)
{ return ns.print(os); }

bool num_sequence::check_integrity(int pos, int size) const
{
    if (pos <= 0 || pos > 64)
    {
        cerr << "!! invalid position: " << pos
             << " Cannot honor request!\n";
        return false;
    }
    if (pos > size)
        gen_elems(pos); // 通过虚拟机制调用
    return true;
}

#endif // !_NUM_SEQUENCE_H_