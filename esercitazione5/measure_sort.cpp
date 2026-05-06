#include <iostream>
#include <vector>
#include <string>
#include "timecounter.h"
#include "sorting.hpp"
#include "randfiller.h"
#include <algorithm>
#include <fstream>//serve per salvare i dati per il grafico

using namespace std;


int main(void)
{
    randfiller rf;

    const int N = 100;
    
    ofstream file("tempi_sort.csv");

    if (!file.is_open())
    {
        cout << "Errore apertura file\n";
        return 1;
    }
    file << "Dim,Bubblesort,Insertionsort,Selectionsort,Standardsort,Mergesort,Quicksort,QuickOttimo\n";
    for (int dim = 2; dim<=N; dim++)
    {
        vector<vector<int>> tabella(N,vector<int>(dim));
        for(size_t j = 0; j<N; j++)
        {
            rf.fill(tabella[j],-10000,10000);
        }
        vector<vector<int>> vec_bubble = tabella;//ho bisogno di copiare 6 volte
        vector<vector<int>> vec_insertion = tabella;//lo stesso vettore
        vector<vector<int>> vec_selection = tabella;//affinchè il confronto sia
        vector<vector<int>> vec_std = tabella;//attendibile
        vector<vector<int>> vec_merge = tabella;
        vector<vector<int>> vec_quick = tabella;
        


        timecounter tc;
        
        //tempo bubble
        tc.tic();
        for (int k = 0; k < N; k++)
        {
            bubble_sort(vec_bubble[k]);
        }
        double tbub = tc.toc()/N;

        //tempo insertion
        
        tc.tic();
        for (int k = 0; k < N; k++)
        {
            insertion_sort(vec_insertion[k]);
        }
        double tins = tc.toc()/N;

        //tempo selection
        
        tc.tic();
        for (int k = 0; k < N; k++)
        {
            selection_sort(vec_selection[k]);
        }
        double tsel = tc.toc()/N;
        
        //tempo stdsort
        tc.tic();
        for (int k = 0; k < N; k++)
        {
            sort(vec_std[k].begin(), vec_std[k].end());
        }
        double tstd = tc.toc()/N;

        
        tc.tic();
        for (int k = 0; k < N; k++)
        {
            call_mergesort(vec_merge[k]);
        }
        double tmerge = tc.toc()/N;

        
        tc.tic();
        for (int k = 0; k < N; k++)
        {
            call_quicksort(vec_quick[k]);
        }
        double tquick = tc.toc()/N;
        
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

        if (tmerge<miglior_tempo)
        { 
            miglior_tempo = tmerge;
            migliore = "Merge Sort";
        }

        if (tquick<miglior_tempo)
        { 
            miglior_tempo = tquick;
            migliore = "Quick Sort";
        }


        cout << "Tempi di esecuzione per un vettore di dimensione " << dim << ":\n";
        cout << "Bubblesort:" << tbub << "\n";
        cout << "Insertionsort:" << tins << "\n";
        cout << "Selectionsort:" << tsel << "\n";
        cout << "Standardsort:" << tstd << "\n";
        cout << "Mergesort:" << tmerge << "\n";
        cout << "Quicksort:" << tquick << "\n";
        cout << "il più veloce è stato:" << " "<< migliore;
        cout << " (con un tempo di" << " "<< miglior_tempo << "s)" << "\n";
        
        vector<vector<int>> vec_quick_ottimo = tabella;
        tc.tic();
        for (size_t k = 0; k<N; k++)
        {
            quicksort_ottimo(vec_quick_ottimo[k]);
        }
        double t_quick_ottimo = tc.toc()/N;

        file << dim << ","<< tbub <<","<< tins <<","<< tsel <<","<< tstd<<","<< tmerge <<","<< tquick <<","<< t_quick_ottimo<<"\n";

        cout<< "Tempo con Quicksort ottimo:" << t_quick_ottimo<<"\n";
    }
    file.close();
    return 0;
}
