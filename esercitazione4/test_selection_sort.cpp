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
        selection_sort(vec);
        //print_vector(vec);


        bool flag = is_sorted(vec);
        if (!flag)
        {
            std::cout<<"Errore di ordinamento";
            return EXIT_FAILURE;
        }

    }

    std::vector<std::string> stringa = {"vasto","fossacesia","sanvito","ortona","pescara","silvi","pineto","roseto","giulianova","martinsicuro"};
    selection_sort(stringa);
    //print_vector(stringa);
    bool flag = is_sorted(stringa);
    if (!flag)
    {
        std::cout<<"Errore di ordinamento";
        return EXIT_FAILURE;
    }
    std::cout<<"Tutto ordinato";
    return EXIT_SUCCESS;

}

