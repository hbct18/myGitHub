#include <iostream>
#include "List.h"
using namespace std;

/*线性表*/
int menu()
{
    cout << "功能菜单" << endl;
    cout << "1 新建联系人" << endl;
    cout << "2 删除联系人" << endl;
    cout << "3 浏览通讯录" << endl;
    cout << "4 推出通讯录" << endl;
    cout << "请输入：";
    int order = 0;
    cin >> order;
    return order;
}

//创建联系人方法
void creatperson(List *pList)
{
    Node node;
    Person person;
    cout << "请输入用户姓名：";
    cin >> person.name;
    cout << "输入电话号码：";
    cin >> person.phone;
    node.data = person;
    pList->ListInsertTail(&node);
}

//删除联系人：先找到联系人的位置再删除
void deletePerson(List *pList, Node *temp)
{
    Node node;
    cout << "请输入用户姓名：";
    cin >> node.data.name;
    cout << "请输入电话号码：";
    cin >> node.data.phone;
    int locate = pList->LocateElem(&node);
    if (locate == -1)
    {
        cout << "没找到此联系人" << endl;
        return;
    }
    pList->ListDelete(locate, temp);
    cout << "成功删除联系人" << endl;
}

int main()
{
    int userorder = 0;
    int pId = 0;
    List *pList = new List();
    Node *pNode = new Node;
    while (userorder != 4)
    {
        userorder = menu();
        switch (userorder)
        {
        case 1:
            cout << "用户指令------》新建联系人" << endl;
            creatperson(pList);
            break;
        case 2:
            cout << "用户指令------》删除联系人" << endl;
            deletePerson(pList, pNode);
            break;
        case 3:
            cout << "用户指令------》浏览通讯录" << endl;
            pList->ListTraverse();
            break;
        case 4:
            cout << "用户指令------》退出通讯录" << endl;
            break;
        }
    }

    delete pList;
    pList = NULL;
    return 0;
}