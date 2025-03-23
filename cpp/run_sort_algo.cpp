#include "../include/run_sort_algo.h"
#include "../include/bubble_sort.h"
#include "../include/counting_sort.h"
#include "../include/heap_sort.h"
#include "../include/insertion_sort.h"
#include "../include/merge_sort.h"
#include "../include/quick_sort.h"
#include "../include/radix_sort.h"
#include "../include/selection_sort.h"
#include "../include/shaker_sort.h"
#include "../include/shell_sort.h"
#include "../include/sort_base.h"
#include "../include/utils.h"
#include "../include/data_generator.h"

void get_sort_algo(SortBase*& sort_algo, const string& algo) {
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

void get_input_order(const string& input_order, int& low, int& high) {
    if(input_order == "-file") {
        low = 4, high = 4;
    }
    else if(input_order == "-all") {
        low = 0; high = 3;
    }
    else {
        for(int i = 0; i <= 3; ++i) {
            if(input_order == INPUT_ORDER[i][0]) {
                low = i, high = i;
                return;
            }
        }
    }
}

void get_data(int*& arr, int& arr_n, int order, const string& file_name) {
    if(order == 4) {
        ifstream inp(file_name);

        if(inp.is_open()) {
            inp >> arr_n;
            arr = new int[arr_n];
            for(int i = 0; i < arr_n; ++i) {
                inp >> arr[i];
            }
        }

        inp.close();
        cout << "Input file: " << file_name << endl;
        cout << "Input size: " << arr_n << endl;
    }
    else {
        cout << "Input order: " << INPUT_ORDER[order][1] << endl;
        arr = new int[arr_n];
        GenerateData(arr, arr_n, order);
    }
}

void copy_arr(int* arr, int*& des_arr, int arr_n) {
    des_arr = new int[arr_n];
    for(int i = 0; i < arr_n; ++i) {
        des_arr[i] = arr[i];
    }
}

string get_value(const string& key, const string option_value[][2], int num_options) {
    for(int i = 0; i < num_options; ++i) {
        if(option_value[i][0] == key) {
            return option_value[i][1];
        }
    }
    return "";
}

void print_data(const int* arr, int arr_n, string file_name) {
    ofstream out(file_name);

    out << arr_n << endl;
    for(int i = 0; i < arr_n; ++i) {
        out << arr[i] << ' ';
    }

    out.close();
}

void algorithm_mode(Params& params) {
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << get_value(params.algo1, SORT_ALGOS, 10) << endl;
    if(params.input_order != "-file") {
        cout << "Input size: " << params.arr_n << endl;
        if(params.input_order == "-all") cout << endl;
    }

    SortBase* sort_algo = nullptr;
    int* arr = nullptr;
    int order_low = 0, order_high = 0;

    get_sort_algo(sort_algo, params.algo1);
    get_input_order(params.input_order, order_low, order_high);

    for(int order = order_low; order <= order_high; ++order) {
        sort_algo->reset_compare();
        get_data(arr, params.arr_n, order, params.file_name);

        if(params.input_order != "-file") {
            if(params.input_order != "-all") {
                print_data(arr, params.arr_n, "input.txt");
            }
            else {
                print_data(arr, params.arr_n, FILE_NAME_ORDER[order][1]);
            }
        }

        int* tem_arr = nullptr;
        copy_arr(arr, tem_arr, params.arr_n);
        sort_algo->sort(tem_arr, params.arr_n);

        show_algo(sort_algo, (params.output_param != "-comp"), (params.output_param != "-time"));
        if(params.input_order != "-all") {
            print_data(tem_arr, params.arr_n, "output.txt");
        }

        if(tem_arr != nullptr) {
            delete [] tem_arr;
            tem_arr = nullptr;
        }

        if(arr != nullptr) {
            delete [] arr;
            arr = nullptr;
        }
    }

    if(sort_algo != nullptr) {
        delete sort_algo;
    }
}

void comparison_mode(Params& params) {
    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << get_value(params.algo1, SORT_ALGOS, 10) << " | " << get_value(params.algo2, SORT_ALGOS, 10) << endl;
    if(params.input_order != "-file") {
        cout << "Input size: " << params.arr_n << endl;
        if(params.input_order == "-all") cout << endl;
    }

    SortBase* sort_algo_1 = nullptr;
    SortBase* sort_algo_2 = nullptr;
    int* arr = nullptr;
    int order_low = 0, order_high = 0;

    get_sort_algo(sort_algo_1, params.algo1);
    get_sort_algo(sort_algo_2, params.algo2);
    get_input_order(params.input_order, order_low, order_high);

    for(int order = order_low; order <= order_high; ++order) {
        sort_algo_1->reset_compare();
        sort_algo_2->reset_compare();
        get_data(arr, params.arr_n, order, params.file_name);

        if(params.input_order != "-file") {
            if(params.input_order != "-all") {
                print_data(arr, params.arr_n, "input.txt");
            }
            else {
                print_data(arr, params.arr_n, FILE_NAME_ORDER[order][1]);
            }
        }

        int* tem_arr_1 = nullptr;
        copy_arr(arr, tem_arr_1, params.arr_n);
        sort_algo_1->sort(tem_arr_1, params.arr_n);

        int* tem_arr_2 = nullptr;
        copy_arr(arr, tem_arr_2, params.arr_n);
        sort_algo_2->sort(tem_arr_2, params.arr_n);

        show_compare(sort_algo_1, sort_algo_2, (params.output_param != "-comp"), (params.output_param != "-time"));

        if(tem_arr_1 != nullptr) {
            delete [] tem_arr_1;
            tem_arr_1 = nullptr;
        }
        
        if(tem_arr_2 != nullptr) {
            delete [] tem_arr_2;
            tem_arr_2 = nullptr;
        }

        if(arr != nullptr) {
            delete [] arr;
            arr = nullptr;
        }
    }

    if(sort_algo_1 != nullptr) {
        delete sort_algo_1;
    }
    if(sort_algo_2 != nullptr) {
        delete sort_algo_2;
    }
}

void choose_mode(Params& params) {
    if(params.exe_type == "-a") {
        algorithm_mode(params);
    }
    else {
        comparison_mode(params);
    }
}