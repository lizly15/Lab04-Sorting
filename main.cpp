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
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    Params params;
    if(!parse_args(argc, argv, params)) return 1;

    return 0;
}