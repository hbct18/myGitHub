#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    //const char* pIn = "58D9";
    //char* pOut;
    stringstream sstr("58D9");
    int x;
    sstr >> x;
    //printf( pOut, "%llx",atoi( pIn ) );
    cout << x << endl;
    return 0;
}
