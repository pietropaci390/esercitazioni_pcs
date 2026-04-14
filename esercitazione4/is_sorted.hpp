#include <cstdlib>
#include <vector>
#include <iostream>


template <typename T>
int is_sorted(std::vector<T>& vec)
{
    if(vec.size() == 0)
    {
        std::cout<< "Il vettore di lunghezza zero è ordinato per definizione";
        return EXIT_SUCCESS;
    }

    else 
    {

        for (size_t j = 0; j <vec.size()-1; j++)
        {
            if (vec[j]>vec[j+1])
            {
                //std::cout<< "Errore: il vettore non è ordinato";
                return EXIT_FAILURE;
            }
        }
        //std::cout<< "Il vettore è ordinato ";
        return EXIT_SUCCESS;
    }
}