#include <cstdlib>
#include <vector>
#include <iostream>
#include "randfiller.h"
#include "sorting.hpp"
#include "is_sorted.hpp"
#include "print_vector.hpp"




int main()
{   
    //if (vec.size() == 0)
    //{
    //    return EXIT_SUCCESS;
    //}
    randfiller rf; 
    
    //vettore in cui salvo 100 dimensioni casuali
    std::vector<int> dimensioni(100); 
    rf.fill(dimensioni, 0, 10000);
    std::vector<int> vec;

    for (size_t i = 0; i<100; i++)
    {
        vec.resize(dimensioni[i]);
        rf.fill(vec,-10000,10000);
        insertion_sort(vec);
        //print_vector(vec);


        is_sorted(vec);
    }
    return 0;
}