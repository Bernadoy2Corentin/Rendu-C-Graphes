#include "graphLadj.h"
#include <string>

void rawGraph(std::string filename);//permet d'afficher la forme brut du graphe qui sera lue 
GraphLadj txt_toGraphLadj(std::string filename);//fonction pour transformer le graphe sous sa forme txt en graphe par list d'adjacence