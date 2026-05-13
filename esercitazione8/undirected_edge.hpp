#pragma once

#include <iostream>

template<typename T>
class undirected_edge 
{
    private:
        T pfrom;
        T pto;

    public:
        undirected_edge()
        {
            pfrom = T{};
            pto = T{};
        }
        undirected_edge(const T& a, const T& b)
        {
            //evito il caso di un arco che parte e arriva allo stesso nodo
            if (a == b)//così da garantire from < to
            {
                pfrom = T{};
                pto = T{};
            }
            else if (a < b)
            {
                pfrom = a;
                pto = b;
            }
            else 
            {
                pfrom = b;
                pto = a;
            }
        }
        
        T from() const
        {
            return pfrom;
        }

        T to() const
        {
            return pto;
        }

        
        bool operator <(const undirected_edge<T>& other) const
        {
            if(pfrom == other.pfrom)
            {
                return pto < other.pto;
            }
            return pfrom < other.pfrom; 

        }

        bool operator ==(const undirected_edge<T>& other) const
        {
            if (pfrom == other.pfrom && pto == other.pto)
            {
                return true;
            }
            return false;
        }

};

//se operator<< fosse implementato come metodo membro della classe
//undirected_edge, allora il membro implicito this rappresenterebbe 
//l'operando sinistro dell'operatore
template <typename T>
std::ostream& operator <<(std::ostream& os,const undirected_edge<T>& arco)
{
    os <<"(" << arco.from() << "," << arco.to() << ")";    
    return os;
}

