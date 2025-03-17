#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "sort_base.h"

class ShellSort : public SortBase {
public:
    void sort(int arr[], int n) override;
};

#endif // SHELL_SORT_H