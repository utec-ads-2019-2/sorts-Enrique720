#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>
#include <vector>
class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            vector<int> temp;
            for(int i  = 0; i < size; i++){
                temp.push_back(elements[i]);
            }
            int max = *max_element(temp.begin(), temp.end());
            int min = *min_element(temp.begin(), temp.end());
            int range = max - min + 1;
            vector<int> count(range), output(temp.size());
            for(int i = 0; i < temp.size(); i++)
                count[temp[i]-min]++;

            for(int i = 1; i < count.size(); i++)
                count[i] += count[i-1];

            for(int i = temp.size()-1; i >= 0; i--)
            {
                output[ count[temp[i]-min] -1 ] = temp[i];
                count[temp[i]-min]--;
            }

            for(int i=0; i < temp.size(); i++)
                temp[i] = output[i];

            for(int i = 0; i < size; i++){
                elements[i] = temp[i];
            }
        }
        inline string name() { return "CountingSort"; }
};

#endif
