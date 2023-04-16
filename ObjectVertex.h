//
// Created by Ken V on 4/16/23.
//

#ifndef GRAPHADT_OBJECTVERTEX_H
#define GRAPHADT_OBJECTVERTEX_H
#include <list>
#include "ObjectEdge.h"


template<typename G>
class ObjectVertex{
private:
    G label;

public:
    //returns the element of the vertex
    G operator*();

    //returns an edge list of edges incident on the vertex
    std::list<ObjectEdge<G>> incidentEdges();

    //test whether the vertex and V are adjacent
    bool isAdjacentTo(ObjectVertex<G> V);
};

template<typename G>
bool ObjectVertex<G>::isAdjacentTo(ObjectVertex<G> V) {
    //TO BE COMPLETED
    return false;
}

template<typename G>
std::list<ObjectEdge<G>> ObjectVertex<G>::incidentEdges() {
    //TO BE FILLED IN
    return std::list<ObjectEdge<G>>();
}

template<typename G>
G ObjectVertex<G>::operator*() {
    return label;
}


#endif //GRAPHADT_OBJECTVERTEX_H
