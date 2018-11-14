#include "resume_2.h"

class ResumeB : public Resume
{
protected:
    void SetPersonalInfo() 
    { 
        std::cout << "B's PersonalInfo" << std::endl;
    }

    void SetEducation()
    {
        std::cout << "B's Education" << std::endl;
    }

    void SetWorkExp()
    {
        std::cout << "B's Work Experience" << std::endl;
    }
};
