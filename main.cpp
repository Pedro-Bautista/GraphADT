//
// Created by moren on 4/10/2023.
//

#include <iostream>
#include "GraphADT.h"
#include "functions.h"

void consolePrinting() {
    std::string filename;
    std::cout <<"Hello!";
    std::cout <<"Enter the file name: ";
    std::cin >> filename;
    //create graph object
    GraphADT<std::string> graph;

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
        }
    } while (input != 5);


}

int main() {
    std::cout <<"hello??";
    std::cout<<"WHY??";
    std::cout <<"ladidadi";
    return EXIT_SUCCESS;
}
