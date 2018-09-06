#include "myclass.h"

Person::Person()
{
    std::cout << "Create Person!" << std::endl;
}

Person::~Person()
{
    std::cout << "Delete Person!" << std::endl;
}

void Person::sayHello()
{
    std::cout << "Hello!" << std::endl;
}