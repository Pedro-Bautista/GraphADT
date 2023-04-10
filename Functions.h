//
// Created by moren on 4/10/2023.
//

#ifndef GRAPHADT_FUNCTIONS_H
#define GRAPHADT_FUNCTIONS_H
#include <iostream>
struct element_struct {
    std::string label;
    std::string content;
};
struct contents{
    int level_of_node, order_of_node;
    element_struct strings;
};
loadTree(const std::string& filename);

#endif //GRAPHADT_FUNCTIONS_H
