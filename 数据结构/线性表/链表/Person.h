#ifndef PERSON_H
#define PERSON_H
#include <ostream>

class Person
{
    friend std::ostream &operator<<(std::ostream &out, Person &person);
public:
    std::string name;
    std::string phone;
    //重载赋值运算符
    Person &operator=(Person &person);
    bool operator==(Person &person);
};

#endif // !PERSON_H