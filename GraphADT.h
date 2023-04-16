//
// Created by moren on 4/11/2023.
//

#ifndef GRAPHADT_GRAPHADT_H
#define GRAPHADT_GRAPHADT_H

#include <list>
#include "ObjectEdge.h"
#include "ObjectVertex.h"


template<typename G>
class GraphADT{
private:
    std::list<ObjectVertex<G>> verticesList;
    std::list<ObjectEdge<G>> edgesList;

public:
    //Return a vertex list of all the vertices of the graph.
    std::list<ObjectVertex<G>> vertices();

    //Return an edge list of all the edges of the graph.
    std::list<ObjectEdge<G>> edges();

    //Insert and return a new vertex storing element x.
    ObjectVertex<G> insertVertex(ObjectVertex<G> vertex);

    //Insert and return a new undirected edge with end vertices and storing new edge
    void insertEdge(ObjectVertex<G>,ObjectVertex<G>,ObjectEdge<G>);

    //Remove vertex and all its incident edges
    void eraseVertex(ObjectVertex<G>);

    //Remove edge e
    void eraseEdge(ObjectEdge<G>);

    //Prints vectors
    void printVectors();

    friend ObjectEdge<G>;
    friend ObjectVertex<G>;
};

template<typename G>
void GraphADT<G>::printVectors() {
    std::cout <<"The list of vertices are:\t";
    for (auto i = verticesList.begin(); i != verticesList.end(); ++i) {
        std::cout << **i << "\t";
    }
    std::cout <<"\n";

}

template<typename G>
void GraphADT<G>::eraseEdge(ObjectEdge<G>) {

}

template<typename G>
ObjectVertex<G> GraphADT<G>::insertVertex(ObjectVertex<G> vertex) {
    verticesList.push_back(vertex);
    return vertex;
}


template<typename G>
void GraphADT<G>::eraseVertex(ObjectVertex<G>) {

}

template<typename G>
void GraphADT<G>::insertEdge(ObjectVertex<G>, ObjectVertex<G>, ObjectEdge<G>) {

}

template<typename G>
std::list<ObjectEdge<G>> GraphADT<G>::edges() {
    return edgesList;
}

template<typename G>
std::list<ObjectVertex<G>> GraphADT<G>::vertices() {
    return verticesList;
}


#endif //GRAPHADT_GRAPHADT_H
