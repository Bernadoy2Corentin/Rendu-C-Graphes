#include "graphLadj.h"
#include <iostream>
#include <limits>
#include <algorithm>
GraphLadj::GraphLadj(std::unordered_map<std::string, std::vector<AdjNode>> graph): graph(graph){}

std::vector<std::string> GraphLadj::Nodes(){
    std::vector<std::string> n;
    for (auto c: graph){//on prend les sommets clés du dictionnaire
        n.push_back(c.first);
    }
    // attention, la boucle au dessus ne prend en compte que les sommets dont une arête part: 
    //il faut aussi les sommets qui ne sont qu'arrivée, d'où la boucle suivante
    for (std::string name : n){
        for (AdjNode end: graph[name]){
            if (not std::count(n.begin(), n.end(), end.name())){//si le sommet n'a pas déjà été ramassé
                n.push_back(end.name());//on l'ajoute à la liste des sommets
            }
        }
    }
    return n;
}

std::vector<AdjNode> GraphLadj::ends(std::string start){
    std::vector<AdjNode> ends;
    for (AdjNode end: graph[start]){
        if (end.exists()){ // on peut avoir des problèmes si on rajoute des arêtes infinies dans la liste, on doit donc les enlever
        ends.push_back(end);
        }
    }
    return ends;
}

void GraphLadj::addNode(std::string start){
    std::vector<AdjNode> s;
    graph[start] = s;
}

void GraphLadj::delEdge(std::string start, std::string end){
    for (int i = 0; i < graph[start].size(); i++){
        if (graph[start].at(i).name() == end){//on cherche la bonne arrivée de l'arrête pour la supprimer
            graph[start].erase(graph[start].begin() + i); //on supprime avec le erase des vecteurs, auquel on doit donner une valeur d'indice
        }
    }
    //cette fonction ne fait rien si l'arète n'existe pas
}

void GraphLadj::setEdge(std::string start, std::string end, double x){
    this->delEdge(start, end);//on supprime l'arête si elle existe, puis on la recrée 
    AdjNode e {end, x};
    graph[start].push_back(e);
}

void GraphLadj::erase(std::string s){
    graph.erase(s);
}

double GraphLadj::readEdge(std::string start, std::string end){
    std::vector<AdjNode> v {graph[start]};
    for (AdjNode c: v){
        if (c.name() == end){
            return c.weight();
        }
    }
    return std::numeric_limits<double>::infinity(); //on renvoie l'infini si pas d'arête

}

int GraphLadj::size(){
    std::vector<std::string> n = this->Nodes();
    return n.size();
}

void GraphLadj::print(){
    std::vector<std::string> n = this->Nodes();
    for (auto &c: n){
        std::cout << c;
        for (AdjNode b: graph[c]){
            if (b.exists()){
            b.print();
            }
        }
        std::cout << std::endl;
    }
}