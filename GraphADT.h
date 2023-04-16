//
// Created by moren on 4/11/2023.
//

#ifndef GRAPHADT_GRAPHADT_H
#define GRAPHADT_GRAPHADT_H

#include <list>
#include "ObjectEdge.h"


template<typename G>
class GraphADT{
public:
    //Return a vertex list of all the vertices of the graph.
    std::list<ObjectVertex<G>> vertices();

    //Return an edge list of all the edges of the graph.
    std::list<ObjectEdge<G>> edges();

    //Insert and return a new vertex storing element x.
    void insertVertex(x);

    //Insert and return a new undirected edge with end vertices and storing new edge
    void insertEdge(ObjectVertex<G>,ObjectVertex<G>,ObjectEdge<G>);

    //Remove vertex and all its incident edges
    void eraseVertex(ObjectVertex<G>);

    //Remove edge e
    void eraseEdge(e);

    friend ObjectEdge<G>;
    friend ObjectVertex<G>;
};

template<typename G>
void GraphADT<G>::eraseVertex(ObjectVertex<G>) {

}

template<typename G>
void GraphADT<G>::insertEdge(ObjectVertex<G>, ObjectVertex<G>, ObjectEdge<G>) {

}

template<typename G>
std::list<ObjectEdge<G>> GraphADT<G>::edges() {
    return std::list<ObjectEdge<G>>();
}

template<typename G>
std::list<ObjectVertex<G>> GraphADT<G>::vertices() {
    return std::list<ObjectVertex<G>>();
}


#endif //GRAPHADT_GRAPHADT_H
