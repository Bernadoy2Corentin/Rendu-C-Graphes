#include "graphLadj.h"
#include "graphMat.h"
#include "transfer.h"
#include "read.h"
#include "Parcours.h"
#include "pcc.h"
#include <iostream>
#include <cstdlib>

void traitement(std::string filename, int i, int level){
    std::cout << "Le fichier d'origine est un fichier txt contenant un graphe sous cette forme:" << std::endl;
    rawGraph(filename);
    std::cout << std::endl;
    std::cout << "on le transforme en graphe par liste d'adjacence qu'on affiche ici:" << std::endl;
    GraphLadj graph {txt_toGraphLadj(filename)};
    graph.print();
    std::vector<std::string> n = graph.Nodes();
    srand(time(0));
    int a = rand() % n.size();
    int b = rand() % n.size();
    std::cout << "On manipule l'arète entre " << n[a] << " et " << n[b] << " entre autres" << std::endl;
    double x = graph.readEdge(n[a], n[b]);
    if (x == std::numeric_limits<double>::infinity()){
        std::cout << "Il n'y a pas d'arète entre " << n[a] << " et " << n[b] << " son poids est infini dans notre représentation" << std::endl;
        std::cout << "on change son poids en " << 22 << std::endl;
        graph.setEdge(n[a], n[b], 22);
    }
    else{
        std::cout << "Le poids de cette arète est " << x << std::endl;
        std::cout << "on change son poids en " << x + 22 << std::endl;
        graph.setEdge(n[a], n[b], x + 22);
    }
    std::cout << "on affiche le graphe pour voir le changement" << std::endl;
    graph.print();
    std::cout << "on reviens au graphe initial, que l'on convertit en graphe par matrice d'adjacence" << std::endl;
    graph.setEdge(n[a], n[b], x);
    GraphMat g {LadjToMat(graph)};
    g.print(i);
    std::vector<std::string> n0 {g.Nodes()};
    srand(time(0));
    int c = rand() % n0.size();
    int d = rand() % n0.size();
    std::cout << "on fait les mêmes traitements sur l'arète entre " << n0[c] << " et " << n0[d] << std::endl;
    double y = g.readEdge(n0[c], n0[d]);
    if (y == std::numeric_limits<double>::infinity()){
        std::cout << "Il n'y a pas d'arète entre " << n0[c] << " et " << n0[d] << " son poids est infini dans notre représentation" << std::endl;
        std::cout << "on change son poids en " << 22 << std::endl;
        g.setEdge(n0[c], n0[d], 22);
    }
    else{
        std::cout << "Le poids de cette arète est " << y << std::endl;
        std::cout << "on change son poids en " << y + 22 << std::endl;
        g.setEdge(n0[c], n[d], y + 22);
    }
    std::cout << "on affiche le graphe pour voir le changement" << std::endl;
    g.print(i);
    std::cout << "on revient au graphe initial" << std::endl;
    g.setEdge(n0[c], n0[d], y);
    g.print(i);
    std::cout << "on teste la conversion inverse" << std::endl;
    GraphLadj graph0 {MatToLadj(g)};
    graph0.print();
    std::cout << "on compare au graphe en liste d'adjacence originel" << std::endl;
    graph.print();
    std::cout << "On regarde maintenant les parcours: on parcourt en profondeur le graphe par liste d'adjacence" << std::endl;
    std::cout << "De manière récursive" << std::endl;
    DfsRecLadjTotal(graph);
    std::cout << "De manière itérative" << std::endl;
    DfsItLadjTotal(graph);
    std::cout << "Le graphe par Matrice D'adjacence" << std::endl;
    std::cout << "De manière récursive" << std::endl;
    DfsRecMatTotal(g);
    std::cout << "De manière itérative" << std::endl;
    DfsItMatTotal(g);
    std::cout << "on affiche le graphe de base pour comparer avec les parcours" << std::endl;
    rawGraph(filename);
    if (level == 0){
        std::cout << "On parcours tout le graphe en largeur" << std::endl;
        std::cout << "Le graphe par liste D'adjacence" << std::endl;
        BfsLadjTotal(graph);
        std::cout << "Le graphe par Matrice D'adjacence" << std::endl;
        BfsMatTotal(g);
    }
    else{
        std::cout << "On parcourt le graphe à partir du sommet " << n0[c] << " jusqu'à la " << level << "ième génération" << std::endl;
        std::cout << "Par liste d'adjacence" << std::endl;
        std::vector<std::string> v;
        BfsLadj(graph, n0[c], v, level);
        std::cout << "Par matrice d'adjacence" << std::endl;
        std::vector<std::string> v0;
        BfsMat(g, n0[c], v, level);
    }
    std::cout << "L'orginal est pour rappel" << std::endl;
    g.print(i);
    std::cout << "On affiche les valeurs des plus courts chemins avec l'algorithme de Floyd-Warshall" << std::endl;
    FloydWarshall(g);
}

int main (int argc, char** argv) {
    if (argc == 1){
        return EXIT_FAILURE;
    }
    traitement(argv[1], 6, 1);
    return EXIT_SUCCESS;
}