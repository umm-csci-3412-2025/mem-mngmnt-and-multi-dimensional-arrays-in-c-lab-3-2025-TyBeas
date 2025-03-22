#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>

int totalSize(int num_arrays, int* sizes) {
int total = 0;
for (int i = 0; i < num_arrays; i++) {
    total = (total + sizes[i]);
}
return total;

}

int* array_merge(int num_arrays, int* sizes, int** values) {
int size = totalSize(num_arrays, sizes);

if (num_arrays == 0) {
    int* emptyArray = (int*) calloc(1, sizeof(int));
    emptyArray[0] = 0;
    return emptyArray;
}

int currentArraySize = 0;
int currentArrayIndex = 0;
int* temp = (int*) calloc(size, sizeof(int));

for (int i = 0; i < num_arrays; i++) {
    currentArraySize = sizes[i];
    for (int j = 0; j < sizes[i]; j++) {
        temp[currentArrayIndex] = values[i][j];
        currentArrayIndex++;
    }
}

mergesort(currentArrayIndex, temp);

int unique = 1;
int current = temp[0];
for (int f = 1; f < size; f++) {
    if (current != temp[f]) {
        current = temp[f];
        unique++;
    }
}

int* distinct = (int*) calloc(unique + 1, sizeof(int));
distinct[0] = unique;
distinct[1] = temp[0];
current = temp[0];
int distinctIndex = 2;

for (int k = 1; k < size; k++) {
    if (current != temp[k]) {
        current = temp[k];
        distinct[distinctIndex] = temp[k];
        distinctIndex++;
    }
}

free(temp);
return distinct;
}
