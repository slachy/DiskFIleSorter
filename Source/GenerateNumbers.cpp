#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "GenerateNumbers.hpp"

unsigned long int randint(int min, int max)
{
    return min + (rand() % static_cast<unsigned long int>(max - min + 1));
}

void generateNumbers()
{
    unsigned long int n = 10000000;
    unsigned long int* arr = new unsigned long int[n];

    for (unsigned long int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }
    std::ofstream file;
    file.open("numbers.txt");
    for (unsigned long int i = 0; i < n; ++i)
    {
        std::swap<unsigned long int>(arr[i], arr[randint(0, n)]);
        file << arr[i] << std::endl;
    }
    file.close();
    delete [] arr;
}
