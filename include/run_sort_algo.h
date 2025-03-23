#ifndef RUN_SORT_ALGO_H
#define RUN_SORT_ALGO_H

#include "sort_base.h"
#include "utils.h"

void get_sort_algo(SortBase*& sort_algo, const string& algo);

void get_input_order(const string& input_order, int& low, int& high);

void get_data(int*& arr, int& arr_n, int order, const string& file_name);

void copy_arr(int* arr, int*& des_arr, int arr_n);

string get_value(const string& key, const string option_value[][2], int num_options);

void print_data(const int* arr, int arr_n, string file_name);

void algorithm_mode(Params& params);

void comparison_mode(Params& params);

void choose_mode(Params& params);

#endif // RUN_SORT_ALGO_H