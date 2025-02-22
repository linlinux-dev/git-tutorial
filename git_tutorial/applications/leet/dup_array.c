#include <stdio.h>

int removeDuplicates(int arr[], int size) {
    if (size == 0) return 0;  // No elements to process

    int uniqueIndex = 1;  // Pointer to track the next unique element position

    // Sort the array first (optional if input is unsorted)
    // You can use any sorting algorithm, but here I use a simple bubble sort for clarity
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Iterate through the sorted array and keep unique elements
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i - 1]) {  // Compare with the previous element
            arr[uniqueIndex++] = arr[i];  // Update the unique position
        }
    }

    return uniqueIndex;  // Return the new size of the array without duplicates
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 3, 2, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print original array
    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Remove duplicates and get the new size
    int newSize = removeDuplicates(arr, size);

    // Print array without duplicates
    printf("Array after removing duplicates: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
