#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}
        int divison(int low, int high)
         {
        int pivote = elements[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++)
        {
            if (elements[j] < pivote)
            {
                i++;
                swap(elements[i], elements[j]);
            }
        }
        swap(elements[i + 1], elements[high]);
        return (i + 1);
    }
    void quickSort(int low, int high)
    {
        if (low < high)
        {

            int p_index = divison(low, high);
            quickSort(low, p_index - 1);
            quickSort( p_index + 1, high);
        }
    }
    void execute() {
        quickSort(0, size - 1);
    }
    inline string name() { return "QuickSort"; }
};

#endif
