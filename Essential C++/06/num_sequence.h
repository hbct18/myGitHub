#include <iostream>
#include <vector>

template <int len, int beg_pos>
class num_sequence
{
public:
    virtual         ~num_sequence(){}
    int             elem(int pos) const;
    const char*     what_am_i() const;
    static int      max_elems(){ return _max_elems; }
    std::ostream&   print(std::ostream &os = std::cout) const;

protected:
    virtual void    gen_elems(int pos) const = 0;
    bool            check_integrity(int pos, int size) const;

    num_sequence(std::vector<int> *pe) : _pelems(pe){}
    static const int _max_elems = 1024;
    std::vector<int> *_pelems;
};

template <int len, int beg_pos>
std::ostream& operator<<(std::ostream &os, const num_sequence<len, beg_pos> &ns)
{ return ns.print(os); }

template <int len, int beg_pos>
int num_sequence<len, beg_pos>::elem(int pos) const
{
    if (!check_integrity(pos ,_pelems->size()))
        return 0;
    
    return (*_pelems)[pos - 1];
}

template <int len, int beg_pos>
const char* num_sequence<len, beg_pos>::what_am_i() const
{ return typeid(*this).name(); }

template <int len, int beg_pos>
bool num_sequence<len, beg_pos>::check_integrity(int pos, int size) const
{
    if (pos <= 0 || pos > max_elems())
    {
        std::cerr << "!! invalid position: " << pos
             << " cannot honor request!\n";
        return false;
    }
    if (pos > size) gen_elems(pos);
    return true;
}

template <int len, int beg_pos>
std::ostream& num_sequence<len, beg_pos>::print(std::ostream &os) const
{
    int elem_pos = beg_pos - 1;
    int end_pos = elem_pos + len;

    if (!check_integrity(end_pos, _pelems->size()))
        return os;
    
    os << "( " << beg_pos << " , " << len << " ) ";

    while (elem_pos < end_pos)
        os << (*_pelems)[elem_pos++] << ' ';

    return os;
}
