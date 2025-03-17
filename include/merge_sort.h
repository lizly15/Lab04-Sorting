#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "sort_base.h"

class MergeSort : public SortBase {
private:
    void merge(int arr[], int l, int m, int r);
    void merge_sort(int arr[], int l, int r);
public:
    void sort(int arr[], int n) override;
};

#endif // MERGE_SORT_H