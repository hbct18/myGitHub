#include <iostream>
#include <sstream>

using namespace std;

istream& FUNC(istream &is)
{
    string s;
    while (is >> s)
    {
        if (is.bad())
            throw runtime_error("IO流已崩溃！");
        if (is.fail())
        {
            cerr << "IO操作失败，请重试！" << endl;
            is.clear();
            is.ignore(100, '\n');   //读取并抛弃。直到读取100个或者遇到'\n'，用来清除上一次输入对下一次输入的影响
            continue;
        }
        cout << s << endl;
    }
    is.clear(); //返回流之前，对其进行复位
    return is;
}

int main(int argc, char const *argv[])
{
    string str("C++ Primer 5th");
    istringstream sin(str);
    if (sin)
        FUNC(sin);
    else
        cerr << "字符串流出现错误！" << endl;

    return 0;
}
