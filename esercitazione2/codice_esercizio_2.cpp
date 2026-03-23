#include <iostream>
#include <cmath>

int main()
{
    static const int N = 10;
    double arr[N] = {4.2, 1.1, 2.7, 3.4, 1.9, 9.8, 4.5, 6.1, 8.8, 1.2};
    double minimo = arr[0];
    double massimo = arr[0];
    double media = arr[0]/N;
    double media_quadratica = (arr[0]*arr[0])/N;

    for (int i = 1; i<N; i++)
    {
        minimo = std::min(minimo,arr[i]);
        massimo = std::max(massimo,arr[i]);
        media = media + arr[i]/N;
        media_quadratica = media_quadratica + ((arr[i]*arr[i])/N);
    }
    
    double deviazione_standard = sqrt(media_quadratica-(media*media));
    std::cout<<minimo<<"\n";
    std::cout<<massimo<<"\n";
    std::cout<<media<<"\n";
    std::cout<<deviazione_standard<<"\n";
}