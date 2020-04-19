#include <iostream>
#include <vector>
#include "histogram.h"

using namespace std;

vector<double> input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}

vector <size_t> make_histogram(vector <double> numbers,size_t bin_count,double min,double max)
{
    vector<size_t> bins(bin_count);
    for (double number : numbers)
    {
        size_t bin = (size_t)((number - min) / (max - min) * bin_count);
        if (bin == bin_count)
        {
            bin--;
        }
        bins[bin]++;
    }
    return(bins);
}

void show_histogram_text(vector<size_t>bins)
{
    const size_t screen_width=80;
    const size_t width=screen_width-4;

    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > width;

    for (size_t bin : bins)
    {
        if (bin < 100)
        {
            cout << ' ';
        }
        if (bin < 10)
        {
            cout << ' ';
        }
        cout << bin << "|";

        size_t height = bin;
        if (scaling_needed)
        {
            const double scaling_multiplier = (double)width / max_count;
            height = (size_t)(bin * scaling_multiplier);
        }

        for (size_t i = 0; i < height; i++)
        {
            cout << '*';
        }
        cout<<' ';
        cout << endl;
    }
}


int main()
{

    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers=input_numbers(number_count);

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;

    double min,max;
    find_minmax(numbers,min,max);

    const auto bins = make_histogram(numbers, bin_count,min,max);
    show_histogram_svg(bins);
    return 0;
}
