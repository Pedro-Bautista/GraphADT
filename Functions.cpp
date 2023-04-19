//
// Created by moren on 4/10/2023.
//

#include "Functions.h"
#include "GraphADT.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

const std::string WHITESPACE = " \r";

//prints user interface
void consolePrinting() {
    GraphADT<std::string> graph;
    std::vector<contents> list;
    std::string filename;

    std::cout <<"Hello!\n";
    std::cout <<"Enter the file name: ";
    std::cin >> filename;

    //creates graph
    list = readFromFile(filename);
    graph = graphMaker(list);

    std::cout <<"Thank you. Your graph is ready";

    int input;
    do {
        std::cout <<"\n--------------\nWhat would you like to do?\n--------------\n";
        std::cout <<"1. Find edges incident on a vertex\n"
                    "2. Find a path in the graph\n"
                    "3. Insert an edge\n"
                    "4. Erase a vertex\n"
                    "5. Exit\n"
                    "Input:\t";
        std::cin >> input;
        switch (input) {
            case 1: findEdgesMenu(graph);
                break;
            case 2: findPathMenu(graph);
                break;
            case 3:
                graph = insertEdgeMenu(graph);
                break;
            case 4:
                graph = ereaseVertexMenu(graph);
                break;
            case 5:
                return;
                break;
            case 6:
                printVectors(graph);
                break;
        }
    } while (input != 5);


}

//prints all vectors
void printVectors(const GraphADT<std::string> &graph) {
    std::list<ObjectVertex<std::string>> verticesList = graph.vertices();
    std::cout << "The list of vertices are: \t" << std::endl;
    for (std::list<ObjectVertex<std::string>>::iterator i = verticesList.begin(); i != verticesList.end(); ++i) {
        std::cout << "|" << **i << "|\t\t" << std::endl;
    }
    std::cout << "End of List" << std::endl;

}

//Find edges incident on a vertex
void findEdgesMenu(const GraphADT<std::string> &graph) {
    std::string label;
    std::cout << "Please provide the label of the of the vertex you are looking for: ";
    getline(std::cin, label);
    std::cout <<"You are looking for |" << label << "|. Coming right up..." << std::endl;

    //for loop to search for the vertex using an iterator
    ObjectVertex<std::string> vertex;
    std::list<ObjectVertex<std::string>> vertices = graph.vertices();
    std::list<ObjectVertex<std::string>>::iterator i;
    for (i = vertices.begin(); i != vertices.end(); ++i) {
        if (*(*i) == label) {
            break;
        }
    }
    vertex = (*i);

    //loops edge list to see if vertex is an incident on a given edge, and then prints results
    std::list<ObjectEdge<std::string>> edgeList = graph.getEdgesList();
    std::list<ObjectEdge<std::string>>::iterator j;
    for (j = edgeList.begin(); j != edgeList.end(); ++j) {
        std::list<ObjectVertex<std::string>> incidents = j->incidentList;
        std::list<ObjectVertex<std::string>>::iterator k;
        if ((*j).isAdjacentTo(vertex)) {
            //std::cout << *vertex << "\t|\t" << **j;
            std::cout << *(*j->endVertices().begin()) << " is " << **j <<" to " <<  *(*j->endVertices().begin().operator++()) << std::endl;
        }
    }


}

//Find a path in the graph
void findPathMenu(GraphADT<std::string> graph) {
    std::string label1, label2;
    std::cout << "Please provide the label of the first vertex you are looking for\t";
    getline(std::cin, label1);
    std::cout << "Please provide the label of the second vertex you are looking for\t";
    getline(std::cin ,label2);
    std::cout << "You are looking for a path between |" << label1 <<"| and |" << label2 << "|. Coming right up..." << std::endl;

    //for loop to search for the first vertex using an iterator
    ObjectVertex<std::string> firstVertex;
    std::list<ObjectVertex<std::string>> vertices = graph.vertices();
    std::list<ObjectVertex<std::string>>::iterator i;
    for (i = vertices.begin(); i != vertices.end(); ++i) {
        if (*(*i) == label1) {
            break;
        }
    }
    firstVertex = (*i);


    //for loop to search for the second vertex using an iterator
    ObjectVertex<std::string> secondVertex;
    for (i = vertices.begin(); i != vertices.end(); ++i) {
        if (*(*i) == label2) {
            break;
        }
    }
    secondVertex = (*i);

    //loops edge list to see if vertex is an incident on a given edge, and if that vertex is an incident on the desired vector.
    std::list<ObjectEdge<std::string>> edgeList = graph.getEdgesList();
    std::list<ObjectEdge<std::string>>::iterator j;
    for (j = edgeList.begin(); j != edgeList.end(); ++j) {
        std::list<ObjectVertex<std::string>> incidents = j->incidentList;
        std::list<ObjectVertex<std::string>>::iterator k;
        if ((*j).isAdjacentTo(firstVertex)) {
            if (*(*j->endVertices().begin()) != *firstVertex) {
                //std::cout << *(*j->endVertices().begin());
                graph.isAdjacent(firstVertex,secondVertex);
                //if ((*j->endVertices().begin()).isAdjacentTo(secondVertex))
                    std::cout <<"The path is " << *firstVertex << " to " << *(*j->endVertices().begin()) << " to " << *secondVertex << std::endl;
            }
            if (*(*j->endVertices().begin().operator++()) != *firstVertex) {
                //std::cout <<*(*j->endVertices().begin().operator++());
                //if ((*j->endVertices().begin().operator++()).isAdjacentTo(secondVertex))
                    std::cout <<"The path is " << *firstVertex << " to " << *(*j->endVertices().begin().operator++()) << " to " << *secondVertex << std::endl;
            }
        }
    }



}

//Insert an edge
GraphADT<std::string> insertEdgeMenu(GraphADT<std::string> graph) {
    std::string label1, label2, newEdgeString;

    //gets user input
    std::cout << "Please provide the label of the first vertex you are looking for\t";
    getline(std::cin, label1);
    std::cout << "Please provide the label of the second vertex you are looking for\t";
    getline(std::cin ,label2);
    std::cout << "Please provide the label of the new edge you want to add (ex. \"0.27 m\")\t";
    getline(std::cin ,newEdgeString);

    //for loop to search for the label1 vertex using an iterator
    ObjectVertex<std::string> label1Vertex;
    std::list<ObjectVertex<std::string>> vertices = graph.vertices();
    std::list<ObjectVertex<std::string>>::iterator i;
    bool label1VertexExist = 0;
    for (i = vertices.begin(); i != vertices.end(); ++i) {
        if (*(*i) == label1) {
            label1VertexExist = 1;
            break;
        }
    }
    if (label1VertexExist)
    label1Vertex = (*i);

    //for loop to search for the label2 vertex using an iterator
    bool label2VertexExist = 0;
    ObjectVertex<std::string> label2Vertex;
    for (i = vertices.begin(); i != vertices.end(); ++i) {
        if (*(*i) == label2) {
            label2VertexExist = 1;
            break;
        }
    }

    if (label2VertexExist)
    label2Vertex = (*i);


    //checks if vertices are in the list
    if (!(label1VertexExist && label2VertexExist)) {
        std::cout << "Edge insert failed: vertices do not exit" << std::endl;
        return graph;
    }


    std::cout << *(*label1Vertex.incidentEdges().begin());
    std::cout << *(*label2Vertex.incidentEdges().begin());


    //loops edge list to see if the two vertices already have an edge that the user inputted
    std::list<ObjectEdge<std::string>> edgeList = graph.getEdgesList();
    std::list<ObjectEdge<std::string>>::iterator j;
    for (j = edgeList.begin(); j != edgeList.end(); ++j) {
        std::list<ObjectVertex<std::string>> incidents = j->incidentList;
        std::list<ObjectVertex<std::string>>::iterator k;
        if ((*j).isAdjacentTo(label1Vertex)) {
            if (*(*j->endVertices().begin()) == *label2Vertex || *(*j->endVertices().begin().operator++()) == *label2Vertex) {
                std::cout << "|" << **j <<"|\n";
                std::cout << "|" << newEdgeString <<"|\n";
                if (**j == newEdgeString) {
                    std::cout << "Edge insertion failed: There is already an edge between these two vertices"
                              << std::endl;
                    return graph;
                }
            }
        }
    }
    
    //inserts new edge
    ObjectEdge<std::string> newEdge = *new ObjectEdge<std::string>(newEdgeString);
    graph.insertEdge(label1Vertex, label2Vertex, newEdge);
    std::cout << "Edge inserted successfully " << std::endl;
    return graph;
}

//Erase a vertex
GraphADT<std::string> ereaseVertexMenu(GraphADT<std::string> graph) {
    std::string vertexToBeRemovedString;
    std::cout << "Please provide the label of the vertex you want to remove\t";
    getline(std::cin, vertexToBeRemovedString);


    //for loop to search for the vertex using an iterator
    bool doesVertexExist = 0;
    ObjectVertex<std::string> vertex;
    std::list<ObjectVertex<std::string>> vertices = graph.vertices();
    std::list<ObjectVertex<std::string>>::iterator i;
    for (i = vertices.begin(); i != vertices.end(); ++i) {
        if (*(*i) == vertexToBeRemovedString) {
            doesVertexExist = 1;
            break;
        }
    }

    if (doesVertexExist == 0) {
        std::cout <<"There is not a vertex with that label in this graph" << std::endl;
        return graph;
    }
    vertex = (*i);

    graph.eraseVertex(vertex);
    std::cout << "Vertex has been removed, as well as any edges that point to it" << std::endl;
    printVectors(graph);
    return graph;
}


//builds a vector of a based on the file
std::vector<contents> readFromFile(const std::string &filename) {
    //creates the vector to store the information
    std::vector<contents> list;
    //buffer to store the input from readfile function
    std::string buffer;
    std::string Contents;
    std::ifstream infile;
    infile.open(filename);
    //allows us to skip first line.
    bool first_time = true;
    if (infile.is_open()) {
        while (std::getline(infile, buffer)) {
            //saves the different strings into a new contents structure
            contents new_struct;
            element_struct new_string_struct;
            std::vector<std::string> row;
            std::stringstream temp(buffer);

            if (first_time) {
                first_time = false;
                while (std::getline(temp, Contents, ',')) {
                    new_struct.strings.TotalVerticies.push_back(Contents);
                    //std::cout << new_struct.strings.TotalVerticies.back() << std::endl;
                }
                list.push_back(new_struct);
                continue;
            }
            while (std::getline(temp, Contents, '\t')) {
                row.push_back(Contents);
            }
            if (row.empty()) {
                continue;
            }
            new_struct.strings.firstVertex = (row[0]);
            //std::cout << std::endl << new_struct.strings.firstVertex;

            new_struct.strings.secondVertex = (row[1]);
            //std::cout << " " << new_struct.strings.secondVertex << " ";

            new_struct.edgeLabel = (row[2]);
            //std::cout << new_struct.edgeLabel;



            //adds strut into the vector
            list.push_back(new_struct);


        }
        infile.close();
    } else {
        std::cout << "Unable to open File! Try again later.\n";
    }
    std::cout << std::endl << std::endl;
    return list;
}

//removes white spaces before and after the nonwhitespace characters
std::string removeWhiteSpaceBeforeAndAfter(std::string input) {
    int firstNonWhitespaceCharacter = input.find_first_not_of(WHITESPACE);
    int lastNonWhitespaceCharacter = input.find_last_not_of(WHITESPACE);
    if (firstNonWhitespaceCharacter == std::string::npos) {
        firstNonWhitespaceCharacter = 0;
    }
    if (lastNonWhitespaceCharacter == std::string::npos || input.substr(input.length() - 1) == "s") {
        lastNonWhitespaceCharacter = input.length();
    }
    //std::cout << "firstNonWhitespaceCharacter: " << firstNonWhitespaceCharacter << " lastNonWhite
    return input.substr(firstNonWhitespaceCharacter, lastNonWhitespaceCharacter);


}

GraphADT<std::string> graphMaker(const std::vector<contents> &contentsList) {


    GraphADT<std::string> graph;
    for (int i = 0; i < contentsList.front().strings.TotalVerticies.size(); i++) {


        //std::cout<<contentsList.front().strings.TotalVerticies[i];



        ObjectVertex<std::string> newVertex = *new ObjectVertex<std::string>(
                removeWhiteSpaceBeforeAndAfter(contentsList.front().strings.TotalVerticies[i]));
        graph.insertVertex(newVertex);
    }
    for (int i = 0; i < contentsList.size(); i++) {
        if (!contentsList[i].edgeLabel.empty()) {

            ObjectVertex<std::string> firstVertex;
            ObjectVertex<std::string> secondVertex;

            //for loop to iterate through the list of vertices to find a match and qual it to the ObjectVertex above
            std::list<ObjectVertex<std::string>>::iterator j;
            std::list<ObjectVertex<std::string>> vertices = graph.vertices();
            for (j = vertices.begin(); j != vertices.end(); ++j) {
                if (*(*j) == (contentsList[i].strings.secondVertex)) {
                    firstVertex = *j;
                }
                if (*(*j) == (contentsList[i].strings.firstVertex)) {
                    secondVertex = *j;
                }
            }

            //inserts edge between the 2 vertices
            graph.insertEdge(firstVertex, secondVertex,
                             *new ObjectEdge<std::string>(removeWhiteSpaceBeforeAndAfter(contentsList[i].edgeLabel)));

        }
    }


    return graph;
}
