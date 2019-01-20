#include <stdlib.h>

#include "DiskFileSorter.hpp"

void merge(int numbers[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* left = new int[n1];
    int* right = new int[n2];
    for (i = 0; i < n1; ++i)
    {
        left[i] = numbers[l + i];
    } 
    for (j = 0; j < n2; ++j)
    {
        right[j] = numbers[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
	{
	    numbers[k] = left[i];
	    ++i;
	}
	else
	{
	    numbers[k] = right[j];
	    ++j;
	}
	++k;
    }

    while (i < n1)
    {
        numbers[k] = left[i];
	++i;
	++k;
    }

    while (j < n2)
    {
        numbers[k] = right[j];
	++j;
	++k;
    }

    delete [] left;
    delete [] right;
}
void merge_sort(int numbers[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        merge_sort(numbers, l, m);
        merge_sort(numbers, m + 1, r);

        merge(numbers, l, m, r);
    }
}

// C sort
int intcomp(const void *x, const void *y)
{
	int l_x = *(int*)x;
	int l_y = *(int*)y;
	return l_x - l_y;
}

void c_sort(int numbers[], int numOfNumbers)
{
	qsort(&numbers, numOfNumbers, sizeof(int), intcomp);
}
