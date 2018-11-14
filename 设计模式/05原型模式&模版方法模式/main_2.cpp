#include "resume_a_2.h"
#include "resume_b_2.h"

int main(int argc, char const *argv[])
{
    Resume *r1;
    r1 = new ResumeA();
    r1->FillResume();
    delete r1;

    r1 = new ResumeB();
    r1->FillResume();
    delete r1;

    r1 = NULL;

    return 0;
}
