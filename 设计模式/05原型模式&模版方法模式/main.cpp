#include "resume_a.h"
#include "resume_b.h"

int main(int argc, char const *argv[])
{
    Resume *r1 = new ResumeA("A");
    Resume *r2 = new ResumeB("B");
    Resume *r3 = r1->Clone();
    Resume *r4 = r2->Clone();

    delete r1;
    delete r2;
    r1 = r2 = NULL;
    r3->Show();
    r4->Show();

    delete r3;
    delete r4;
    r3 = r4 = NULL;

    return 0;
}
