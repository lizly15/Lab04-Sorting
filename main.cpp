#include "./include/bubble_sort.h"
#include "./include/counting_sort.h"
#include "./include/heap_sort.h"
#include "./include/insertion_sort.h"
#include "./include/merge_sort.h"
#include "./include/quick_sort.h"
#include "./include/radix_sort.h"
#include "./include/selection_sort.h"
#include "./include/shaker_sort.h"
#include "./include/shell_sort.h"
#include "./include/sort_base.h"
#include <iostream>
#include <string>

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
    {"-rand", "Randomized data"},
    {"-nsorted", "Nearly sorted data"},
    {"-sorted", "Sorted data"},
    {"-rev", " Reverse sorted data"}
};
const string OUTPUT_PARAM[3][2] = {
    {"-time", "Running time"},
    {"-comp", "Number of comparisions"},
    {"-both", "Both above options"}
};

void show_algo(SortBase* sort_algo, bool show_runtime = true, bool show_comparisons = true) {
    cout << endl << DASH_LINE << endl;
    if(show_runtime) {
        cout << "Running time: " << sort_algo->runtime << "ms" << endl;
    }
    if(show_comparisons) {
        cout << "Comparisons: " << sort_algo->comparisons << endl;
    }
}

void show_compare(SortBase* sort_algo_1, SortBase* sort_algo_2, bool show_runtime = true, bool show_comparisons = true) {
    cout << endl << DASH_LINE << endl;
    if(show_runtime) {
        cout << "Running time: " << sort_algo_1->runtime << "ms | " << sort_algo_2->runtime << "ms" << endl;
    }
    if(show_comparisons) {
        cout << "Comparisons: " << sort_algo_1->comparisons << " | " << sort_algo_2->runtime << endl;
    }
}

bool check_and_parse(int argc, char* argv[], int index, string& output, string option_name, const string option_value[][2], int num_options) {
    if(argc <= index) {
        cerr << "Please enter " << option_name << ":" << endl;
        for(int i = 0; i < num_options; ++i) {
            cerr << option_value[i][0] << " for " << option_value[i][1] << endl;
        }
        return false;
    }

    bool is_invalid = true;
    for(int i = 0; i < num_options; ++i) {
        if(string(argv[index]) == option_value[i][0]) {
            is_invalid = false;
            break;
        }
    }
    if(is_invalid) {
        cerr << "Invalid " << option_name << ":" << endl;
        for(int i = 0; i < num_options; ++i) {
            cerr << option_value[i][0] << " for " << option_value[i][1] << endl;
        }
        return false;
    }

    output = string(argv[index]);
    return true;
}

bool parse_args(int argc, char* argv[], string& exe_type, string& algo1, string& algo2) {
    if(!check_and_parse(argc, argv, 1, exe_type, "execution type", EXE_TYPES, 2)) return false;

    if(!check_and_parse(argc, argv, 2, algo1, "algorithm name", SORT_ALGOS, 10)) return false;

    if(exe_type == "-c") {
        if(!check_and_parse(argc, argv, 3, algo2, "algorithm name", SORT_ALGOS, 10)) return false;
    }

    return true;
}

int main(int argc, char* argv[])
{
    string exe_type = "";
    string algo1 = "";
    string algo2 = "";
    if(!parse_args(argc, argv, exe_type, algo1, algo2)) return 1;

    return 0;
}