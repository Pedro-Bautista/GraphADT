//
// Created by moren on 4/10/2023.
//

#include "Functions.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
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
            new_struct.strings.label = row[2];
            new_struct.strings.content = row[3];
            new_struct.order_of_node = std::stoi(row[1]);
            new_struct.level_of_node = std::stoi(row[0]);

            //adds strut into the vector
            list.push_back(new_struct);


        }
        infile.close();
    } else {
        std::cout << "Unable to open File! Try again later.\n";
    }


    return list;
}