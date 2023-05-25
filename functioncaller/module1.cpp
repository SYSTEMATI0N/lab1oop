#include "Module1.h"
#include <cmath>
#include <algorithm>

void sort(doubleComparator_t compare, double* sequence, const int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            double& a = sequence[j];
            double& b = sequence[j + 1];
            if (compare(a, b))
                std::swap(a, b);
        }
    }
}

bool compare_decimal_ascending(double a, double b)
{
    double tmp;
    double decimal_a = std::abs(std::modf(a, &tmp));
    double decimal_b = std::abs(std::modf(b, &tmp));
    return decimal_a < decimal_b;
}

Results calculate_results(const double* sequence, const int length)
{
    double maximum = sequence[0];
    double minimum = sequence[0];
    int maximumIndex = 0;
    int minimumIndex = 0;

    for (int i = 1; i < length; i++)
    {
        if (sequence[i] > maximum)
        {
            maximum = sequence[i];
            maximumIndex = i;
        }
        if (sequence[i] < minimum)
        {
            minimum = sequence[i];
            minimumIndex = i;
        }
    }

    Results results;
    results.maximum = maximum;
    results.minimum = minimum;
    results.maximumIndex = maximumIndex;
    results.minimumIndex = minimumIndex;

    return results;
}