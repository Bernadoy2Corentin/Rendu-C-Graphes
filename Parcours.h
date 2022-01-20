#pragma once
#include "graphLadj.h"
#include "graphMat.h"
// Parcours en profondeur (Depht search first ou Dfs)
// // Récursifs
// // // Par liste d'adjacence
void DfsRecLadj(GraphLadj graph, std::string s, std::vector<std::string>& v);
void DfsRecLadjTotal(GraphLadj graph);
// // // Par matrice d'adjacence
void DfsRecMat(GraphMat graph, std::string s, std::vector<std::string>& v);
void DfsRecMatTotal(GraphMat graph);
// // Itératifs
// // // Par liste d'adjacence
void DfsItLadj(GraphLadj graph, std::string s, std::vector<std::string>& v);
void DfsItLadjTotal(GraphLadj graph);
// // // Par matrice d'adjacence
void DfsItMat(GraphMat graph, std::string s, std::vector<std::string>& v);
void DfsItMatTotal(GraphMat graph);
// Parcours en profondeur (Breadth First Search ou Bfs)
// // Par liste d'adjacence
void BfsLadj(GraphLadj graph, std::string s, std::vector<std::string>& v, int i);
void BfsLadjTotal(GraphLadj graph);
// // Par matrice d'adjacence
void BfsMat(GraphMat graph, std::string s, std::vector<std::string>& v, int i);
void BfsMatTotal(GraphMat graph);