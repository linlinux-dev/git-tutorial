#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 3;

    int k ;
    int *result = (int *)malloc(sizeof(int) * (a+1));
    for(int i=0;i<=a;i++)
    {
        int ans = 0;
        int j = i;
        while(j)
        {
            k = (j & 255);
            j >>= 1;
            ans++;
        }
        result[i]=ans;
    }
    for(int j=0;j<=a;j++)
    {
        printf("%d\n",result);
    }
}
