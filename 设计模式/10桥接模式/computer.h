#include "os.h"

class Computer
{
public:
    virtual void InstallOs(OS *os) {}
};

class DellComputer : public Computer
{
public:
    void InstallOs(OS *os)
    { 
        cout << "DellComputer ";
        os->InstallOS_Imp(); 
    }
};

class AppleComputer : public Computer
{
public:
    void InstallOs(OS *os) 
    { 
        cout << "AppleComputer ";
        os->InstallOS_Imp(); 
    }
};

class HPComputer : public Computer
{
public:
    void InstallOs(OS *os)
    { 
        cout << "HPComputer ";
        os->InstallOS_Imp(); 
    }
};