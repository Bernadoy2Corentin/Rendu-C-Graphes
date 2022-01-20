#include "pcc.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>
#include <iomanip>
//Algorithme de Floyd Warshall
//Les zones commentées sont des tentatives pour afficher les plus courts chemins
//Pred fait référence à la matrice des prédécesseurs
//chemins est la matrice contenant chacun des chemins
//les zones commentées compilent mais malheuresement ne permettent pas d'obtenir les résultats...
//décommenter pour voir ce qu'elles affichent
void FloydWarshall(GraphMat graph){
    std::vector<std::string> n = graph.Nodes();
    GraphMat gW {graph}; //on créer une copie du graphe pour pouvoir le modifier plus facilement
    // std::vector<std::string> m (n.size());
    // std::vector<std::vector<std::string>> chemins (n.size(), m);
    // std::vector<std::vector<std::string>> pred (n.size(), m);
    // for (int i = 0; i < chemins.size(); i++){
    //     for (int j = 0; j < chemins.size(); j++){
    //         if (graph.readEdge(n[i], n[j]) != std::numeric_limits<double>::infinity()){
    //         pred.at(i).at(j) = n[i];
    //         }
    //     }
    // }
    for (std::string k : n){
        // int c = 0;
        for (std::string i : n){
            // int d = 0;
            for (std::string j : n){
                if (gW.readEdge(i, k) + gW.readEdge(k, j) < gW.readEdge(i, j)){//condition de Floyd Warshall
                    double x = gW.readEdge(i, k) + gW.readEdge(k, j);
                    gW.setEdge(i, j, x);
                    // int cdk = graph.readNode(k);
                    // if (graph.readEdge(k, j) != std::numeric_limits<double>::infinity()){
                    //     pred.at(c).at(d) = pred.at(cdk).at(d);
                    // }
                    // chemins.at(c).at(d) += " " + k;
                }
                // d++;
            }
            // c++;
        }
    }
    gW.print(6);//on affiche le graphe final
    // std::cout<< "Les chemins les plus courts sont" << std::endl;
    // for (int e = 0; e<chemins.size(); e++){
    //     for (int f = 0; f<chemins.size(); f++){
    //         if (gW.readEdge(n[e], n[f]) != std::numeric_limits<double>::infinity()){
    //             std::cout << n[e] << " " + chemins.at(e).at(f) <<  " " + n[f] + " " << gW.readEdge(n[e], n[f]) << std::endl;
    //         }
    //         else{
    //             std::cout << "pas de chemin entre " << n[e] << " et " << n[f] << std::endl;
    //         }
    //     }
    // }
    // std::cout << std::setw(5) << std::left << " ";
    // for (std::string c : n){
    //     std::cout << std::setw(5) << std::left << c;
    // }
    // std::cout << std::endl;
    // for (int e = 0; e<pred.size(); e++){
    //     std::cout << std::setw(5) << std::left << n[e];
    //     for (int f = 0; f<pred.size(); f++){
    //         std::cout << std::setw(5) << std::left << pred.at(e).at(f) + " ";
    //     }
    //     std::cout << std::endl;
    // }
}