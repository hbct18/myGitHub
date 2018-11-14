#include <iostream>
using namespace std;

class Scanner
{
public:
    void Scan() { cout << "词法分析" << endl; }
};

class Parser
{
public:
    void Parse() { cout << "语法分析" << endl; }
};

class GenMidCode
{
public:
    void GenCode() { cout << "产生中间代码" << endl; }
};

class GenMachineCode
{
public:
    void GenCode() { cout << "产生机器代码" << endl; }
};

// 高层接口
class Compiler
{
public:
    void run()
    {
        Scanner scanner;
        Parser parser;
        GenMidCode genMidCode;
        GenMachineCode genMacCode;
        scanner.Scan();
        parser.Parse();
        genMidCode.GenCode();
        genMacCode.GenCode();
    }
};