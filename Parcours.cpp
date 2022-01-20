#include "Parcours.h"
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <queue>

void DfsRecLadj(GraphLadj graph, std::string s, std::vector<std::string>& v){
        v.push_back(s);//on ajoute le sommet dans la liste des visites
        std::vector<AdjNode> ends {graph.ends(s)};
    for (AdjNode n: ends){// parmi les voisins
        if (not(std::count(v.begin(), v.end(), n.name()))){//si le sommet n'a pas été visité
            //on affiche l'arête qui mène à la prchaine visite
            std::cout << s << " " << n.name() << " " << graph.readEdge(s,n.name())<< std::endl;
            //on lance la visite du voisin
            DfsRecLadj(graph, n.name(), v);
        }
        else{//si on a visité le sommet
            //on affiche l'arête qu'on a pas encore prise
            std::cout << s << " " << n.name() << " " << graph.readEdge(s,n.name())<< std::endl;
            //on ne visite pas le sommet car il a déjà été visité
        }
    }
}

void DfsRecLadjTotal(GraphLadj graph){
    std::vector<std::string> v;
    std::vector<std::string> n = graph.Nodes();
    for (std::string c : n){//on parcourt la liste des sommets
        if (not std::count(v.begin(), v.end(), c)){//si on a pas visité le sommet lors d'appels précédants
            //on lance la visite du sommet non visité
            DfsRecLadj(graph, c, v);
        }
    }
}

void DfsRecMat(GraphMat graph, std::string s, std::vector<std::string>& v){
    //idem DfsRecLadj
    v.push_back(s);
    for (std::string n: graph.ends(s)){
        if (not(std::count(v.begin(), v.end(), n))){
            std::cout << s << " " << n << " " << graph.readEdge(s,n)<< std::endl;
            DfsRecMat(graph, n, v);
        }
        else{
            std::cout << s << " " << n << " " << graph.readEdge(s,n)<< std::endl;
        }
    }
}

void DfsRecMatTotal(GraphMat graph){
    std::vector<std::string> v;
    std::vector<std::string> n = graph.Nodes();
    for (std::string c : n){
        if (not std::count(v.begin(), v.end(), c)){
        DfsRecMat(graph, c, v);
        }
    }
}

void DfsItLadj(GraphLadj graph, std::string s, std::vector<std::string>& v){
    std::stack<std::string> stack;//on crée notre pile
    stack.push(s);//on met le sommet dans la pile : à visiter
    v.push_back(s);//on marque le sommet comme visité
    while (not stack.empty()){
        std::string NewNode = stack.top();//on dépile
        stack.pop();
        for (AdjNode n: graph.ends(NewNode)){//on parcourt les voisins du sommet à visiter
            std::string m {n.name()};
            if (not std::count(v.begin(), v.end(), m)){
                //si le sommet n'as pas été visité, on y va
                std::cout << NewNode << " " << m << " " << graph.readEdge(NewNode,m)<< std::endl;
                //on le stocke pour le mettre à visiter
                stack.push(m);
                v.push_back(m);
            }
            else{//si le sommet a été visité
                //on parcourt uniquement l'arête
                std::cout << NewNode << " " << m << " " << graph.readEdge(NewNode,m)<< std::endl;
            }
        }
    }
}

void DfsItLadjTotal(GraphLadj graph){
    //idem DfsRecLadjTotal, mais en itératif
    std::vector<std::string> v;
    std::vector<std::string> n = graph.Nodes();
    for (std::string c : n){
        if (not std::count(v.begin(), v.end(), c)){
        DfsItLadj(graph, c, v);
        }
    }
}

void DfsItMat(GraphMat graph, std::string s, std::vector<std::string>& v){
    //idem DfsItLadj
    std::stack<std::string> stack;
    stack.push(s);
    v.push_back(s);
    while (not stack.empty()){
        std::string NewNode = stack.top();
        stack.pop();
        for (std::string n: graph.ends(NewNode)){
            if (not std::count(v.begin(), v.end(), n)){
                std::cout << NewNode << " " << n << " " << graph.readEdge(NewNode,n)<< std::endl;
                stack.push(n);
                v.push_back(n);
            }
            else{
                std::cout << NewNode << " " << n << " " << graph.readEdge(NewNode,n)<< std::endl;
            }
        }
    }
}

void DfsItMatTotal(GraphMat graph){
    std::vector<std::string> v;
    std::vector<std::string> n = graph.Nodes();
    for (std::string c : n){
        if (not std::count(v.begin(), v.end(), c)){
        DfsItMat(graph, c, v);
        }
    }
}

void BfsLadj(GraphLadj graph, std::string s, std::vector<std::string>& v, int i){
    std::queue<std::string> queue;
    queue.push(s);
    v.push_back(s);
    int j = 0;
    while ((not queue.empty()) && (j < i)){//on s'arrête à la génération souhaitée
        std::string NewNode = queue.front();
        queue.pop();
        for (AdjNode n: graph.ends(NewNode)){
            std::string m {n.name()};
            if (not std::count(v.begin(), v.end(), m)){
                std::cout << NewNode << " " << m << " " << graph.readEdge(NewNode,m)<< std::endl;
                queue.push(m);
                v.push_back(m);
            }
            else{
                std::cout << NewNode << " " << m << " " << graph.readEdge(NewNode,m)<< std::endl;
            }
        }
        j++;
    }
}

void BfsLadjTotal(GraphLadj graph){
    //on parcourt tout le graphe en largeur
    std::vector<std::string> v;
    std::vector<std::string> n = graph.Nodes();
    for (std::string c : n){
        if (not std::count(v.begin(), v.end(), c)){
        BfsLadj(graph, c, v, n.size());
        }
    }  
}

void BfsMat(GraphMat graph, std::string s, std::vector<std::string>& v, int i){
    std::queue<std::string> queue;
    queue.push(s);
    v.push_back(s);
    int j = 0;
    while ((not queue.empty()) && (j < i)){
        std::string NewNode = queue.front();
        queue.pop();
        for (std::string n: graph.ends(NewNode)){
            if (not std::count(v.begin(), v.end(), n)){
                std::cout << NewNode << " " << n << " " << graph.readEdge(NewNode,n)<< std::endl;
                queue.push(n);
                v.push_back(n);
            }
            else{
                std::cout << NewNode << " " << n << " " << graph.readEdge(NewNode,n)<< std::endl;
            }
        }
    }
}
void BfsMatTotal(GraphMat graph){
    std::vector<std::string> v;
    std::vector<std::string> n = graph.Nodes();
    for (std::string c : n){
        if (not std::count(v.begin(), v.end(), c)){
        BfsMat(graph, c, v, n.size());
        }
    }
}