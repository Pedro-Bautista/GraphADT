//
// Created by moren on 4/11/2023.
//

#ifndef GRAPHADT_GRAPHADT_H
#define GRAPHADT_GRAPHADT_H

#include <list>

template<typename G>
class ObjectVertex{
public:
    G operator*();
    G incidentEdges();
    G isAdjacentTo(V);
};
template<typename G>
class ObjectEdge{
public:
    G operator*()
    endVertices();
    opposite(V);
    isAdjacentTo(F);
    IsIncidentOn(v);

};
template<typename G>
class GraphADT{
public:
    std::list<ObjectVertex<G>> vertices();
    std::list<ObjectEdge<G>> edges();
    void insertVertex(x);
    void insertEdge(ObjectVertex<G>,ObjectVertex<G>,ObjectEdge<G>);
    void eraseVertex(ObjectVertex<G>);
    void eraseEdge(e);
};

template<typename G>
void GraphADT<G>::eraseVertex(ObjectVertex<G>) {

}

#endif //GRAPHADT_GRAPHADT_H
