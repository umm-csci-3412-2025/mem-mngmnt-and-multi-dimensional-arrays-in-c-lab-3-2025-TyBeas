#include <gtest/gtest.h>
#include "mergesort.h"

void arrays_match(int size, int a[], int b[]) {
    for (int i = 0; i < size; ++i) {
        ASSERT_EQ(a[i], b[i]) << "Mismatch at index " << i;
    }
}

TEST(Mergesort, Mergesort_SortsEmptyArray) {
    int a[] = {};
    int b[] = {};
    mergesort(0, b);
    arrays_match(0, a, b);
}

TEST(Mergesort, Mergesort_SortsSingletonArray) {
    int a[] = { 5 };
    int b[] = { 5 };
    mergesort(1, b);
    arrays_match(1, a, b);
}

TEST(Mergesort, Mergesort_SortsOrderedPair) {
    int a[] = { 5, 8 };
    int expected[] = { 5, 8 };
    mergesort(2, a);
    arrays_match(2, a, expected);
}

TEST(Mergesort, Mergesort_SortsUnorderedPair) {
    int a[] = { 8, 5 };
    int expected[] = { 5, 8 };
    mergesort(2, a);
    arrays_match(2, a, expected);
}

TEST(Mergesort, Mergesort_SortsMixedArray) {
    int a[] = { 5, 8, 9, 6, 3, 2, 0 };
    int expected[] = { 0, 2, 3, 5, 6, 8, 9 };
    mergesort(7, a);
    arrays_match(7, a, expected);
}

TEST(Mergesort, Mergesort_SortsOrderedArray) {
    int a[] = { 0, 2, 3, 5, 6, 8, 9 };
    int expected[] = { 0, 2, 3, 5, 6, 8, 9 };
    mergesort(7, a);
    arrays_match(7, a, expected);
}

TEST(Mergesort, Mergesort_SortsReversedArray) {
    int a[] = { 9, 8, 6, 5, 3, 2, 0 };
    int expected[] = { 0, 2, 3, 5, 6, 8, 9 };
    mergesort(7, a);
    arrays_match(7, a, expected);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
