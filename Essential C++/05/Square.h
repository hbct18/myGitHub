/**
 * 1、4、9、16、25、36、49、64
*/

#include "num_sequence.h"

class Square : public num_sequence
{
public:
    Square(int len = 1, int beg_pos = 1)
        : _length(len), _beg_pos(beg_pos){}
    
    virtual int         elem(int pos) const;
    virtual const char* what_am_i() const { return "Square"; }
    virtual ostream&    print(ostream &os = cout) const;
    int                 length() const { return _length; }
    int                 beg_pos() const { return _beg_pos; }

protected:
    //bool                check_integrity(int pos, int size) const;
    virtual void        gen_elems(int pos) const;
    int                 _length;
    int                 _beg_pos;
    static vector<int>  _elems;
};

int Square::elem(int pos) const
{
    if (!check_integrity(pos, _elems.size()))
        return 0;
    
    if (pos > _elems.size())
        Square::gen_elems(pos);

    return _elems[pos - 1];
}

void Square::gen_elems(int pos) const
{
    if (_elems.empty())
    {
        _elems.push_back(1);
        _elems.push_back(4);
    }
    if (_elems.size() <= pos)
    {
        int ix = _elems.size();
        //int n_2 = _elems[ix - 2];
        int n_1 = _elems[ix - 1];

        for (; ix <= pos; ++ix)
        {
            int elem = n_1 + ix * 2 + 1;
            _elems.push_back(elem);
            //n_2 = n_1;
            n_1 = elem;
        }
    }
}

ostream& Square::print(ostream &os) const
{
    int elem_pos = _beg_pos - 1;
    int end_pos = elem_pos + _length;

    if (end_pos > _elems.size())
        Square::gen_elems(end_pos);

    while (elem_pos < end_pos)
        os << _elems[elem_pos++] << ' ';

    return os;
}