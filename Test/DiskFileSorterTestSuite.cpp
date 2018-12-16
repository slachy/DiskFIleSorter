#include <gtest/gtest.h>
#include "DiskFileSorter.hpp"
#include "GenerateNumbers.hpp"

void assertArraysEq(int* first, int* second, int size)
{
    for (int i = 0; i < size; ++i)
    {
        ASSERT_EQ(first[i], second[i]);
    }
}

TEST(DiskFileSorterTestSuite, SimpleValues)
{
    const int numOfNumbers = 6;
    int numbers[numOfNumbers] = { 4, 8, 2, 5, 9, 3 };
    int expected[numOfNumbers] = { 2, 3, 4, 5, 8, 9 };
    
    merge_sort(numbers, 0, numOfNumbers - 1);

    assertArraysEq(numbers, expected, numOfNumbers);
}

TEST(DiskFileSorterTestSuite, DifferentValues)
{
    const int numOfNumbers = 6;
    int numbers[numOfNumbers] = { 4, 1, 2, 6, 9, 3 };
    int expected[numOfNumbers] = { 1, 2, 3, 4, 6, 9 };
    
    merge_sort(numbers, 0, numOfNumbers - 1);

    assertArraysEq(numbers, expected, numOfNumbers);
}

TEST(DiskFileSorterTestSuite, GenerateNumbers)
{
    generateNumbers();
}
