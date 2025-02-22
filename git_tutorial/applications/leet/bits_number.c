#include<stdio.h>
int main()
{
    int a=2;
    int ans=0;
    while (a) 
    {
        a &= (a - 1); // Clears the rightmost set bit
        ans++;
    }
    printf("%d\n",ans);
}