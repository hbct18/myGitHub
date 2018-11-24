#include <iostream>
#include <algorithm>
using namespace std;


int main(int argc, char const *argv[])
{
    int num = 5;

    auto bf = [&num]() ->bool {while (num > 0) --num;return true;};

    int j = bf();
    cout << j << endl;
    cout << num << endl;


    return 0;
}
