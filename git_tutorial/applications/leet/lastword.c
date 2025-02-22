#include<stdio.h>
#include<string.h>

int  lastword(char *s)
{
    int count = 0;
    int b = strlen(s);
    for (int i = (b-1); i > 0; i--)
    {
        count++;
        if(s[i]==0x20)
        {
            i=0;
            count --;
        }
        
    }
    return count;
}

int main()
{
    char *a = "Hello World";
    int k   = lastword(a);
    printf("%d\n",k);
}