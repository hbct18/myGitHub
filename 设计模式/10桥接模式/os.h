#include <iostream>
using namespace std;

class OS
{
public:
    virtual void InstallOS_Imp() {}
};

class WindowOS : public OS
{
public:
    virtual void InstallOS_Imp()
    {
        cout << "安装 Window 操作系统" << endl;
    }
};

class LinuxOS : public OS
{
public:
    virtual void InstallOS_Imp()
    {
        cout << "安装 Linux 操作系统" << endl;
    }
};

class UnixOS : public OS
{
public:
    virtual void InstallOS_Imp()
    {
        cout << "安装 Unix 操作系统" << endl;
    }
};