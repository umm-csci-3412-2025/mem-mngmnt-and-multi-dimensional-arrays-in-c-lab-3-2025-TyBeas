#include "mergesort.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Internal function to sort an array using mergesort
void int_mergesort(unsigned int size, int* values);

// Merge two sorted arrays into a single sorted array
void merge_arrays(int* dest, unsigned int left_size, int* left, unsigned int right_size, int* right);

// Sort arrays with size and values
void mergesort(int raw_size, int* values) {
    assert(raw_size > 0);  // Assert non-zero size
    unsigned int size = (unsigned int) raw_size;

    if (size == 0) return;  // Handle empty array

    int_mergesort(size, values);
}

// Internal function to sort an array using mergesort
void int_mergesort(unsigned int size, int* values) {
    if (size <= 1) {
        return;
    }

    // Compute the size of the left and right arrays
    unsigned int left_length = size / 2;
    unsigned int right_length = size - left_length;

    int* left_side = (int*) malloc(left_length * sizeof(int));
    int* right_side = (int*) malloc(right_length * sizeof(int));

    // Split the array into two halves
    memcpy(left_side, values, left_length * sizeof(int));
    memcpy(right_side, values + left_length, right_length * sizeof(int));

    int_mergesort(left_length, left_side);
    int_mergesort(right_length, right_side);

    // Merge the sorted halves back into the original array
    merge_arrays(values, left_length, left_side, right_length, right_side);

    free(left_side);
    free(right_side);
}

// Merge two sorted arrays into a single sorted array
void merge_arrays(int* dest, unsigned int left_size, int* left, unsigned int right_size, int* right) {
    unsigned int left_index = 0;
    unsigned int right_index = 0;
    unsigned int dest_index = 0;

    while (left_index < left_size && right_index < right_size) {
        if (left[left_index] < right[right_index]) {
            dest[dest_index++] = left[left_index++];
        } else {
            dest[dest_index++] = right[right_index++];
        }
    }

    // Copy any remaining elements
    while (left_index < left_size) {
        dest[dest_index++] = left[left_index++];
    }

    while (right_index < right_size) {
        dest[dest_index++] = right[right_index++];
    }
}

