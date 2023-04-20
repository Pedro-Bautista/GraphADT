//
// Created by Kenneth Verzyl and Pedro Bautista on 4/10/2023.
//

#include <iostream>
#include <vector>
#include "GraphADT.h"
#include "Functions.h"



int main() {
    consolePrinting();
    GraphADT<std::string> graph;
    std::string filename = "input.txt";
    std::vector<contents> list;
    list= readFromFile(filename);
    graph = graphMaker(list);
    return EXIT_SUCCESS;
}
