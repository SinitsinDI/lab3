#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>
using namespace std;
Input
read_input(istream& in, bool prompt)
{
    Input data;
    if (prompt)
        cerr << "Enter number count: ";
    size_t number_count;
    cin >> number_count;
    if (prompt)
        cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);
    if (prompt)
        cerr << "Enter column count: ";
    size_t bin_count;
    cin>>bin_count;
    data.bin_count = bin_count;

    return data;
}
int
main() {
    curl_global_init(CURL_GLOBAL_ALL);
    const auto input = read_input(cin, true);
    const auto bins = make_histogram(input);
    show_histogram_svg(bins);
}
