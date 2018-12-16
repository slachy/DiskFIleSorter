#include "DiskFileSorter.hpp"

void merge(ulong numbers[], ulong l, ulong m, ulong r)
{
    ulong i, j, k;
    ulong n1 = m - l + 1;
    ulong n2 = r - m;

    ulong left[n1], right[n2];
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
}
void merge_sort(ulong numbers[], ulong l, ulong r)
{
    if (l < r)
    {
        ulong m = l + (r - l) / 2;

        merge_sort(numbers, l, m);
        merge_sort(numbers, m + 1, r);

        merge(numbers, l, m, r);
    }
}
