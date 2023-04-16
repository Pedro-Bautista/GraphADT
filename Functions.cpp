//
// Created by moren on 4/10/2023.
//

#include "Functions.h"
#include "GraphADT.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

//Find edges incident on a vertex
void findEdgesMenu(GraphADT<std::string> graph){
    std::string label;
    std::cout <<"Please provide the label of the of the vertex you are looking for: ";
    std::cin >> label;
}

//Find a path in the graph
void findPathMenu(GraphADT<std::string> graph){
    std::string label1, label2;
    std::cout <<"Please provide the label of the first vertex you are looking for";
    std::cin >> label1;
    std::cout <<"Please provide the label of the second vertex you are looking for";
    std::cin >> label2;
}

//Insert an edge
GraphADT<std::string> insertEdgeMenu(GraphADT<std::string> graph) {
    std::string label1, label2, newEdgeString;

    //gets user input
    std::cout <<"Please provide the label of the first vertex you want to add in-between of";
    std::cin >> label1;
    std::cout <<"Please provide the label of the second vertex you want to add in-between of";
    std::cin >> label2;
    std::cout <<"Please provide the label of the new edge you want to add";
    std::cin >> newEdgeString;
    ObjectEdge<std::string> newEdge;
    *newEdge = newEdgeString;
    ObjectVertex<std::string> label1Vertex;
    *label1Vertex = label1;
    ObjectVertex<std::string> label2Vertex;
    *label1Vertex = label2;

    //checks if vertices are already in the list
    bool existanceOfVertexAlreadyInGraph;
    std::list<ObjectVertex<std::string>> vertices = graph.vertices();
    std::list<ObjectVertex<std::string>>::iterator i;
    for (i = vertices.begin(); i != vertices.end(); ++i) {
        if (*(*i) == *label1Vertex || *(*i) == *label2Vertex) {
            existanceOfVertexAlreadyInGraph = true;
        }
    }
    if (existanceOfVertexAlreadyInGraph) {
        std::cout <<"Edge insert failed: vertices do not exit" << std::endl;
        return graph;
    }

    //checks if edge is already in the list
    std::list<ObjectEdge<std::string>> edges = graph.edges();
    std::list<ObjectEdge<std::string>>::iterator j;
    for (j = edges.begin(); j != edges.end(); ++j) {
        if (*(*j) == *newEdge) {
            std::cout <<"Edge insert failed: edge already exit" << std::endl;
            return graph;
        }
    }

    //inserts new edge
    graph.insertEdge(label1Vertex, label2Vertex, newEdge);
    std::cout <<"Edge inserted successfully (hopefully)" << std::endl;

}

//Erase a vertex
GraphADT<std::string> ereaseVertexMenu(GraphADT<std::string> graph) {
    std::string vertexToBeRemoved;
    std::cout <<"Please provide the label of the vertex you want to remove";
    std::cin >> vertexToBeRemoved;
    ObjectVertex<std::string> newVertex;
    *newVertex = vertexToBeRemoved;
    graph.eraseVertex(newVertex);
    std::cout <<"Vertex has been removed" << std::endl;
    return graph;
}


//builds a vector of a based on the file
std::vector<contents> readFromFile(const std::string& filename) {
    //creates the vector to store the information
    std::vector<contents> list;
    //buffer to store the input from readfile function
    std::string buffer;
    std::string Contents;
    std::ifstream infile;
    infile.open(filename);
    if (infile.is_open()) {
        while (std::getline(infile, buffer)) {
            std::vector<std::string> row;
            std::stringstream temp(buffer);
            while (std::getline(temp, Contents, '\t')) {
                row.push_back(Contents);
            }

            //saves the different strings into a new contents structure
            contents new_struct;
            element_struct new_string_struct;
            if (row.empty()) {
                continue;
            }
            new_struct.edgeLabel = std::stoi(row[2]);
            new_struct.strings.endOfVertices = (row[1]);
            new_struct.strings.listofVertices = (row[0]);

            //adds strut into the vector
            list.push_back(new_struct);


        }
        infile.close();
    } else {
        std::cout << "Unable to open File! Try again later.\n";
    }


    return list;
}