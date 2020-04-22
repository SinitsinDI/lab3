#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>
using namespace std;
void find_minmax(const vector<double> numbers, double& min, double& max);
double bin_opacity17(double bin, size_t max_count);
vector<double> input_numbers(size_t count);
vector <size_t> make_histogram(vector <double> numbers,size_t bin_count,double min,double max);
void show_histogram_text(vector<size_t>bins);
#endif // HISTOGRAM_H_INCLUDED
