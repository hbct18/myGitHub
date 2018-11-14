#include "mediaor.h"

int main(int argc, char const *argv[])
{
    Mediator *mediator = new HoseMediator();
    Person *p1 = new Renter();      // 租房者
    Person *p2 = new Landlord();    // 房东
    mediator->SetA(p1);
    mediator->SetB(p2);
    p1->SetMediator(mediator);
    p2->SetMediator(mediator);
    p1->SendMessage("我想租房子");
    p2->SendMessage("出租房子");
    delete p1;
    delete p2;
    delete mediator;
    return 0;
}
