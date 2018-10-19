#include <iostream>

template <typename elemType, typename Comp = std::less<elemType> >
class LessThanPred
{
public:
    LessThanPred(const elemType &val) : _val(val){}
    bool operator()(const elemType &val) const
                { return Comp(val, _val); }
    
    void val(const elemType &newval){ _val = newval; }
    elemType val() const { return _val; }

private:
    elemType _val;
};

class StringLen
{
public:
    bool operator()(const std::string &s1, const std::string &s2)
        { return s1.size() < s2.size(); }
};