#include <stdio.h>
#include <cstdlib>

int** fun(int* nums, int numsSize, int target) {
    // Allocate memory for a pointer to a pointer (int**), i.e., an array of 1 pointer
    int* result = (int*) malloc(sizeof(int)*4);
    
}

int main() {
    int size = 6;
    int target = 0;
    int a = 5;

    // Call fun to get a pointer to a pointer (int**)
    int** k = fun(a, size, target);
        free(k);
    return 0;
}
