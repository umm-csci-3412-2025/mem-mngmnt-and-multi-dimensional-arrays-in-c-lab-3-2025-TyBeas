#include "mergesort.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

// internal function to sort an array using mergesort
void int_mergesort(unsigned int size, int* values);

void merge_arrays(int* dest, unsigned int left_size, int* left, unsigned int right_side, int* right);

// Sort arrays with size and values
void mergesort(int raw_size, int* values) {

    assert(raw_size >= 0);
    unsigned int size = (unsigned int) raw_size;

    int_mergesort(size, values);
}

// Internal function to sort an array using mergesort
void int_mergesort(unsigned int size, int* values) {
    if(size <= 1) {
        return;
    }

    // Compute the size of the left and right arrays
    unsigned int left_length = size / 2;
    unsigned int right_length = size - left_length;

    int* left_side = (int*) calloc(left_length, sizeof(int));
    int* right_side = (int*) calloc(right_length, sizeof(int));

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

    while (1) {
        // Check if we have reached the end of either array
        if (left_index >= left_size) {
            memcpy(dest + dest_index, right + right_index, (right_size - right_index) * sizeof(int));
            return;
        }
        else if (right_index >= right_size) {
            memcpy(dest + dest_index, left + left_index, (left_size - left_index) * sizeof(int));
            return;
        }

        // Compare the current elements of both arrays
        int left_value = left[left_index];
        int right_value = right[right_index];

        if (left_value < right_value) {
            dest[dest_index++] = left_value;
            left_index++;
        } else {
            dest[dest_index++] = right_value;
            right_index++;
        }
    }
}
