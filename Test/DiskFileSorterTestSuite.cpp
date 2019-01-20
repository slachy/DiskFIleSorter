#include <gtest/gtest.h>
#include <iostream>
#include <chrono>

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

/*TEST(DiskFileSorterTestSuite, BigFileMergeSort)
{
    const int numOfNumbers = 10000000;
    int* numbers = new int[numOfNumbers];
    numbers = generateNumbers();
    saveNumbers("numbers.txt", numbers, numOfNumbers);

    using namespace std::chrono;
    high_resolution_clock::time_point start = high_resolution_clock::now();
    merge_sort(numbers, 0, numOfNumbers - 1);
    high_resolution_clock::time_point end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( end - start).count();
    std::cout << "Execution time: " << duration << std::endl;;

    saveNumbers("merge_sort_sorted.txt", numbers, numOfNumbers);
}
*/
TEST(DiskFileSorterTestSuite, BigFileC_Sort)
{
    const int numOfNumbers = 10000000;
    int* numbers = new int[numOfNumbers];
    numbers = generateNumbers();
    saveNumbers("numbers.txt", numbers, numOfNumbers);

    using namespace std::chrono;
    high_resolution_clock::time_point start = high_resolution_clock::now();
    c_sort(numbers, numOfNumbers);
    high_resolution_clock::time_point end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( end - start).count();
    std::cout << "Execution time: " << duration << std::endl;;

    saveNumbers("c_sort_sorted.txt", numbers, numOfNumbers);
}
