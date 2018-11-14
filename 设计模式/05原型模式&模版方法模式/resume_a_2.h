#include "resume_2.h"

class ResumeA : public Resume
{
protected:
    void SetPersonalInfo() 
    { 
        std::cout << "A's PersonalInfo" << std::endl;
    }

    void SetEducation()
    {
        std::cout << "A's Education" << std::endl;
    }

    void SetWorkExp()
    {
        std::cout << "A's Work Experience" << std::endl;
    }
};
