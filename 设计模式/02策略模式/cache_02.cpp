#include "replace_algorithm.h"

enum RA {LRU, FIFO, RANDOM};

class Cache
{
private:
    ReplaceAlgorithm *m_ra;
public:
    Cache(RA ra) 
    {
        if (ra == LRU)
            m_ra = new LRU_ReplaceAlgorithm(); 
        else if (ra == FIFO)
            m_ra = new FIFO_ReplaceAlgorithm();
        else if (ra == RANDOM)
            m_ra = new Random_ReplaceAlgorithm();
        else
            m_ra = NULL;
    }
    ~Cache() { delete m_ra; }
    void Replace() { m_ra->Replace(); }
};

int main(int argc, char const *argv[])
{
    Cache cache(LRU);
    cache.Replace();

    return 0;
}
