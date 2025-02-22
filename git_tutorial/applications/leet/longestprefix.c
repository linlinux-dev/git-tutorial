#include <stdio.h>
int main()
{
    char a = 'a';
    char b = 'b';
    char c = 'c';
    char *a[3] = {&a,&b,&c};
    for (int i = 0; i < 2; i++) 
    {
        printf("%c\n", a[i]);
    }
    return 0;
}