#include<stdio.h>

char* splice(char* img, int num)
{
    char* origin = img;
    img += 3;
    int t = 1;
    while (t * 10 <= num)
    {
        t *= 10;
    }
    while(t)
    {
        *img++ = num / t + '0';
        num %= t;
        t /= 10;
    }
    return origin;
}

int main()
{
    char img[10] = "img";
    for (int i = 0; i < 12; i++)
    {
        char* ans = splice(img, i);
        printf("%s\n", ans);
    }
    return 0;
}
