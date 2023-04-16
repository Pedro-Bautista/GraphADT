//
// Created by moren on 4/10/2023.
//

#include <iostream>
#include <map>

int main() {
    std::map<std::string,int> products{{"Hammer",14},{"Nails",25},{"Wrench",8}};
    products.insert("Wrench",18);
    products.insert("wrench",18);
    int quantity=products{"drill"};
    return EXIT_SUCCESS;
}
