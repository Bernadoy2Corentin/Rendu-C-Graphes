#include "transfer.h"

GraphMat LadjToMat(GraphLadj& g0){
    std::vector<std::string> n = g0.Nodes();
    std::unordered_map<std::string, int> position;
    int i = 1;
    for (std::string node: n){
        position[node] = i;//on construit le dictionnaire des positions
        i++;
    }
    int j = n.size();
    position.erase("");//on enlève un sommet vide qui peut parfois se créer sans qu'on le veule
    GraphMat g {j, position};//on construit notre graphe vide
    for (std::string node: n){
        // on remplit le graphe avec les valeurs du graphLadj
        std::vector<AdjNode> ends = g0.ends(node);
        for (AdjNode anode: ends){
            if (anode.exists()){
                g.setEdge(node, anode.name(), anode.weight());
            }
        }
    }
    return g;
}

GraphLadj MatToLadj(GraphMat& g0){
    std::vector<std::string> n = g0.Nodes();
    std::unordered_map<std::string, std::vector<AdjNode>> g;
    for (std::string start: n){
        for (std::string end: n){
            if (g0.readEdge(start, end) != std::numeric_limits<double>::infinity()){
                AdjNode a {end, g0.readEdge(start, end)};
                g[start].push_back(a);
            }
        }
    }
    return g;
}