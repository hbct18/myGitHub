#include "manager.h"

int main(int argc, char const *argv[])
{
    Manager *general = new GeneralManager(NULL, "A");   // 设置上级和名字，总经理没有上级
    Manager *majordomo = new Majordomo(general, "B");
    Manager *common = new CommonManager(majordomo, "C");
    common->DealWithRequest("D", 300);  // 员工D要求加薪
    common->DealWithRequest("E", 600);
    common->DealWithRequest("F", 1000);
    delete common;
    delete majordomo;
    delete general;
    return 0;
}