#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream fin("fout");
    string str;
    vector<string> vecstr;
    while (getline(fin, str))
        vecstr.push_back(str);
    fin.close();
    
    for (int i = 0; i < vecstr.size(); ++i)
    {
        istringstream sin(vecstr[i]);
        while (sin >> str)
            cout << str << endl;
    }
    return 0;
}
