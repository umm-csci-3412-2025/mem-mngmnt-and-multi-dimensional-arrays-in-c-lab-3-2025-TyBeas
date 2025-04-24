#include "mergesort.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

void int_mergesort(unsigned int size, int* values);

void merge_arrays(int* dest, unsigned int left_size, int* left, unsigned int right_side, int* right);

void mergesort(int raw_size, int* values) {

    assert(raw_size >= 0);
    unsigned int size = (unsigned int) raw_size;

    int_mergesort(size, values);
}

void int_mergesort(unsigned int size, int* values) {
    if(size <= 1) {
        return;
    }

    unsigned int left_length = size / 2;
    unsigned int right_length = size - left_length;

    int* left_side = (int*) malloc(left_length * sizeof(int));
    int* right_side = (int*) malloc(right_length * sizeof(int));

    memcpy(left_side, values, left_length * sizeof(int));
    memcpy(right_side, values + left_length, right_length * sizeof(int));

    int_mergesort(left_length, left_side);
    int_mergesort(right_length, right_side);

    merge_arrays(values, left_length, left_side, right_length, right_side);

    free(left_side);
    free(right_side);
}

void merge_arrays(int* dest, unsigned int left_size, int* left, unsigned int right_size, int* right) {
    unsigned int left_index = 0;
    unsigned int right_index = 0;
    unsigned int dest_index = 0;

    while (1) {
        if (left_index >= left_size) {
            memcpy(dest + dest_index, right + right_index, (right_size - right_index) * sizeof(int));
            return;
        }
        if (right_index >= right_size) {
            memcpy(dest + dest_index, left + left_index, (left_size - left_index) * sizeof(int));
            return;
        }

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
