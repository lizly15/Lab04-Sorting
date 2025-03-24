#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "../include/sort_base.h"
using namespace std;

const string DASH_LINE = "--------------------------------";
const string EXE_TYPES[2][2] = {
    {"-a", "Algorithm mode"},
    {"-c", "Comparison mode"}
};
const string SORT_ALGOS[10][2] = {
    {"bubble-sort", "Bubble Sort"},
    {"counting-sort", "Counting Sort"},
    {"heap-sort", "Heap Sort"},
    {"insertion-sort", "Insertion Sort"},
    {"merge-sort", "Merge Sort"},
    {"quick-sort", "Quick Sort"},
    {"radix-sort", "Radix Sort"},
    {"selection-sort", "Selection Sort"},
    {"shaker-sort", "Shaker Sort"},
    {"shell-sort", "Shell Sort"}
};
const string INPUT_ORDER[4][2] = {
    {"-rand", "Randomized"},
    {"-sorted", "Sorted"},
    {"-rev", "Reverse sorted"},
    {"-nsorted", "Nearly sorted"}
};
const string FILE_NAME_ORDER[4][2] = {
    {"-rand", "input_1.txt"},
    {"-sorted", "input_3.txt"},
    {"-rev", "input_4.txt"},
    {"-nsorted", "input_2.txt"}
};
const string OUTPUT_PARAM[3][2] = {
    {"-time", "Running time"},
    {"-comp", "Number of comparisions"},
    {"-both", "Both above options"}
};

struct Params {
    string exe_type = "";
    string algo1 = "";
    string algo2 = "";
    int arr_n = 0;
    string input_order = "";
    string file_name = "";
    string output_param = "";
};

void show_algo(SortBase* sort_algo, bool show_runtime = true, bool show_comparisons = true);

void show_compare(SortBase* sort_algo_1, SortBase* sort_algo_2, bool show_runtime = true, bool show_comparisons = true);

bool check_and_parse(
    int argc, char* argv[], 
    int index, string& output, 
    string option_name, const string option_value[][2], int num_options,
    bool required = true
);

bool parse_args(int argc, char* argv[], Params& params);

#endif // UTILS_H