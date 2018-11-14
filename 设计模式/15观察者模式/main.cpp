#include "observe.h"

int main(int argc, char const *argv[])
{
    Observer *observer = new ObserverBlog("tutupig");

    Blog *blog1 = new BlogCSDN("wuzhekai");
    Blog *blog2 = new BlogCSDN("zhangsan");

    observer->Attach(blog1);
    observer->Attach(blog2);

    blog1->SetStatus("发表文章1");
    blog2->SetStatus("方表文章2");

    //observer->Remove(blog2);

    blog2->SetStatus("方表文章3");

    delete blog1;
    delete blog2;
    delete observer;
    return 0;
}
