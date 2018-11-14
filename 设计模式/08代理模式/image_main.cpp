#include "image.h"

int main(int argc, char const *argv[])
{
    Image *image = new BigImageProxy("proxy.jpg");
    image->Show();
    delete image;
    return 0;
}
