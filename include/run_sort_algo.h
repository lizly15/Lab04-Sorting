#ifndef RUN_SORT_ALGO_H
#define RUN_SORT_ALGO_H

#include "sort_base.h"
#include "utils.h"

void get_sort_algo(SortBase*& sort_algo, const string& algo);

void get_input_order(const string& input_order, int& low, int& high);

void get_data(int*& arr, int& arr_n, int order, const string& file_name);

void algorithm_mode(Params& params);

void comparison_mode(Params& params);

void choose_mode(Params& params);

#endif // RUN_SORT_ALGO_H