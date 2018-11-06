#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    string strBuf;
    vector<string> vecstr;
    string strFileName = "../../source/GNU_makefile_template";
    ifstream input(strFileName);
    if (input)
    {
        while (input >> strBuf)
        {
            vecstr.push_back(strBuf);
        }
    }
    else
    {
        cerr << "Can not open this file: " << strFileName << endl;
    }

    for (int i = 0; i < vecstr.size(); ++i)
        cout << vecstr[i] << endl;

    return 0;
}