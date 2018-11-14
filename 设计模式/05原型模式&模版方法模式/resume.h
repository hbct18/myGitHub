#ifndef _RESUME_H_
#define _RESUME_H_

#include <iostream>

class Resume
{
protected:
    char *name;
public:
    Resume() {}
    virtual ~Resume() {}
    virtual Resume* Clone() { return NULL; }
    virtual void Set(char *n) {}
    virtual void Show() {}
};

#endif // !_RESUME_H_