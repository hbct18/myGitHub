#include "Coordinate.h"

Coordinate::Coordinate(int x, int y)
{
    m_iX = x;
    m_iY = y;
}

void Coordinate::printCoordinate()
{
    std::cout << "( " << m_iX << ", " << m_iY << " )" << std::endl;
}

std::ostream & operator<<(std::ostream &out, Coordinate &coor)
{
    std::cout << "( " << coor.m_iX << ", " << coor.m_iY << " )" << std::endl;
    return out;
}

bool Coordinate::operator==(Coordinate &coor)
{
    if (this->m_iX == coor.m_iX && this->m_iY == coor.m_iY)
    {
        return true;
    }
    else
    {
        return false;
    }
}