#include "./include/run_sort_algo.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    Params params;
    if(!parse_args(argc, argv, params)) return 1;

    choose_mode(params);

    return 0;
}