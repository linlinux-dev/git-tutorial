#include <stdio.h>
#include <cstdlib>

int** fun(int* nums, int numsSize, int target) {
    // Allocate memory for a pointer to a pointer (int**), i.e., an array of 1 pointer
    int** result = (int**) malloc(sizeof(int*));

    // Allocate memory for 4 integers (this is the array that will hold the result)
    result[0] = (int*) malloc(sizeof(int) * 4);

    if (result[0] == NULL) {
        free(result);  // Free result if memory allocation fails
        return NULL;
    }

    // Iterate through the array to find combinations of 4 numbers that sum to target
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                for (int n = k + 1; n < numsSize; n++) {
                    if (nums[i] + nums[j] + nums[k] + nums[n] == target) {
                        result[0][0] = nums[i];
                        result[0][1] = nums[j];
                        result[0][2] = nums[k];
                        result[0][3] = nums[n];
                        return result;  // Return the result when a valid combination is found
                    }
                }
            }
        }
    }

    free(result[0]);  // Free the allocated memory if no valid combination is found
    free(result);
    return NULL;  // Return NULL if no valid combination is found
}

int main() {
    int size = 6;
    int target = 0;
    int a[6] = {1, 0, -1, 0, -2, 2};

    // Call fun to get a pointer to a pointer (int**)
    int** k = fun(a, size, target);

    if (k != NULL) {
        // Dereference k to get the first array and print its values
        for (int l = 0; l < 4; l++) {
            printf("%d ", k[0][l]);  // Dereference k[0] to access the array of 4 integers
        }
        // Free the dynamically allocated memory after use
        free(k[0]);
        free(k);
    } else {
        printf("No valid combination found.\n");
    }

    return 0;
}
