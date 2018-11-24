#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int main()
{
    ifstream fin("10_29.cpp");
    istream_iterator<string> in_itr(fin), eof;
    vector<string> strVec(in_itr, eof);
    for (vector<string>::iterator itr = strVec.begin();
            itr != strVec.end(); ++itr)
        cout << *itr << endl;
    
    return 0;
}