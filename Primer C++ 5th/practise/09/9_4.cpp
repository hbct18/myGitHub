#include <iostream>
#include <vector>

bool searchNum(std::vector<int>::iterator iBegin,
               std::vector<int>::iterator iEnd, int num)
{
    for (; iBegin != iEnd; ++iBegin)
    {
        if (*iBegin == num)
            return true;
    }
    return false;
}

std::vector<int>::iterator searchNum2(std::vector<int>::iterator iBegin,
               std::vector<int>::iterator iEnd, int num)
{
    for (; iBegin != iEnd; ++iBegin)
    {
        if (*iBegin == num)
            return iBegin;
    }
    return iEnd;
}
