#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "GenerateNumbers.hpp"

int randint(int min, int max)
{
    return min + (rand() % static_cast<int>(max - min + 1));
}

void saveNumbers(std::string filename, int numbers[], int size)
{
    std::ofstream file;
    file.open(filename);
    for (int i = 0; i < size; ++i)
    {
        file << numbers[i] << std::endl;
    }
    file.close();
}

int* generateNumbers()
{
    int n = 10000000;
    int* arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        std::swap<int>(arr[i], arr[randint(0, n)]);
    }
    return arr;
}
