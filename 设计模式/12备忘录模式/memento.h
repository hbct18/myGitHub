#include <iostream>
#include <vector>
using namespace std;

// 需保存的信息
class Memento
{
public:
    int m_vitality; // 生命值
    int m_attack;   // 进攻值
    int m_defense;  // 防守值
public:
    Memento(int vitality, int attack, int defense)
        : m_vitality(vitality), m_attack(attack), m_defense(defense) {}
    Memento& operator=(const Memento &memento)
    {
        m_vitality = memento.m_vitality;
        m_attack = memento.m_attack;
        m_defense = memento.m_defense;
        return *this;
    }
};

// 游戏角色
class GameRole
{
private:
    int m_vitality;
    int m_attack;
    int m_defense;
public:
    GameRole() : m_vitality(100), m_attack(100), m_defense(100) {}
    Memento Save()  // 保存进度，只与 Memento 对象交互，并不牵涉到 Caretake
    {
        Memento memento(m_vitality, m_attack, m_defense);
        return memento;
    }

    void Load(Memento memento)  // 载入进度，只与 Memento 对象交互，并不牵涉到 Caretake
    {
        m_vitality = memento.m_vitality;
        m_attack = memento.m_attack;
        m_defense = memento.m_defense;
    }
    
    void Show() 
    { 
        cout << "vitality : " << m_vitality << ", attack : " 
             << m_attack << ", defense : " << m_defense << endl;
    }

    void Attack()
    {
        m_vitality -= 10;
        m_attack -= 10;
        m_defense -= 10;
    }
};

// 保存的进度
class Caretake
{
public:
    Caretake() {}
    void Save(Memento memento) { m_vecMemento.push_back(memento); }
    Memento Load(int state) { return m_vecMemento[state]; }
private:
    vector<Memento> m_vecMemento;
};