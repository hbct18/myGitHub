#include <iostream>

std::istream& getstream(std::istream& cin)
{
    int num;
    cin >> num;
    std::cout << num << std::endl;
    cin.clear();
    return cin;
}

int main()
{
    //std::istream in_1;
    getstream(std::cin);
    return 0;
}