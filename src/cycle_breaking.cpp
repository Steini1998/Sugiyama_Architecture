#include <iostream>

#include "SUGIPROJ/steps/cycle_breaking.h"

using namespace sugi;


void cycle_breaking::go() {
    std::cout << "Kara" << std::endl;
    std::cout << this->getGraph().number_of_edges() << std::endl;
}