#include <iostream>

void logCall(const std::string& funcName);

class Date{};

class Customer
{
public:
    Customer(const Customer& rhs);
    Customer& operator=(const Customer& rhs);

private:
    std::string name;
    Date lastTransaction;
};

Customer::Customer(const Customer& rhs)
    : name(rhs.name)
{
    logCall("Customer copy constructor");
}

Customer& Customer::operator=(const Customer& rhs)
{
    logCall("Customer copy assignment operator");
    name = rhs.name;
    return *this;
}