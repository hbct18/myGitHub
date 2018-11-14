#include "phone.h"

int main(int argc, char const *argv[])
{
    Phone *iphone = new NokiaPhone("6300");
    Phone *dpa = new DecoratorPhoneA(iphone);
    Phone *dpb = new DecoratorPhoneB(dpa);
    dpb->ShowDecorate();
    delete dpa;
    delete dpb;
    delete iphone;
    return 0;
}
