//
// Created by moren on 4/11/2023.
//

#ifndef GRAPHADT_GRAPHADT_H
#define GRAPHADT_GRAPHADT_H

#include <list>
#include "ObjectEdge.h"
#include "ObjectVertex.h"


template<typename G>
class GraphADT {
private:
    std::list<ObjectVertex<G>> verticesList;
    std::list<ObjectEdge<G>> edgesList;

public:
    //Return a vertex list of all the vertices of the graph.
    std::list<ObjectVertex<G>> vertices() const;

    //Return an edge list of all the edges of the graph.
    std::list<ObjectEdge<G>> edges();

    //Insert and return a new vertex storing element x.
    ObjectVertex<G> insertVertex(ObjectVertex<G> vertex);

    //Insert and return a new undirected edge with end vertices and storing new edge
    void insertEdge(ObjectVertex<G>, ObjectVertex<G>, ObjectEdge<G>);

    //Remove vertex and all its incident edges
    void eraseVertex(ObjectVertex<G>);

    //Remove edge e
    void eraseEdge(ObjectEdge<G>);


    friend ObjectEdge<G>;
    friend ObjectVertex<G>;
};



template<typename G>
void GraphADT<G>::eraseEdge(ObjectEdge<G>) {

}

template<typename G>
ObjectVertex<G> GraphADT<G>::insertVertex(ObjectVertex<G> vertex) {
    verticesList.push_back(vertex);
    std::cout << "A vertex, "<< *vertex <<" , has been inserted into the graph, with no edges" << std::endl;
    return vertex;
}


template<typename G>
void GraphADT<G>::eraseVertex(ObjectVertex<G>) {

}

template<typename G>
void GraphADT<G>::insertEdge(ObjectVertex<G> v1, ObjectVertex<G> v2, ObjectEdge<G> e) {


    std::cout <<"A edge, with label " << *e << ", has been inserted between " << *v1 << " and " << *v2 <<".\n";
}

template<typename G>
std::list<ObjectEdge<G>> GraphADT<G>::edges() {
    return edgesList;
}

template<typename G>
std::list<ObjectVertex<G>> GraphADT<G>::vertices() const {
    return verticesList;
}


#endif //GRAPHADT_GRAPHADT_H

