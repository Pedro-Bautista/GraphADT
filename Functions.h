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

//Find edges incident on a vertex
void findEdgesMenu(GraphADT<std::string> graph);

//Find a path in the graph
void findPathMenu(GraphADT<std::string> graph);

//Insert an edge
GraphADT<std::string> insertEdgeMenu(GraphADT<std::string> graph);

//Erase a vertex
GraphADT<std::string> ereaseVertexMenu(GraphADT<std::string> graph);

//Reads from the text file and inserts the data into a vector in which every element in a struct
std::vector<contents> readFromFile(const std::string& filename);


#endif //GRAPHADT_FUNCTIONS_H