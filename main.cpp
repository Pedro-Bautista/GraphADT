//
// Created by moren on 4/10/2023.
//

#include <iostream>
#include <vector>
#include "GraphADT.h"
#include "functions.h"

void consolePrinting() {
    GraphADT<std::string> graph;
    std::vector<contents> list;
    std::string filename;

    std::cout <<"Hello!";
    std::cout <<"Enter the file name: ";
    std::cin >> filename;

    //creates graph
    list = readFromFile(filename);


    std::cout <<"Thank you. Your graph is ready";

    int input;
    do {
    std::cout <<"--------------\nWhat would you like to do?\n--------------";
    std::cout <<"1. Find edges incident on a vertex\n"
                "2. Find a path in the graph\n"
                "3. Insert an edge\n"
                "4. Erase a vertex\n"
                "5. Exit";
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
        }
    } while (input != 5);


}

int main() {
    std::cout <<"hello??";
    std::cout<<"WHY??";
    std::cout <<"ladidadi";
    return EXIT_SUCCESS;
}
