#include<stdio.h>
#include<stdlib.h>

int *duplicate(int *nums, int sizeofarray, int *returnsize)
{
    // Allocate memory for the result array (up to the original size)
    int *b = (int*)malloc(sizeof(int) * sizeofarray);
    if (b == NULL) {
        printf("Memory allocation failed\n");
        *returnsize = 0;
        return NULL;
    }

    int uniqueIndex = 0;  // To keep track of the position for unique elements
    
    for (int i = 0; i < sizeofarray; i++) {
        int isDuplicate = 0;
        
        // Check if nums[i] is already in the result array (b)
        for (int j = 0; j < uniqueIndex; j++) {
            if (nums[i] == b[j]) {
                isDuplicate = 1;  // Found a duplicate
                break;
            }
        }
        
        // If it's not a duplicate, add it to the result array
        if (!isDuplicate) {
            b[uniqueIndex++] = nums[i];
        }
    }

    *returnsize = uniqueIndex;  // Set the return size to the number of unique elements
    return b;  // Return the new array with unique elements
}

int main()
{
    int a[10] = {5, 5, 6, 7, 3, 8, 9, 4, 1, 2};
    int size = sizeof(a) / sizeof(a[0]);
    int retsize = 0;

    // Get the unique elements
    int *ans = duplicate(a, size, &retsize);

    if (ans != NULL) {
        // Print the unique elements
        printf("Array after removing duplicates: ");
        for (int i = 0; i < retsize; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");

        // Free the dynamically allocated memory
        free(ans);
    } else {
        printf("No memory allocated for duplicates.\n");
    }

    return 0;
}
