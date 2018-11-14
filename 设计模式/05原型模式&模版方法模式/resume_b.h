#include "resume.h"

class ResumeB : public Resume
{
public:
    ResumeB(const char *str);   // 构造函数
    ResumeB(const ResumeB &r);  // 拷贝构造函数
    ~ResumeB();                 // 析构函数
    ResumeB* Clone();           // 克隆，关键所在
    void Show();                // 显示内容
};
ResumeB::ResumeB(const char *str)
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
ResumeB::~ResumeB() { delete []name; }
ResumeB::ResumeB(const ResumeB &r)
{
    name = new char[strlen(r.name) + 1];
    strcpy(name, r.name);
}
ResumeB* ResumeB::Clone()
{
    return new ResumeB(*this);
}
void ResumeB::Show()
{
    std::cout << "ResumeB name : " << name << std::endl;
}
