#include "replace_algorithm.h"

class Cache
{
private:
    ReplaceAlgorithm *m_ra;
public:
    Cache(ReplaceAlgorithm *ra) { m_ra = ra; }
    ~Cache() { delete m_ra; }
    void Replace() { m_ra->Replace(); }
};

int main(int argc, char const *argv[])
{
    Cache cache(new LRU_ReplaceAlgorithm());
    cache.Replace();

    return 0;
}
