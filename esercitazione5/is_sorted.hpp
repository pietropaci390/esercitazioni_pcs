#include <cstdlib>
#include <vector>
#include <iostream>


template <typename T>
bool is_sorted(std::vector<T>& vec)
{
    if(vec.size() <=1)
    {
        return true;
    }

    else 
    {

        for (size_t j = 0; j <vec.size()-1; j++)
        {
            if (vec[j]>vec[j+1])
            {
                //std::cout<< "Errore: il vettore non è ordinato";
                return false;
            }
        }
        //std::cout<< "Il vettore è ordinato ";
        return true;
    }
}