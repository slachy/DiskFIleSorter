#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "GenerateNumbers.hpp"

ulong randint(int min, int max)
{
    return min + (rand() % static_cast<ulong>(max - min + 1));
}

void saveNumbers(std::string filename, ulong numbers[], ulong size)
{
    std::ofstream file;
    file.open(filename);
    for (ulong i = 0; i < size; ++i)
    {
        file << numbers[i] << std::endl;
    }
    file.close();
}

ulong* generateNumbers()
{
    ulong n = 10000000;
    ulong* arr = new ulong[n];

    for (ulong i = 0; i < n; ++i)
    {
        arr[i] = i;
    }
    for (ulong i = 0; i < n; ++i)
    {
        std::swap<ulong>(arr[i], arr[randint(0, n)]);
    }
    return arr;
}
