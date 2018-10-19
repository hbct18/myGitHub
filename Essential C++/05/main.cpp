#include "Fibonacci.h"
#include "Lucas.h"
#include "Pell.h"
#include "Triangular.h"
#include "Square.h"
#include "Pentagonal.h"

vector<int> Fibonacci::_elems;
vector<int> Lucas::_elems;
vector<int> Pell::_elems;
vector<int> Triangular::_elems;
vector<int> Square::_elems;
vector<int> Pentagonal::_elems;

inline void display(ostream &os, const num_sequence &ns, int pos)
{
    os << "The element at position " << pos << " for the "
       << ns.what_am_i() << " sequence is "
       << ns.elem(pos) << endl;
}

int main()
{
    const int pos = 8;
    Fibonacci fib(8);
    display(cout, fib, pos);

    Pell pell(6, 4);
    display(cout, pell, pos);

    Lucas lucas(10, 7);
    display(cout, lucas, pos);

    Triangular trian(12);
    display(cout, trian, pos);

    Square square(6, 6);
    display(cout, square, pos);

    Pentagonal penta(8);
    display(cout, penta, pos);

    cout << "fib: " << fib << '\n'
         << "pell: " << pell << '\n'
         << "lucas: " << lucas << '\n'
         << "trian: " << trian << '\n'
         << "square: " << square << '\n'
         << "penta: " << penta << endl;

    return 0;
}