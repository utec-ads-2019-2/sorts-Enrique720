#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(int *elements, size_t size) : Sort(elements, size) {}
        void merge(int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 =  right - mid;
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
            L[i] = elements[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = elements[mid + 1+ j];
        int i = 0;
        int j = 0;
        int k = left;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                elements[k] = L[i];
                i++;
            }
            else
            {
                elements[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            elements[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)

        {
            elements[k] = R[j];
            j++;
            k++;
        }
    }
        void mergeSort( int right, int left)
    {
        if (left < right)
        {
            int mid = left+(right-left)/2;
            mergeSort( mid, left);
            mergeSort(right, mid+1);
            merge(left, mid, right);
        }
    }
        void execute() {
        mergeSort(size-1,0);
    }
    inline string name() { return "MergeSort"; }
};

#endif
