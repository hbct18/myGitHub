#include "single_ton.h"

int main(int argc, char const *argv[])
{
    Singleton *st = Singleton::GetInstance("SingletonA");
    st->Show();
    return 0;
}
