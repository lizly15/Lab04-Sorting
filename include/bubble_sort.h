#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "sort_base.h"

class BubbleSort : public SortBase {
public:
    void sort(int arr[], int n) override;
};

#endif // BUBBLE_SORT_H