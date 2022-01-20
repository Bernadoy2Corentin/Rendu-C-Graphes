###Rendu sujet graphes:

##### Ce rendu contient les fichiers:
- graphLadj.cpp et .h codant le graphe par liste d'adjacence
- AdjNode.cpp et .h contenant une classe auxiliaire à graphLadj
- graphMat.cpp et .h codant le graphe par matrice d'adjacence
- transfer.cpp et .h codant les fonctions permettant de passer d'un graphe à l'autre
- read.cpp et .h pour lire un graphe à partir d'un fichier txt
- 2 fichiers txt et 2 fichier png contenant des graphes sous forme d'image et de texte. Les graphes ont été adaptés ainsi: les arêtes de poids négatifs ont été changé par une arête ayant le même départ et la même arrivée, de poids égal à la valeur absolue. Les arêtes de poids nul ont vu leur poids passer à 0.01
- Parcours qui code les parcours
- pcc qui code l'algorithme de Floyd Warshall, l'algorithme de Dijkstra n'a pas été réalisé.
- un makefile

##### Utilisation :
- pour obtenir l'affichage de test, faire make Graphes
- puis ensuite faire ./Graphes + nom du fichier txt choisi.
