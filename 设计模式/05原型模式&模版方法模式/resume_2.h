#ifndef _RESUME_H_
#define _RESUME_H_

#include <iostream>

class Resume
{
protected:
    virtual void SetPersonalInfo() {}
    virtual void SetEducation() {}
    virtual void SetWorkExp() {}
public:
    void FillResume()
    {
        SetPersonalInfo();
        SetEducation();
        SetWorkExp();
    }
};

#endif // !_RESUME_H_