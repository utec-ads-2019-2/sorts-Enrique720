#ifndef RADIX_H
#define RADIX_H

#include "sort.h"

class RadixSort : public Sort {       
    public:
        RadixSort(int *elements, size_t size) : Sort(elements, size) {}
        int maximo(int n)
    {
        int max = elements[0];
        for (int i = 1; i < n; i++)
            if (elements[i] > max)
                max = elements[i];
            return max;
    }
    void countSort(int exp)
    {
        int salida[size];
        int count[10] = {0};
        for (int i = 0; i < size; i++)
            count[ (elements[i]/exp)%10 ]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = size - 1; i >= 0; i--)
        {
            salida[count[ (elements[i]/exp)%10 ] - 1] = elements[i];
            count[ (elements[i]/exp)%10 ]--;
        }
        for (int i = 0; i < size; i++)
            elements[i] = salida[i];
    }
    void execute() {
        int max = maximo(size);
        for (int exp = 1; max/exp > 0; exp *= 10)
            countSort(exp);
    }

        inline string name() { return "RadixSort"; }
};

#endif
