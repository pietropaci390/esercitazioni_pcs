#include <iostream>
#include "rational.hpp"

int main()
{
    int a;
    int b;
    int c;
    int d;

    std::cout <<"inserire numeratore e denominatore interi separati da uno spazio:\n";
    if (!(std::cin>> a))
    {
        std::cout <<"Errore:"<< a << "non è un numero intero\n";
        return 1;
    }
    else if (!(std::cin>> b))
    {
        std::cout <<"Errore:"<< b << "non è un numero intero\n";
        return 1;
    }

    else 
    {
        razionali<int> n_1(a,b);

        std::cout <<"inserire numeratore e denominatore interi separati da uno spazio:\n";

        if (!(std::cin>> c))
        {
        std::cout <<"Errore:"<< c << "non è un numero intero\n";
        return 1;
        }
        else if (!(std::cin>> d))
        {
        std::cout <<"Errore:"<< d << "non è un numero intero\n";
        return 1;
        }

        else
        {
            razionali<int> n_2(c,d);
            
            razionali<int> somma = n_1+n_2;
            razionali<int> sottrazione = n_1-n_2;
            razionali<int> prodotto = n_1*n_2;
            razionali<int> divisione = n_1/n_2;

            std::cout <<"I due numeri razionali sono: "<< n_1 <<", "<< n_2 <<"\n";
            std::cout <<"Somma: "<< somma << "\n";
            std::cout <<"Differenza: "<< sottrazione << "\n";
            std::cout <<"Prodotto: "<< prodotto << "\n";
            std::cout <<"divisione: "<< divisione << "\n";
        }

    }

}