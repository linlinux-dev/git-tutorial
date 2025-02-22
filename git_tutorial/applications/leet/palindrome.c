#include<stdio.h>
#include<string.h>

int removeDuplicates(int* nums, int numsSize) {
    int i=0, j=1;
    while(j<numsSize){
        if(nums[i] == nums[j]) j++;
        else nums[++i] = nums[j++];
    }
    return i+1;
}

int main()
{
    int a[10]={0,0,1,1,1,2,2,3,3,4};
    int size = sizeof(a)/sizeof(a[0]);
    int k = removeDuplicates(a, size);
    for(int i=0;i<5;i++)
    {
    printf("%d",a[i]);
    }
}
