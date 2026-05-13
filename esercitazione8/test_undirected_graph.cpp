#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include "undirected_graph.hpp"

int main()
{
    //controllo prima undirected_edge e poi undirected_graph
    undirected_edge<int> e1(1,2);
    undirected_edge<int> e2(2,1);
    undirected_edge<int> e3(2,6);
    undirected_edge<int> e4(4,3);
    undirected_edge<int> arco_vuoto;

    if(e1.from() != 1 || e1.to() != 2)
    {
        std::cerr<<"il costruttore di undirected_edge ha fallito\n";
        return EXIT_FAILURE;
    }
    
    if(e2.from() != 1 || e2.to() != 2)
    {
        std::cerr<<"il costruttore di undirected_edge ha fallito\n";
        return EXIT_FAILURE;
    }
    
    if(e3.from() != 2 || e3.to() != 6)
    {
        std::cerr<<"il costruttore di undirected_edge ha fallito\n";
        return EXIT_FAILURE;
    }
    
    if(e4.from() != 3 || e4.to() != 4)
    {
        std::cerr<<"il costruttore di undirected_edge ha fallito\n";
        return EXIT_FAILURE;
    }

    if(!(arco_vuoto == undirected_edge<int>()))
    {
        std::cerr<<"il costruttore di undirected_edge ha fallito\n";
        return EXIT_FAILURE;
    }

    if(!(e1 == e2))
    {
        std::cerr<<"operator== ha fallito\n";
        return EXIT_FAILURE;
    }
    
    if (!(e1 < e3))
    {
        std::cerr<<"operator< ha fallito\n";
        return EXIT_FAILURE;
    }

    if (!(e1 < e4))
    {
        std::cerr<<"operator< ha fallito\n";
        return EXIT_FAILURE;
    }

    if (!(e3 < e4))
    {
        std::cerr<<"operator< ha fallito\n";
        return EXIT_FAILURE;
    }

    if (e4 < e3)
    {
        std::cerr<<"operator< ha fallito\n";
        return EXIT_FAILURE;
    }

    std::ostringstream os; //lo uso per mettere l'output in una stringa
    os << e1;

    if (os.str() != "(1,2)")
    {
        std::cerr<<"operator<< ha fallito\n";
        return EXIT_FAILURE;
    }


    //test di undirected_graph
    undirected_graph<int> grafo1;
    grafo1.add_edge(0, 4);
    grafo1.add_edge(5, 6);
    grafo1.add_edge(0, 2);
    grafo1.add_edge(1, 2);
    grafo1.add_edge(6, 5);
    grafo1.add_edge(0, 4);
    grafo1.add_edge(5, 7);
    grafo1.add_edge(9, 11);


    //test add_edge
    if(grafo1.all_edges().size() != 6)
    {
        std::cerr<<"il metodo add_edge ha fallito\n";
        return EXIT_FAILURE;
    }
    if(grafo1.all_nodes().size() != 9)
    {
        std::cerr<<"il metodo add_edge ha fallito\n";
        return EXIT_FAILURE;
    }
    if(grafo1.edge_number(undirected_edge<int>(0,2)) == -1)//l'arco non c'è
    {
        std::cerr<<"il metodo add_edge ha fallito\n";
        return EXIT_FAILURE;
    }
    if(grafo1.edge_number(undirected_edge<int>(0,4)) == -1)
    {
        std::cerr<<"il metodo add_edge ha fallito\n";
        return EXIT_FAILURE;
    }
    
    if(grafo1.edge_number(undirected_edge<int>(1,2)) == -1)
    {
        std::cerr<<"il metodo add_edge ha fallito\n";
        return EXIT_FAILURE;
    }
    
    if(grafo1.edge_number(undirected_edge<int>(5,6)) == -1)
    {
        std::cerr<<"il metodo add_edge ha fallito\n";
        return EXIT_FAILURE;
    }
    
    if(grafo1.edge_number(undirected_edge<int>(5,7)) == -1)
    {
        std::cerr<<"il metodo add_edge ha fallito\n";
        return EXIT_FAILURE;
    }
    
    if(grafo1.edge_number(undirected_edge<int>(9,11)) == -1)
    {
        std::cerr<<"il metodo add_edge ha fallito\n";
        return EXIT_FAILURE;
    }

    //test all_edges
    std::set<undirected_edge<int>> attesi_all_edges;
    attesi_all_edges.insert(undirected_edge<int>(0,4));
    attesi_all_edges.insert(undirected_edge<int>(0,2));
    attesi_all_edges.insert(undirected_edge<int>(1,2));
    attesi_all_edges.insert(undirected_edge<int>(5,6));
    attesi_all_edges.insert(undirected_edge<int>(9,11));
    attesi_all_edges.insert(undirected_edge<int>(5,7));

    if(!(grafo1.all_edges() == attesi_all_edges))
    {
        std::cerr<<"il metodo all_edges ha fallito\n";
        return EXIT_FAILURE;
    }

    //test all_nodes
    std::set<int> attesi_all_nodes;
    attesi_all_nodes.insert(0);
    attesi_all_nodes.insert(1);
    attesi_all_nodes.insert(2);
    attesi_all_nodes.insert(4);
    attesi_all_nodes.insert(5);
    attesi_all_nodes.insert(6);
    attesi_all_nodes.insert(7);
    attesi_all_nodes.insert(9);
    attesi_all_nodes.insert(11);
    
    if (!(grafo1.all_nodes() == attesi_all_nodes))
    {
        std::cerr<<"il metodo all_nodes ha fallito\n";
        return EXIT_FAILURE;    
    }


    //test neighbours
    std::set<int> attesi_di_0;
    attesi_di_0.insert(4);
    attesi_di_0.insert(2);

    if(!(grafo1.neigbhours(0) == attesi_di_0))
    {
        std::cerr<<"il metodo neigbhours ha fallito\n";
        return EXIT_FAILURE;
    }

    
    std::set<int> attesi_di_1;
    attesi_di_1.insert(2);

    if(!(grafo1.neigbhours(1) == attesi_di_1))
    {
        std::cerr<<"il metodo neigbhours ha fallito\n";
        return EXIT_FAILURE;
    }

    
    std::set<int> attesi_di_2;
    attesi_di_2.insert(0);
    attesi_di_2.insert(1);

    if(!(grafo1.neigbhours(2) == attesi_di_2))
    {
        std::cerr<<"il metodo neigbhours ha fallito\n";
        return EXIT_FAILURE;
    }

    
    std::set<int> attesi_di_4;
    attesi_di_4.insert(0);

    if(!(grafo1.neigbhours(4) == attesi_di_4))
    {
        std::cerr<<"il metodo neigbhours ha fallito\n";
        return EXIT_FAILURE;
    }    
    

    std::set<int> attesi_di_5;
    attesi_di_5.insert(6);
    attesi_di_5.insert(7);

    if(!(grafo1.neigbhours(5) == attesi_di_5))
    {
        std::cerr<<"il metodo neigbhours ha fallito\n";
        return EXIT_FAILURE;
    }

    
    std::set<int> attesi_di_6;
    attesi_di_6.insert(5);

    if(!(grafo1.neigbhours(6) == attesi_di_6))
    {
        std::cerr<<"il metodo neigbhours ha fallito\n";
        return EXIT_FAILURE;
    }

    
    std::set<int> attesi_di_7;
    attesi_di_7.insert(5);

    if(!(grafo1.neigbhours(7) == attesi_di_7))
    {
        std::cerr<<"il metodo neigbhours ha fallito\n";
        return EXIT_FAILURE;
    }

    
    std::set<int> attesi_di_9;
    attesi_di_9.insert(11);

    if(!(grafo1.neigbhours(9) == attesi_di_9))
    {
        std::cerr<<"il metodo neigbhours ha fallito\n";
        return EXIT_FAILURE;
    }


    std::set<int> attesi_di_11;
    attesi_di_11.insert(9);

    if(!(grafo1.neigbhours(11) == attesi_di_11))
    {
        std::cerr<<"il metodo neigbhours ha fallito\n";
        return EXIT_FAILURE;
    }

    std::set<int> vuoto;

    if(!(grafo1.neigbhours(12) == vuoto))
    {
        std::cerr<<"il metodo neigbhours ha fallito\n";
        return EXIT_FAILURE;
    }


    //test edge_number
    if(grafo1.edge_number(undirected_edge<int>(0,2)) != 0)
    {
        std::cerr<<"il metodo edge_number ha fallito\n";
        return EXIT_FAILURE;
    }
    
    if(grafo1.edge_number(undirected_edge<int>(0,4)) != 1)
    {
        std::cerr<<"il metodo edge_number ha fallito\n";
        return EXIT_FAILURE;
    }
    
    if(grafo1.edge_number(undirected_edge<int>(1,2)) != 2)
    {
        std::cerr<<"il metodo edge_number ha fallito\n";
        return EXIT_FAILURE;
    }

    
    if(grafo1.edge_number(undirected_edge<int>(5,6)) != 3)
    {
        std::cerr<<"il metodo edge_number ha fallito\n";
        return EXIT_FAILURE;
    }

    
    if(grafo1.edge_number(undirected_edge<int>(5,7)) != 4)
    {
        std::cerr<<"il metodo edge_number ha fallito\n";
        return EXIT_FAILURE;
    }

    
    if(grafo1.edge_number(undirected_edge<int>(9,11)) != 5)
    {
        std::cerr<<"il metodo edge_number ha fallito\n";
        return EXIT_FAILURE;
    }

    if(grafo1.edge_number(undirected_edge<int>(4,6)) != -1)// controllo la corretta gestione dell'arco non all'interno del grafo
    {
        std::cerr<<"il metodo edge_number ha fallito\n";
        return EXIT_FAILURE;
    }


    //test edge_at
    if (!(grafo1.edge_at(0) == undirected_edge<int>(0,2)))
    {
        std::cerr<<"il metodo edge_at ha fallito\n";
        return EXIT_FAILURE;
    }
    if (!(grafo1.edge_at(1) == undirected_edge<int>(0,4)))
    {
        std::cerr<<"il metodo edge_at ha fallito\n";
        return EXIT_FAILURE;
    }
        if (!(grafo1.edge_at(2) == undirected_edge<int>(1,2)))
    {
        std::cerr<<"il metodo edge_at ha fallito\n";
        return EXIT_FAILURE;
    }
        if (!(grafo1.edge_at(3) == undirected_edge<int>(5,6)))
    {
        std::cerr<<"il metodo edge_at ha fallito\n";
        return EXIT_FAILURE;
    }
        if (!(grafo1.edge_at(4) == undirected_edge<int>(5,7)))
    {
        std::cerr<<"il metodo edge_at ha fallito\n";
        return EXIT_FAILURE;
    }
        if (!(grafo1.edge_at(5) == undirected_edge<int>(9,11)))
    {
        std::cerr<<"il metodo edge_at ha fallito\n";
        return EXIT_FAILURE;
    }
        if (!(grafo1.edge_at(10) == undirected_edge<int>()))//controllo che andando fuori dal range mi esca un arco vuoto
    {
        std::cerr<<"il metodo edge_at ha fallito\n";
        return EXIT_FAILURE;
    }


    //test operator-
    undirected_graph<int> grafo2;
    grafo2.add_edge(0, 4);
    grafo2.add_edge(5, 7);
    grafo2.add_edge(9, 11);

    undirected_graph<int> risultato = grafo1 - grafo2;

    undirected_graph<int> atteso;
    atteso.add_edge(0, 2);
    atteso.add_edge(1, 2);
    atteso.add_edge(5, 6);

    if (!(atteso.all_edges() == risultato.all_edges()))
    {
        std::cerr<<"operator- ha fallito\n";
        return EXIT_FAILURE;
    }

    undirected_graph<std::string> grafo_stringhe1;
    grafo_stringhe1.add_edge("A","B");
    grafo_stringhe1.add_edge("A","C");
    grafo_stringhe1.add_edge("D","F");
    grafo_stringhe1.add_edge("F","S");
    grafo_stringhe1.add_edge("M","N");
    grafo_stringhe1.add_edge("O","R");

    undirected_graph<std::string> grafo_stringhe2;
    grafo_stringhe2.add_edge("A","B");
    grafo_stringhe2.add_edge("D","F");
    grafo_stringhe2.add_edge("M","N");

    undirected_graph<std::string> risultato_stringhe = grafo_stringhe1 - grafo_stringhe2;

    undirected_graph<std::string> atteso_stringhe;
    atteso_stringhe.add_edge("A","C");
    atteso_stringhe.add_edge("F","S");
    atteso_stringhe.add_edge("O","R");

    if (!(atteso_stringhe.all_edges() == risultato_stringhe.all_edges()))
    {
        std::cerr<<"operator- ha fallito\n";
        return EXIT_FAILURE;
    }


    //test costruttore di copia
    undirected_graph<int> copia(grafo1);

    if(!(copia.all_edges() == grafo1.all_edges()))
    {
        std::cerr<<"il costruttore di copia ha fallito\n";
        return EXIT_FAILURE;
    }
    if(!(copia.all_nodes() == grafo1.all_nodes()))
    {
        std::cerr<<"il costruttore di copia ha fallito\n";
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;
}