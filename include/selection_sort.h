#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "sort_base.h"

class SelectionSort : public SortBase {
public:
    void sort(int arr[], int n) override;
};

#endif // SELECTION_SORT_H
