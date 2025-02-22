#include<stdio.h>

int sumIndicesWithKSetBits(int* nums, int numsSize, int k) 
{
    int ans = 0;
    int sum = 0;
    for(int i = 0; i<numsSize; i++)
    {
        int count = 0;
        int num = i;
        while(num)
        {
            num &= (num-1);
            count++;
        }
        if(count == k)
        {
           sum = sum + nums[i];
        }
    }
    return sum;
}

int main()
{
    int a[]     = {4,3,2,1};
    int k       = 2;
    int size    = sizeof(a) / sizeof(a[0]);
    int answer  = sumIndicesWithKSetBits(a,size,k);
    printf("%d\n",answer);   
}
