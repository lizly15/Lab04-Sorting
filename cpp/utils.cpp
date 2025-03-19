#include "../include/utils.h"

void show_algo(SortBase* sort_algo, bool show_runtime, bool show_comparisons) {
    cout << endl << DASH_LINE << endl;
    if(show_runtime) {
        cout << "Running time: " << sort_algo->runtime << "ms" << endl;
    }
    if(show_comparisons) {
        cout << "Comparisons: " << sort_algo->comparisons << endl;
    }
}

void show_compare(SortBase* sort_algo_1, SortBase* sort_algo_2, bool show_runtime, bool show_comparisons) {
    cout << endl << DASH_LINE << endl;
    if(show_runtime) {
        cout << "Running time: " << sort_algo_1->runtime << "ms | " << sort_algo_2->runtime << "ms" << endl;
    }
    if(show_comparisons) {
        cout << "Comparisons: " << sort_algo_1->comparisons << " | " << sort_algo_2->runtime << endl;
    }
}

bool check_and_parse(
    int argc, char* argv[], 
    int index, string& output, 
    string option_name, const string option_value[][2], int num_options,
    bool required
) {
    if(argc <= index) {
        if(required) {
            cerr << "Please enter " << option_name << ":" << endl;
            for(int i = 0; i < num_options; ++i) {
                cerr << option_value[i][0] << " for " << option_value[i][1] << endl;
            }
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
        if(required) {
            cerr << "Invalid " << option_name << ":" << endl;
            for(int i = 0; i < num_options; ++i) {
                cerr << option_value[i][0] << " for " << option_value[i][1] << endl;
            }
        }
        return false;
    }

    output = string(argv[index]);
    return true;
}

bool parse_args(int argc, char* argv[], Params& params) {
    int cur_argc = 1;
    if(!check_and_parse(argc, argv, cur_argc, params.exe_type, "execution type", EXE_TYPES, 2)) return false;

    cur_argc++;
    if(!check_and_parse(argc, argv, cur_argc, params.algo1, "algorithm name", SORT_ALGOS, 10)) return false;

    if(params.exe_type == "-c") {
        cur_argc++;
        if(!check_and_parse(argc, argv, cur_argc, params.algo2, "algorithm name", SORT_ALGOS, 10)) return false;
    }

    cur_argc++;
    if(cur_argc >= argc) {
        cerr << "Please enter input type!";
        return false;
    }

    try {
        params.arr_n = stoi(argv[cur_argc]);
        if (params.arr_n <= 0) {
            throw out_of_range("");
        }

        cur_argc++;
        if(!check_and_parse(argc, argv, cur_argc, params.input_order, "input order", INPUT_ORDER, 4, false)) {
            params.input_order = "all";
            cur_argc--;
        }
    }
    catch (const invalid_argument& e) {
        params.input_order = "file";
        params.file_name = string(argv[cur_argc]);
    }
    catch (const out_of_range& e) {
        cerr << "Number is out of range [1, 1000000]" << endl;
        return false;
    }

    cur_argc++;
    if(!check_and_parse(argc, argv, cur_argc, params.output_param, "output param", OUTPUT_PARAM, 3)) return false;

    return true;
}