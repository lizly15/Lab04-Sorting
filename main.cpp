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
#include "./include/utils.h"
#include "./include/data_generator.h"
#include <iostream>
#include <string>

void choose_sort_algo(SortBase*& sort_algo, const string& algo) {
    if(algo == "bubble-sort") {
        sort_algo = new BubbleSort();
        return;
    }
    if(algo == "counting-sort") {
        sort_algo = new CountingSort();
        return;
    }
    if(algo == "heap-sort") {
        sort_algo = new HeapSort();
        return;
    }
    if(algo == "insertion-sort") {
        sort_algo = new InsertionSort();
        return;
    }
    if(algo == "merge-sort") {
        sort_algo = new MergeSort();
        return;
    }
    if(algo == "quick-sort") {
        sort_algo = new QuickSort();
        return;
    }
    if(algo == "radix-sort") {
        sort_algo = new RadixSort();
        return;
    }
    if(algo == "selection-sort") {
        sort_algo = new SelectionSort();
        return;
    }
    if(algo == "shaker-sort") {
        sort_algo = new ShakerSort();
        return;
    }
    if(algo == "shell-sort") {
        sort_algo = new ShellSort();
        return;
    }
}

void get_data(int*& a, int arr_n, string input_order, const string& file_name) {
    if(input_order == "file") {
        
    }
    else {
        int order = 0;
        if(input_order == "-rand") {
            order = 0;
        }
        else if(input_order == "-sorted") {
            order = 1;
        }
        else if(input_order == "-rev") {
            order = 2;
        }
        else if(input_order == "-nsorted") {
            order = 3;
        }
        GenerateData(a, arr_n, order);
    }
}

int main(int argc, char* argv[])
{
    Params params;
    if(!parse_args(argc, argv, params)) return 1;

    return 0;
}