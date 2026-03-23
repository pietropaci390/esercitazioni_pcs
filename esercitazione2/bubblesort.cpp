#include <iostream>


int main()
{
    static const int N = 10;
    double arr[N] = {4.2, 1.1, 2.7, 3.4, 1.9, 9.8, 4.5, 6.1, 8.8, 1.2};
    int contatore = 1;
    while (contatore != 0)
    {    
        contatore=0;

        for (int i = 0; i<N-1; i++)
        {
            if (arr[i]>arr[i+1])
            {   
                contatore= contatore+1;
                double maggiore = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = maggiore;
            }
        }
    }
    for (int i = 0; i<N; i++)
    {
        std::cout << arr[i]<<" ";
    }

    
}