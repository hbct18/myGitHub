#include "resume.h"

class ResumeA : public Resume
{
public:
    ResumeA(const char *str);   // 构造函数
    ResumeA(const ResumeA &r);  // 拷贝构造函数
    ~ResumeA();                 // 析构函数
    ResumeA* Clone();           // 克隆，关键所在
    void Show();                // 显示内容
};
ResumeA::ResumeA(const char *str)
{
    if (str == NULL)
    {
        name = new char[1];
        name[0] = '\0';
    }
    else
    {
        name = new char[strlen(str) + 1];
        strcpy(name, str);
    }
}
ResumeA::~ResumeA() { delete []name; }
ResumeA::ResumeA(const ResumeA &r)
{
    name = new char[strlen(r.name) + 1];
    strcpy(name, r.name);
}
ResumeA* ResumeA::Clone()
{
    return new ResumeA(*this);
}
void ResumeA::Show()
{
    std::cout << "ResumeA name : " << name << std::endl;
}
