#ifndef MODULE1_H
#define MODULE1_H
#include <cmath>
#include <vector>
#include <string>
struct Results
{
    double maximum;
    double minimum;
    int maximumIndex;
    int minimumIndex;
};

bool ascending(double  a, double  b);
void sort(double* sequence, bool (*comparisonFunc)(double, double), int lenght);

Results calculate_results(const double* sequence, const int length);

#endif  // MODULE1_H

