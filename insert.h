#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {       
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
              int i, j;
            int temp = 0;
            for (i = 1; i < size; i++)
            {
                temp = elements[i];
                j = i - 1;
                while (j >= 0 && elements[j] > temp)
                {
                    elements[j + 1] = elements[j];
                    j = j - 1;
                }
                elements[j + 1] = temp;
            }
        }

        inline string name() { return "InsertSort"; }
};

#endif
