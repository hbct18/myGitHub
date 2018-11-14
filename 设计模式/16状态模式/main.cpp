#include "war_state.h"

int main(int argc, char const *argv[])
{
    War *war = new War(new ProphaseState());
    for (int i = 1; i < 40; i += 5)
    {
        war->SetDays(i);
        war->GetState();
    }
    return 0;
}
