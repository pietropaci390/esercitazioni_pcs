
#pragma once
#include <iostream>
#include <vector>
#include <string>

template<typename T>

void bubble_sort(std::vector<T>& vec)
{
    for (size_t i = 1; i<vec.size()-1; i++)
    {
        for (size_t j = vec.size(); j >= i; j--)
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
    for ( size_t i = 0; i<vec.size()-1; i++)
    {
        int min = i;
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

