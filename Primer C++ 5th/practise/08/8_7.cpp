#include <iostream>
#include <fstream>
#include "../../source/1/Sales_item.h"

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream fin;
    ofstream fout;
    if  (argc != 3)
    {
        cerr << "请正确输入命令行参数！" << endl;
        return -1;
    }

    fin.open(argv[1]);
    fout.open(argv[2], ofstream::app);
    if (!fin)
    {
        cerr << "打开文件失败！" << endl;
        return -1;
    }
    Sales_item total;
    if (fin >> total)
    {
        Sales_item trans;
        while (fin >> trans)
        {
            if (total.isbn() == trans.isbn())
                total += trans;
            else
            {
                fout << total << endl;
                total = trans;
            }
        }
        fout << total << endl;
    }
    else
    {
        cerr << "No data!?" << endl;
        return -1;
    }
    fin.close();
    fout.close();

    return 0;
}
