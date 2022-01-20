#pragma once
#include "AdjNode.h"
#include <string>
#include <vector>
#include <unordered_map>


class GraphLadj{
    // la classe des graphes par liste d'adjecence
    // Il s'agit ici d'un dictionnaire affectant à chaque sommet une liste des sommets auquels il est relié
    std::unordered_map<std::string, std::vector<AdjNode>> graph;
    public:
    GraphLadj(std::unordered_map<std::string, std::vector<AdjNode>> graph);
    std::vector<std::string> Nodes(); //renvoie les sommets du graphe
    std::vector<AdjNode> ends(std::string start); //renvoie les voisins du sommet start
    void erase(std::string s);// supprime le sommet s du graphe
    void addNode(std::string start);// ajoute le sommet start
    void delEdge(std::string start, std::string end); // supprime l'arête entre start et end
    void setEdge(std::string start, std::string end, double x); //change la valeur de l'arête entre start et end par x. Crée l'arête et ou les sommets s'ils n'existent pas
    double readEdge(std::string start, std::string end);//renvoie la valeur de l'arête entre start et end
    int size();// renvoie le nombre de sommet du graphe
    void print();// affiche le graphe en conservant la structure en liste d'adjacence
};