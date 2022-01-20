#include "graphMat.h"
#include "graphLadj.h"

GraphMat LadjToMat(GraphLadj& g0);//de liste d'adjacence à matrice
GraphLadj MatToLadj(GraphMat& g0);// de matrice à liste