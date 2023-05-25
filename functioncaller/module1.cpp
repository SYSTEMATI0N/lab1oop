#include "module1.h"

int getDigitSum(double num) {
    std::string numStr = std::to_string(num);
    
    int i = 0;
    int sum = 0;
    bool dot = false;
    while (numStr[i] != '\0') {
        if (numStr[i] == '.')
            dot = true;
        else if (dot) {
            sum += numStr[i] - '0';
        }
        ++i;
    }
    return sum;
}

bool ascending(double  a, double  b) {
    double tmp;
    double decimal_a = std::abs(std::modf(a, &tmp));
    double decimal_b = std::abs(std::modf(b, &tmp));
  
    return getDigitSum(a) > getDigitSum(b);
}
void sort(double* sequence, bool (*comparisonFunc)(double, double), int lenght)
{
    for (int i = 0; i < lenght - 1; ++i) {
        for (int j = 0; j < lenght - i - 1; ++j) {
            if (comparisonFunc(sequence[j], sequence[j + 1])) {
                std::swap(sequence[j], sequence[j + 1]);
            }
        }
    }
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