#pragma once

#include <set>
#include <map>
#include <cstddef>
#include "undirected_edge.hpp"


template<typename T>
class undirected_graph
{
    private:
        std::set<undirected_edge<T>> archi;
        std::map<T,std::set<undirected_edge<T>>> grafo;
        std::set<T> nodi;
    public:
        undirected_graph() = default;
        undirected_graph(const undirected_graph<T>& other)
        {
            archi = other.archi;
            grafo = other.grafo;
            nodi = other.nodi;
        }

        std::set<T> neigbhours(const T& nodo) const
        {
            auto iteratore = grafo.find(nodo);
            std::set<T> adiacenti;

            if (iteratore != grafo.end())
            {
                auto it = iteratore->second.begin();
                while(it!=iteratore->second.end())
                {   
                    if ((*it).from() == nodo)
                    {
                        adiacenti.insert(it->to());
                    }
                    else
                    {
                        adiacenti.insert(it->from());
                    }      
                    it++;
                }
            }
            return adiacenti;
        }
        
        void add_edge(const T&a,const T& b)
        {
            undirected_edge<T> e(a,b);

            grafo[a].insert(e);
            grafo[b].insert(e);
            archi.insert(e);
            nodi.insert(a);
            nodi.insert(b);

        }

        const std::set <undirected_edge<T>>& all_edges() const
        {
            return archi;
        }

        const std::set<T>& all_nodes() const
        {
            return nodi;
        }

        int edge_number(const undirected_edge<T>& arco) const
        {
            int numerazione = 0;
            auto iteratore = archi.begin();
            while(iteratore != archi.end())
            {
                if (*iteratore == arco)
                {
                    return numerazione;
                }

                numerazione++;
                iteratore++;
            }

            return -1;// l'arco non è nel grafo
        }

        undirected_edge<T> edge_at(const int& numerazione) const
        {
            auto iteratore = archi.begin();
            int contatore = 0;
            if (numerazione > -1 && static_cast<size_t>(numerazione) < archi.size())
            {
                while(contatore != numerazione)
                {
                    iteratore++;
                    contatore++;
                }
                return (*iteratore);
            }

            return undirected_edge<T>();//se il numero d'arco non corrisponde a nessun arco, restituisco l'arco vuoto
        }

        undirected_graph<T> operator-(const undirected_graph<T>& other) const
        {
            undirected_graph<T> differenza;
            for(size_t i = 0; i < this->archi.size(); i++)
            {
                undirected_edge<T> arco_t = edge_at(i);
                bool flag = true;

                for (size_t j = 0; j < other.archi.size(); j++)
                {
                    undirected_edge<T> arco_o = other.edge_at(j);

                    if (arco_t == arco_o)
                    {
                        flag = false;
                    }

                } 
                if (flag)
                {
                    differenza.add_edge(arco_t.from(),arco_t.to());
                }
            }

            return differenza;
        }
        
};
