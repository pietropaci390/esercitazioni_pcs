#include <iostream>
#include <vector>
#include <string>
#include "timecounter.h"
#include "sorting.hpp"
#include "randfiller.h"
#include <algorithm>

using namespace std;


int main(void)
{
    randfiller rf;

    vector<int> vec;
    for (int i = 4; i<=8192; i *= 2)
    {
        vec.resize(i);
        rf.fill(vec, -10000, 10000);

        vector<int> vec_bubble = vec;//ho bisogno di copiare 4 volte
        vector<int> vec_insertion = vec;//lo stesso vettore
        vector<int> vec_selection = vec;//affinchè il confronto sia
        vector<int> vec_std = vec;//attendibile

        timecounter tc;
        
        //tempo bubble
        tc.tic();
        bubble_sort(vec_bubble);
        //print_vector(vec_bubble);
        double tbub = tc.toc();

        //tempo insertion
        tc.tic();
        insertion_sort(vec_insertion);
        //print_vector(vec_insertion);
        double tins = tc.toc();

        //tempo selection
        tc.tic();
        selection_sort(vec_selection);
        //print_vector(vec_selection);
        double tsel = tc.toc();
        
        //tempo stdsort
        tc.tic();
        sort(vec_std.begin(), vec_std.end());
        double tstd = tc.toc();

        string migliore;
        double miglior_tempo = tbub;
        migliore = "Bubblesort";

        if (tins<miglior_tempo)
        { 
            miglior_tempo = tins;
            migliore = "Insertionsort";
        }


        if (tsel<miglior_tempo)
        { 
            miglior_tempo = tsel;
            migliore = "Selectionsort";
        }

        
        if (tstd<miglior_tempo)
        { 
            miglior_tempo = tstd;
            migliore = "Standard Sort";
        }

        cout << "Tempi di esecuzione per un vettore di dimensione " << i << ":\n";
        cout << "Bubblesort:" << tbub << "\n";
        cout << "Insertionsort:" << tins << "\n";
        cout << "Selectionsort:" << tsel << "\n";
        cout << "Standardsort:" << tstd << "\n";
        cout << "il più veloce è stato:" << " "<< migliore;
        cout << " (con un tempo di" << " "<< miglior_tempo << "s)" << "\n";
    
    }
    return 0;
}
