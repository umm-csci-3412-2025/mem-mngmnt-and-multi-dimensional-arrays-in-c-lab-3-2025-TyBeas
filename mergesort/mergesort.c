#include "mergesort.h"

void mergeRanges(int values[], int start, int mid, int end) {
int size = end - start + 1;
int * temp = (int*) calloc(size, sizeof(int));
int first = start;
int second = mid + 1;
int index = 0;

while((first <= mid) && (second <= end)) {
    if(values[first] < values[second]) {
        temp[index] = values[first];
        first++;
    } else {
        temp[index] = values[second];
        second++;
    }
    index++;
}

while(first <= mid) {
    temp[index] = values[first];
    first++;
    index++;
}

while(second <= end) {
    temp[index] = values[second];
    second++;
    index++;
}

for(int i = 0; i < size; i++) {
    values[start + i] = temp[i];
}

free(temp);
}

void mergesortRange(int values[], int start, int end) {
    int size = end - start + 1;
    if(size > 2) {
        int mid = (start + end) / 2;
        mergesortRange(values, start, mid);
        mergesortRange(values, mid + 1, end);
        mergeRanges(values, start, mid, end);
    }
}

void mergesort(int size, int values[]) {
    mergesortRange(values, 0, size - 1);
}
