#pragma once
#include <vector>
#include <unordered_map>
#include <string>


class GraphMat{
    std::vector<std::vector<double>> graph; // notre matrice est un vecteur de vecteur
    std::unordered_map<std::string, int> position; // un dictionnaire qui relie le nom d'un sommet à sa place dans la matrice
    public:
    GraphMat(int i, std::unordered_map<std::string, int> postion);//constructeur, à partir de sa taille i
    GraphMat(const GraphMat& Gmat);//constructeur de copie
    void reset(int i);// crée une matrice remplie de inf par défaut (graph avec i sommet sans arêtes)
    int size();// renvoie le nombre de sommets
    int readNode(std::string st);// vérfie si le sommet existe et renvoie sa position dans la matrice
    std::vector<std::string> Nodes();// renvoie la liste des sommets
    std::vector<std::string> ends(std::string start);// renvoie la liste des voisins d'un sommet
    void setEdge(std::string start, std::string end, double x);//fixe l'arête de start à end à la valeur x
    double readEdge(std::string start, std::string end); //renvoie la valeur de l'arête allant start à end 
    void print(int i); //affiche le graphe, l'entier i règle l'espacement entre les colonnes (il est conseillé d'avoir i = 2 + taille du plus grand nombre du graphe)
};