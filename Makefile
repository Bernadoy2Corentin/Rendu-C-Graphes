CPP=g++ -g
RM=rm -f

Graphes : main.o AdjNode.o graphLadj.o graphMat.o Parcours.o pcc.o read.o transfer.o
	$(CPP) $^ -o $@

main.o: main.cpp graphLadj.h graphMat.h transfer.h read.h pcc.h Parcours.h
AdjNode.o: AdjNode.h AdjNode.cpp
graphLadj.o: graphLadj.h graphLadj.cpp AdjNode.h
graphMat.o: graphMat.h graphMat.cpp
Parcours.o: graphLadj.h graphMat.h Parcours.cpp Parcours.h 
pcc.o: pcc.h pcc.cpp graphLadj.h graphMat.h
read.o: read.cpp read.h graphLadj.h
transfer.o: transfer.cpp transfer.h graphLadj.h graphMat.h

%.o: %.cpp
	$(CPP) -o $@ -c $<

clean:
	$(RM) *.o Graphes

.PHONY: clean