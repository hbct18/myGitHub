#include <iostream>
using namespace std;

class War;

class State
{
public:
    virtual void Prophase() {}
    virtual void MetaPhase() {}
    virtual void Anaphase() {}
    virtual void End() {}
    virtual void CurrentState(War *war) {}
};

// 战争
class War
{
private:
    State *m_state;
    int m_days;
public:
    War(State *state) : m_state(state), m_days(0) {}
    ~War() { delete m_state; }
    int GetDays() { return m_days; }
    void SetDays(int days) { m_days = days; }
    void SetState(State *state) { delete m_state; m_state = state; }
    void GetState() { m_state->CurrentState(this); }
};

// 战争结束
class EndState : public State
{
public:
    void End(War *war)
    {
        cout << "战争结束" << endl;
    }
    void CurrentState(War *war) { End(war); }
};

// 后期
class AnaphaseState : public State
{
public:
    void Anaphase(War *war)
    {
        if (war->GetDays() < 30)
            cout << "第" << war->GetDays() << "天，战争后期，双方拼死一搏" << endl;
        else
        {
            war->SetState(new EndState());
            war->GetState();
        }
    }
    void CurrentState(War *war) { Anaphase(war); }
};

// 中期
class MetaphaseState : public State
{
public:
    void Metaphase(War *war)
    {
        if (war->GetDays() < 20)
            cout << "第" << war->GetDays() << "天，战争中期" << endl;
        else
        {
            war->SetState(new AnaphaseState());
            war->GetState();
        }
    }
    void CurrentState(War *war) { Metaphase(war); }
};

// 前期
class ProphaseState : public State
{
public:
    void Prophase(War *war)
    {
        if (war->GetDays() < 10)
            cout << "第" << war->GetDays() << "天，战争前期" << endl;
        else
        {
            war->SetState(new MetaphaseState());
            war->GetState();
        }
    }
    void CurrentState(War *war) { Prophase(war); }
};