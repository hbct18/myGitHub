#include "computer.h"

int main(int argc, char const *argv[])
{
    OS *os1 = new WindowOS();
    OS *os2 = new LinuxOS();
    Computer *cp1 = new AppleComputer();
    cp1->InstallOs(os1);
    cp1->InstallOs(os2);

    return 0;
}
