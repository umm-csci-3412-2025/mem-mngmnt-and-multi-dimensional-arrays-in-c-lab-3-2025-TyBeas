#include "array_merge.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "../mergesort/mergesort.h"

// Function to merge multiple arrays and return a new array with unique elements
unsigned int uniqueCount(int* array, unsigned int length);

int* array_merge(int num_arrays, int* sizes, int** values) {
    assert(num_arrays > 0);  // Ensure num_arrays is non-zero

    // Total number of elements in all arrays
    unsigned int total = 0;
    for (unsigned int i = 0; i < num_arrays; i++) {
        assert(sizes[i] >= 0);  // sizes should be non-negative
        total += sizes[i];
    }

    // Allocate memory for the merged array
    int* buffer = (int*) calloc(total + 1, sizeof(int));

    if (total == 0) {
        buffer[0] = 0;  // No elements, so 0 unique
        return buffer;
    }

    // Copy the values from the input arrays into the merged array
    unsigned int index = 1;
    for (unsigned int i = 0; i < num_arrays; i++) {
        memcpy(buffer + index, values[i], sizes[i] * sizeof(int));
        index += sizes[i];
    }

    // Count unique elements
    unsigned int unique_c = uniqueCount(buffer + 1, total);

    assert(unique_c <= INT_MAX);

    // Set the unique count at the beginning of the array
    buffer[0] = (int) unique_c;

    return buffer;
}

// Function to count unique elements in an array
unsigned int uniqueCount(int* array, unsigned int length) {
    assert(length <= INT_MAX);

    // Sort the array
    mergesort(array, length);

    unsigned int dest_index = 0;
    unsigned int src_index = 0;

    // Loop through the array and remove duplicates
    while (src_index < length) {
        if (array[dest_index] == array[src_index]) {
            src_index++;
        } else {
            array[++dest_index] = array[src_index++];
        }
    }

    return dest_index + 1;
}

// Comparison function for mergesort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

