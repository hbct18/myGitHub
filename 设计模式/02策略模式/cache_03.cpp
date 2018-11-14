#include "replace_algorithm.h"

template <class RA>
class Cache
{
private:
    RA m_ra;
public:
    Cache() {}
    ~Cache() {}
    void Replace() { m_ra.Replace(); }
};

int main(int argc, char const *argv[])
{
    Cache<Random_ReplaceAlgorithm> cache;
    cache.Replace();

    return 0;
}
