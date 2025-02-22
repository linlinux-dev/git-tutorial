#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 5;
    int *result = (int *)malloc(sizeof(int) * (a + 1));
    
    // Count the number of set bits for each number from 0 to a
    for (int i = 0; i <= a; i++) {
        int ans = 0;
        int num = i;
        while (num) {
            num &= (num - 1); // Clears the rightmost set bit
            ans++;
        }
        result[i] = ans; // Store the result in the array
    }

    // Print the results
    for (int j = 0; j <= a; j++) {
        printf("Number of 1s in %d: %d\n", j, result[j]);
    }

    free(result); // Free the allocated memory
    return 0;
}

