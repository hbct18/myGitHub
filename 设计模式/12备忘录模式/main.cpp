#include "memento.h"

int main(int argc, char const *argv[])
{
    Caretake caretake;
    GameRole role;

    cout << "---- The First ----" << endl;
    role.Show();    // 初始值
    caretake.Save(role.Save());
    role.Attack();

    cout << "---- After Attack ----" << endl;
    role.Show();    // 进攻后
    role.Load(caretake.Load(0));

    cout << "---- After Load ----" << endl;
    role.Show();

    return 0;
}
