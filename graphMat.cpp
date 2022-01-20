#include "graphMat.h"
#include <limits>
#include <iostream>
#include <algorithm>
#include <iomanip>

GraphMat::GraphMat(int i, std::unordered_map<std::string, int> position):graph(i), position(position){
    reset(i);
}

GraphMat::GraphMat(const GraphMat& Gmat):graph(Gmat.graph), position(Gmat.position){}

void GraphMat::reset(int i){
    std::vector<double> w (i, std::numeric_limits<double>::infinity());
    for (int j = 0; j < i; j++){
        graph.at(j) = w; //on initialise notre graphe comme sans arête, on le remplit après
    }
}

int GraphMat::size(){
    return graph.size();
}

int GraphMat::readNode(std::string st){
    if (position.count(st) == 1){ //on vérifie que le sommet existe 
        return (position.at(st) - 1);
    }
    else{
        std::cerr << "error, no node" << st << std::endl;
        exit(1);
    }
}

double GraphMat::readEdge(std::string start, std::string end){
    int i = this->readNode(start);
    int j = this->readNode(end); 
    return graph.at(i).at(j);
}

void GraphMat::setEdge(std::string start, std::string end, double x){
    int i = this->readNode(start);
    int j = this->readNode(end); 
    if (i < graph.size() && j < graph.size()){
    graph.at(i).at(j) = x; // on vérfie que l'arête est dans le graphe
    }
    else{
        std::cerr << "error, edge out of range" << std::endl;
        exit(1);
    }
    // cette fonction est bien plus rigide que dans le graphe par liste d'adjacence
    // ici on ne peut pas créer de nouveaux sommets sans réinitialiser le graphe
}

std::vector<std::string> GraphMat::Nodes(){
    std::vector<std::string> p;
    for (auto &c : position){
        p.push_back(c.first);
    }
    return p;
}

std::vector<std::string> GraphMat::ends(std::string(start)){
    std::vector<std::string> ends;
    for (auto end: position){
        //on prend uniquement les sommets reliés par une arête
        if (this->readEdge(start, end.first) != std::numeric_limits<double>::infinity()){
            ends.push_back(end.first);
        }
    }
    return ends;
}

void GraphMat::print(int i){
    std::vector<std::string> n = this->Nodes();
    std::cout << std::setw(i) << std::left << " ";// les lignes de ce type servent à alligner les lignes de la matrice
    for (std::string c : n){
        std::cout << std::setw(i) << std::left << c;
    }
    std::cout << std::endl;
    for (std::string c : n){
        std::cout << std::setw(i) << std::left << c;
        for (std::string d: n){
            std::cout << std::setw(i) << std::left << this->readEdge(c,d);
        }
        std::cout << std::endl;
    }
}