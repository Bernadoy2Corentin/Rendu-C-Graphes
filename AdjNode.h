#pragma once
#include <string>

class AdjNode{
    // cette classe représente un sommet adjacent par son nom et le poids de l'arête qui le relie au premier
    std::string end;
    double x;
    public:
    AdjNode(std::string end, double x); //le constructeur
    void print(); // permet d'afficher 
    bool exists(); // permet de voir si le sommet est relié (ie si l'arête n'a pas un poids infini)
    std::string name(); // renvoie le nom 
    double weight(); // renvoie le poids
};