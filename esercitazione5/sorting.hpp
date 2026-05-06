
#pragma once
#include <iostream>
#include <vector>
#include <string>



template<typename T>

void bubble_sort(std::vector<T>& vec)
{
    if(vec.size()<2)
    {
        return;
    }
    for (size_t i = 0; i<vec.size()-1; i++)
    {
        for (size_t j = vec.size()-1; j > i; j--)
        {
            if (vec[j]<vec[j-1])
            {   
                T min = vec [j];
                vec[j] = vec[j-1];
                vec [j-1] = min;
            }
        }
    }
}

template<typename T>
void insertion_sort(std::vector<T>& vec)
{   
    
    if(vec.size()<2)
    {
        return;
    }
    for (size_t j = 1; j<vec.size(); j++)
    {
        T key = vec[j];
        int i = j-1;
        while (i >=0 && vec[i]>key)
        {   
            vec[i+1] = vec[i];
            i--;
        }
        vec[i+1] = key;
    }
}

template<typename T>
void selection_sort(std::vector<T>& vec)
{   
    
    if(vec.size()<2)
    {
        return;
    }
    for ( size_t i = 0; i<vec.size()-1; i++)
    {
        size_t min = i;
        for (size_t j = i+1; j<vec.size(); j++)
        {
            if (vec[j]<vec[min])
            {
                min = j;   
            }
        }
        T max = vec[i];
        vec[i] = vec[min];
        vec[min] = max;
    }
}

template<typename T>
void merge(std::vector<T>& vec, size_t sx, size_t mid,size_t dx)
{
    size_t n1 = mid-sx+1;
    size_t n2 = dx-mid;

    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for (size_t i = 0; i < n1; i++)
    {
        L[i] = vec[sx+i];
    }

    for (size_t j = 0; j < n2; j++)
    {
        R[j] = vec[mid+j+1];
    }

    size_t i = 0;
    size_t j = 0;


    while (i < L.size() && j < R.size())
    {
        if (L[i] <= R[j])
        {
            vec[sx] = L[i];
            i++;
        }

        else
        {
            vec[sx] = R[j];
            j++;
        }

        sx++;
    }
    
    while (i < L.size())
    {
        vec[sx] = L[i];
        i++;
        sx++;
    }

    
    while (j < R.size())
    {
        vec[sx] = R[j];
        j++;
        sx++;
    }

}
template<typename T>
void mergesort(std::vector<T>& vec, size_t sx, size_t dx)
{
    if (sx<dx)
    {
        size_t mid = (sx+dx)/2;
        mergesort(vec, sx, mid);
        mergesort(vec, mid+1, dx);
        merge(vec, sx, mid, dx);
    }
}

//Dovendo chiamare mergesort rispetto a vec.size()-1,utilizzo un'altra
//funzione per gestire il caso in cui ho un vettore vuoto.
//Inoltre in questo modo chiamando la funzione nel main
//non ho bisogno di inserire tutti e tre i parametri.
template<typename T>
void call_mergesort(std::vector<T>& vec)
{
    if(vec.size()>1)//il vettore di lunghezza uno è ordinato
    {
        mergesort(vec,0,vec.size()-1);
    }
}

template<typename T>
size_t partition(std::vector<T>& vec, size_t p, size_t r)
{
    T x = vec[r];
    size_t i = p;

    for(size_t j = p; j < r; j++)
    {
        if (vec[j]<=x)
        {
            T value = vec[i];
            vec[i] = vec[j];
            vec[j] = value;
            i++;

        }
    }
    T value = vec[i];
    vec[i] = vec[r];
    vec[r] = value;

    return i;
}

template<typename T>
void quicksort(std::vector<T>& vec, size_t p, size_t r)
{
    if (p<r)
    {
        size_t q= partition(vec,p,r);
        if (q>0)
        {
             quicksort(vec,p,q-1);
        }
        quicksort(vec,q+1,r);
    }
}
//faccio la stessa cosa già fatta per mergesort
template<typename T>
void call_quicksort(std::vector<T>& vec)
{
    if(vec.size()>1)
    {
        quicksort(vec, 0, vec.size()-1);
    }
}

template<typename T>
void quick_ottimo(std::vector<T>& vec,size_t p, size_t r)
{
    if (p>=r)
    {
        return;
    }
    size_t dim = r-p+1;

    if (dim<20)//notato che in media da dim=21 quicksort è più veloce
    {
        return;
    }
    if(p <r)
    {
        size_t q = partition(vec, p, r);
        if (q>p)
        {
            quick_ottimo(vec, p ,q-1);
        }
        if (q<r)
        {
            quick_ottimo(vec,q+1,r);
        }
    }
}

template<typename T>
void quicksort_ottimo(std::vector<T>& vec)
{
    if (vec.size()<2)
    {
        return;
    }
    quick_ottimo(vec, 0, vec.size()-1);

    insertion_sort(vec);
}