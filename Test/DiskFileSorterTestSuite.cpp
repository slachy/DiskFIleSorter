#include <gtest/gtest.h>
#include <iostream>
#include <chrono>

#include "DiskFileSorter.hpp"
#include "GenerateNumbers.hpp"

void assertArraysEq(ulong* first, ulong* second, ulong size)
{
    for (ulong i = 0; i < size; ++i)
    {
        ASSERT_EQ(first[i], second[i]);
    }
}

TEST(DiskFileSorterTestSuite, SimpleValues)
{
    const ulong numOfNumbers = 6;
    ulong numbers[numOfNumbers] = { 4, 8, 2, 5, 9, 3 };
    ulong expected[numOfNumbers] = { 2, 3, 4, 5, 8, 9 }; 
    merge_sort(numbers, 0, numOfNumbers - 1);

    assertArraysEq(numbers, expected, numOfNumbers);
}

TEST(DiskFileSorterTestSuite, DifferentValues)
{
    const ulong numOfNumbers = 6;
    ulong numbers[numOfNumbers] = { 4, 1, 2, 6, 9, 3 };
    ulong expected[numOfNumbers] = { 1, 2, 3, 4, 6, 9 };
    
    merge_sort(numbers, 0, numOfNumbers - 1);

    assertArraysEq(numbers, expected, numOfNumbers);
}

TEST(DiskFileSorterTestSuite, BigFileMergeSort)
{
    const ulong numOfNumbers = 10000000;
    ulong* numbers = new ulong[numOfNumbers];
    numbers = generateNumbers();
    saveNumbers("numbers.txt", numbers, numOfNumbers);

    using namespace std::chrono;
    high_resolution_clock::time_point start = high_resolution_clock::now();
    merge_sort(numbers, 0, numOfNumbers - 1);
    high_resolution_clock::time_point end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( end - start).count();
    std::cout << "Execution time: " << duration << std::endl;;

    saveNumbers("sorted_numbers.txt", numbers, numOfNumbers);
}
