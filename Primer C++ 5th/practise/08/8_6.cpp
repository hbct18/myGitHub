#include <iostream>
#include <fstream>
#include "../../source/1/Sales_item.h"

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream fin;

    if (argc != 2)
    {
        cerr << "请正确输入命令行参数！" << endl;
        return -1;
    }

    fin.open(argv[1]);
    if (!fin)
    {
        cerr << "打开文件失败：" << argv[1] << endl;
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
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    }
    else
    {
        cerr << "No data !?" << endl;
        return -1;
    }
    fin.close();
    
    return 0;
}
