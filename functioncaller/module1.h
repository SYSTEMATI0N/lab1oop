#ifndef MODULE1_H
#define MODULE1_H

typedef bool (*doubleComparator_t)(double, double);

struct Results
{
    double maximum;
    double minimum;
    int maximumIndex;
    int minimumIndex;
};

void sort(doubleComparator_t compare, double* sequence, const int length);
bool compare_decimal_ascending(double a, double b);
Results calculate_results(const double* sequence, const int length);

#endif  // MODULE1_H

