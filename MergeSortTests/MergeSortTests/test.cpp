#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "../../src/MergeSort.hpp"
#include "../../src/MergeSort.cpp" 

// 1. Zachowuje tablicę niezmienioną, gdy ona jest już posortowana rosnąco
TEST(MergeSortTest, AlreadySorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 2. Potrafi posortować tablicę, która jest posortowana w odwrotnej kolejności
TEST(MergeSortTest, ReverseSorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 3. Poprawnie sortuje losową tablicę liczb
TEST(MergeSortTest, RandomArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 38, 27, 43, 3, 9, 82, 10 };
    std::vector<int> expected = { 3, 9, 10, 27, 38, 43, 82 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 4. Poprawnie sortuje tablice tylko z liczbami ujemnymi
TEST(MergeSortTest, OnlyNegativeNumbers) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -5, -12, -3, -1, -42 };
    std::vector<int> expected = { -42, -12, -5, -3, -1 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 5. Poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi
TEST(MergeSortTest, NegativeAndPositiveNumbers) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -5, 10, -2, 0, 7, -1 };
    std::vector<int> expected = { -5, -2, -1, 0, 7, 10 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 6. Obsługuje pustą tablicę bez rzucania wyjątkiem
TEST(MergeSortTest, EmptyArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = {};

    EXPECT_NO_THROW(sorter.sort(arr));
    EXPECT_TRUE(arr.empty());
}

// 7. Nie zmienia tablicy, która zawiera tylko jeden element
TEST(MergeSortTest, SingleElementArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 8. Poprawnie sortuje tablicę z duplikatami liczb
TEST(MergeSortTest, ArrayWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 4, 1, 3, 4, 2, 1, 3 };
    std::vector<int> expected = { 1, 1, 2, 3, 3, 4, 4 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 9. Poprawnie sortuje tablice ujemną z duplikatami
TEST(MergeSortTest, NegativeArrayWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -3, -1, -3, -5, -1, -5 };
    std::vector<int> expected = { -5, -5, -3, -3, -1, -1 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 10. Poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortTest, MixedArrayWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -2, 5, 0, -2, 5, 3, 0, -5 };
    std::vector<int> expected = { -5, -2, -2, 0, 0, 3, 5, 5 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 11. Poprawnie sortuje tablicę zawierającą tylko dwa elementy w kolejności rosnącej
TEST(MergeSortTest, TwoElementsAscending) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 10, 20 };
    std::vector<int> expected = { 10, 20 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 12. Poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów
TEST(MergeSortTest, LargeArrayOver100Elements) {
    MergeSort<int> sorter;
    std::vector<int> arr;
    for (int i = 150; i >= 1; --i) {
        arr.push_back(i);
    }

    // Wzorzec posortowany
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 13. Poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortTest, LargeMixedArrayWithDuplicatesOver100Elements) {
    MergeSort<int> sorter;
    std::vector<int> arr;

    // Generowanie ponad 100 elementów z ujemnymi, dodatnimi i duplikatami
    for (int i = -60; i <= 60; ++i) {
        arr.push_back(i % 7); // generuje dużo duplikatów
        arr.push_back(i);     // ujemne i dodatnie
    }

    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 14. Poprawnie sortuje wektor liczb zmiennoprzecinkowych (double)
TEST(MergeSortTest, DoublePrecisionNumbers) {
    MergeSort<double> sorter;
    std::vector<double> arr = { 3.14, -0.5, 2.71, -0.5, 0.0, 1.41 };
    std::vector<double> expected = { -0.5, -0.5, 0.0, 1.41, 2.71, 3.14 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 15. Poprawnie sortuje tablicę rosnącą do szczytu, a potem malejącą ("górka")
TEST(MergeSortTest, MountainShapedArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 1, 3, 7, 15, 25, 19, 12, 6, 2 };
    std::vector<int> expected = { 1, 2, 3, 6, 7, 12, 15, 19, 25 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 16. Radzi sobie z tablicą "prawie posortowaną" (tylko kilka elementów zamienionych miejscami)
TEST(MergeSortTest, NearlySortedArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 1, 2, 4, 3, 5, 6, 8, 7, 9, 10 };
    std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 17. Sprawdza sortowanie tablicy o nieparzystej liczbie elementów z asymetrycznym podziałem
TEST(MergeSortTest, OddNumberOfElements) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 99, 12, 45, 7, 23 };
    std::vector<int> expected = { 7, 12, 23, 45, 99 };

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}

// 18. Obsługuje wektor składający się z samych wartości -1
TEST(MergeSortTest, AllMinusOnes) {
    MergeSort<int> sorter;
    std::vector<int> arr(15, -1);
    std::vector<int> expected(15, -1);

    sorter.sort(arr);

    EXPECT_EQ(arr, expected);
}