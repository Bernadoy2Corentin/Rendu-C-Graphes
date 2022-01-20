#include "AdjNode.h"
#include <iostream>
#include <limits>
AdjNode::AdjNode(std::string end, double x): end(end), x(x){}

void AdjNode::print(){
    std::cout << "{" << end << ":" << x << "},"; 
}

bool AdjNode::exists(){
    if (x == std::numeric_limits<double>::infinity()){ // les sommets non reliés sont représentés comme reliés par des arètes de poids infini
        return false;
    }
    return true;
}

std::string AdjNode::name(){
    return end;
}

double AdjNode::weight(){
    return x;
}
