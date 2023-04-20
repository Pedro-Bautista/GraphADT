//
// Created by Kenneth Verzyl and Pedro Bautista on 4/11/2023.
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

    //get edges
public:
    const std::list<ObjectEdge<G>> &getEdgesList() const {
        return edgesList;
    }

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
    void eraseVertex(ObjectVertex<G> V);

    //sees if vector A and vector B are adjacent
    bool isAdjacent(ObjectVertex<G> A, ObjectVertex<G> B);

    friend ObjectEdge<G>;
    friend ObjectVertex<G>;
};

template<typename G>
bool GraphADT<G>::isAdjacent(ObjectVertex<G> A, ObjectVertex<G> B) {
    //std::cout << "\n" << *A << " tested with " << *B << std::endl;
    std::list<ObjectEdge<std::basic_string<char>>>::iterator i = edgesList.begin();
    for (; i != edgesList.end(); ++i) {
        if (i->isAdjacentTo(A)) {
            //std::cout << *(*i->incidentList.begin());
            std::list<ObjectVertex<std::basic_string<char>>> list2 = i.operator*().incidentList;
            std::list<ObjectVertex<std::basic_string<char>>>::iterator k;
            for (k = list2.begin(); k != list2.end(); ++k) {
                if (*B == **k) {
                    //std::cout << *A << " == " << *B << std::endl;
                    return true;
                }
            }
        }
    }
    return false;
}



template<typename G>
ObjectVertex<G> GraphADT<G>::insertVertex(ObjectVertex<G> vertex) {
    verticesList.push_back(vertex);
    //std::cout << "A vertex, "<< *vertex <<" , has been inserted into the graph, with no edges" << std::endl;
    return vertex;
}


template<typename G>
void GraphADT<G>::eraseVertex(ObjectVertex<G> V) {

    std::list<std::list<ObjectEdge<std::basic_string<char>>>::iterator> toBeRemoved;
    //loops edgeList and stores any iterators that link to edges to be removed in toBeRemoved list
    for (auto j = edgesList.begin(); j != edgesList.end(); ++j) {
        if (j->isAdjacentTo(V)) {
            toBeRemoved.push_back(j);
        }
    }

    //erases edges that need to be removed from the edgeListlist
    for (auto k = toBeRemoved.begin(); k != toBeRemoved.end(); ++k ) {
        edgesList.erase(*k);
    }


    //loops verticesList and removes V
    for (auto i = verticesList.begin(); i != verticesList.end(); ++i) {
        if (*V == **i) {
            verticesList.erase(i);
            break;
        }
    }
}

template<typename G>
void GraphADT<G>::insertEdge(ObjectVertex<G> v1, ObjectVertex<G> v2, ObjectEdge<G> e) {
    e.addVertex(v1);
    e.addVertex(v2);
    edgesList.push_back(e);
    v1.addIncidientEdge(e);
    v2.addIncidientEdge(e);
    //std::cout <<"A edge, with label " << *e << ", has been inserted between " << *v1 << " and " << *v2 <<".\n";
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

