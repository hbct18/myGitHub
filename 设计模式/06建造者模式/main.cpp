#include "builder.h"

int main(int argc, char const *argv[])
{
    FatBuilder thin;
    Director director(&thin);
    director.Creat();
    return 0;
}
