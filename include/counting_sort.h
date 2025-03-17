#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include "sort_base.h"

class CountingSort : public SortBase {
public:
    void sort(int arr[], int n) override;
};

#endif // COUNTING_SORT_H