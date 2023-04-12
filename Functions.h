//
// Created by moren on 4/10/2023.
//

#ifndef GRAPHADT_FUNCTIONS_H
#define GRAPHADT_FUNCTIONS_H
#include <iostream>
#include "GraphADT.h"

struct element_struct {
    std::string listofVertices;
    std::string endOfVertices;
};
struct contents{
    int edgeLabel;
    element_struct strings;
};

void findEdgesMenu(GraphADT<std::string> graph);
void findPathMenu(GraphADT<std::string> graph);
GraphADT<std::string> insertEdgeMenu(GraphADT<std::string> graph);
GraphADT<std::string> ereaseVertexMenu(GraphADT<std::string> graph);


#endif //GRAPHADT_FUNCTIONS_H
