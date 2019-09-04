#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            for (int lim = size / 2; lim > 0; lim /= 2) {
                for (int i = lim; i < size; i += 1) {
                    int temp = elements[i];
                    int j;
                    for (j = i; j >= lim && elements[j - lim] > temp; j -= lim)
                        elements[j] = elements[j - lim];
                    elements[j] = temp;
                }
            }
        }

            inline string name() { return "ShellSort"; }
};

#endif
