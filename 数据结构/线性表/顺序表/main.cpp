#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    Coordinate e1(3, 5);
    Coordinate e2(5, 7);
    Coordinate e3(6, 8);
    Coordinate temp(0, 0);
    List *list1 = new List(10);

    //打印长度
    cout << "length:" << list1->ListLength() << endl;
    list1->ListInsert(0, &e1);
    cout << "length:" << list1->ListLength() << endl;
    list1->ListInsert(1, &e2);
    list1->ListInsert(2, &e3);

    list1->ListTraverse();
    

    delete list1;
    return 0;
}