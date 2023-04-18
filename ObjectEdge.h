//
// Created by Ken V on 4/16/23.
//

#ifndef GRAPHADT_OBJECTEDGE_H
#define GRAPHADT_OBJECTEDGE_H
#include "ObjectVertex.h"

template<typename G>
class ObjectEdge{
public:
    G value;
    std::list<ObjectVertex<G>> incidentList;
    explicit ObjectEdge(G value) : value(value) {}

    ObjectEdge() {}

public:
    //returns the element of the label
    G operator*();

    //add Vertex to edge
    void addVertex(ObjectVertex<G> v) {
        incidentList.push_back(v);
    }

    //returns the vertex list of the edges ends
    std::list<ObjectVertex<G>> endVertices();

    //returns the end vertex of the edge distinct from V
    ObjectVertex<G> opposite(ObjectVertex<G> V);

    //test whether this edge and f are adjacent
    bool isAdjacentTo(ObjectEdge<G> f);

    //test whether edge is incident on v
    bool IsIncidentOn(ObjectVertex<G> V);

    friend class ObjectVertex<G>;
};

template<typename G>
std::list<ObjectVertex<G>> ObjectEdge<G>::endVertices() {
    //TO BE COMPLETED
    return std::list<ObjectVertex<G>>();
}

template<typename G>
bool ObjectEdge<G>::IsIncidentOn(ObjectVertex <G> V) {
    for (auto i = incidentList.begin(); i != incidentList.end(); ++i) {
        if (*i == V) {
            return true;
        } else return false;
    }
    return false;
}

template<typename G>
bool ObjectEdge<G>::isAdjacentTo(ObjectEdge<G> f) {
    for
    return false;
}

template<typename G>
ObjectVertex<G> ObjectEdge<G>::opposite(ObjectVertex<G> V) {
    //TO BE COMPLETED
    return ObjectVertex<G>();
}

template<typename G>
G ObjectEdge<G>::operator*() {
    return value;
}

#endif //GRAPHADT_OBJECTEDGE_H
