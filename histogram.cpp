#include "histogram.h"
#include "svg.h"
#include <iostream>
void find_minmax(vector<double> numbers, double& min, double& max)
{
    min = numbers[0];
    max = numbers[0];
    for (double number : numbers)
    {
        if (number < min)
        {
            min = number;
        }
        if (number > max)
        {
            max = number;
        }
    }
}

double bin_opacity17(double bin, size_t max_count)
{
    return bin/max_count;
}

