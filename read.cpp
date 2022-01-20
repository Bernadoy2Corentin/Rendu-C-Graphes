#include "read.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
// #include "transfer.h"
// #include "Parcours.h"
// #include "pcc.h"


void rawGraph(std::string filename){
    std::ifstream input_file(filename);
    // si problème d'ouverture de fichier on s'en va
    if (!input_file.is_open()) {
        std::cerr << "cannot open file '" << filename << "'" << std::endl;
        exit(1);
    }
    std::string line;
    int i = 0;
    //on affiche e=le graphe ligne par ligne (donc arrête par arête)
    while (getline(input_file, line)){
        std::cout << line << std::endl;
        i++;
    }
    //on affiche le nombre d'arêtes en complément
    std::cout << "le graphe possède " << i << " arètes" << std::endl;
}

GraphLadj txt_toGraphLadj(std::string filename){
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "cannot open file '" << filename << "'" << std::endl;
        exit(1);
    }
    //on construit un graphe vide avec des valeurs non initialisées
    std::string s;
    std::vector<AdjNode> v;
    std::unordered_map<std::string, std::vector<AdjNode>> g0 {{s,v}}; 
    GraphLadj graph {g0};
    std::string line;
    while (getline(input_file, line)){
        //chaque ligne est constituée de deux string et d'un double sous la forme
        //départ arrivée valeur de l'arête
        std::istringstream iss(line);
        std::string x;
        std::vector<std::string> edge;
        while (iss >> x){
            edge.push_back(x); //on met tout dans un vecteur de string
        }
        std::string stweight = edge.back(); //on extrait la valeur de l'arête
        edge.pop_back();// on l'enlève du string
        double weight = std::stod(stweight);//on convertit la dernière valeur en double
        graph.setEdge(edge[0], edge[1], weight);//on crée les arêtes (setEdge montre ici tout son talent)
    }
    graph.erase(s);// on enlève la valeur non initialisée du début
    return graph;
}