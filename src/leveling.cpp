#include <iostream>

#include "SUGIPROJ/steps/leveling.h"

using namespace sugi;


void leveling::go() {
    std::cout << "oke" << std::endl;
    std::cout << this->getGraph().number_of_nodes() << std::endl;
}