#include "array_merge.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#include "../mergesort/mergesort.h"

unsigned int uniqueCount(int* arrays, unsigned int length);

int* array_merge(int num_arrays, int* sizes, int** values) {
assert(num_arrays >= 0);

unsigned int total = 0;
for (unsigned int i = 0; i < (unsigned int) num_arrays; i++) {
    assert(sizes[i] >= 0);
    total += (unsigned int) sizes[i];
}

int* buffer = (int*) calloc(total + 1, sizeof(int));

if (total == 0) {
    buffer[0] = 0;
    return buffer;
}

unsigned int index = 1;
for (unsigned int i = 0; i < (unsigned int) num_arrays; i++)
    {
    memcpy(buffer + index, values[i], sizes[i] * sizeof(int));
    index += sizes[i];
    }

unsigned int unique_c = uniqueCount(buffer + 1, total);

assert(unique_c <= INT_MAX);

buffer[0] = (int) unique_c;

return buffer;
}

unsigned int uniqueCount(int* array, unsigned int length) {
    assert(length <= INT_MAX);
    mergesort((int)length, array);
    unsigned int dest_index = 0;
    unsigned int src_index = 0;

    while (src_index < length) {
        if (array[dest_index] == array[src_index]) {
        src_index++;
        }
        else {
            array[++dest_index] = array[src_index++];
        }
    }
    return dest_index + 1;
}
