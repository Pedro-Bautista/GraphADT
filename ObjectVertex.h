//
// Created by Ken V on 4/16/23.
//

#ifndef GRAPHADT_OBJECTVERTEX_H
#define GRAPHADT_OBJECTVERTEX_H
#include <list>
#include "ObjectEdge.h"
template<typename G>
class ObjectEdge;

template<typename G>
class ObjectVertex{
private:
    G label;
    std::list<ObjectEdge<G>> incidentEdgesList;


public:
    //constructor

    ObjectVertex() = default;

    //constructor
    explicit ObjectVertex(G label) : label(label) {

    }

    //add edge to incidentEdgesList
    void addIncidientEdge(ObjectEdge<G> e) {
        incidentEdgesList.push_back(e);
    }

    //returns the element of the vertex
    G operator*();

    //returns an edge list of edges incident on the vertex
    std::list<ObjectEdge<G>> incidentEdges();


};


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
