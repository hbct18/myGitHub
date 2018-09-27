#include "Person.h"

Person &Person::operator=(Person &person)
{
    this->name = person.name;
    this->phone = person.phone;
    
    return *this;
}

bool Person::operator==(Person &person)
{
    if (this->name == person.name && this->phone == person.phone)
    {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &out, Person &person)
{
    out << person.name << "--------" << person.phone << std::endl;
    return out;
}