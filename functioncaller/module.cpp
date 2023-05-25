#ifndef _MODULE_H_
#define _MODULE_H_

struct Average {
	double arithmetic;
	double harmonic;
};

typedef bool(*doubleComparator_t)(double, double);

void sort(doubleComparator_t comparator, double* sequence, const int sequence_length);
bool compare_decimal_descending(double a, double b);

Average average_arithmetic_and_harmonic(const double* sequence, const int length);

#endif // !_MODULE_H_