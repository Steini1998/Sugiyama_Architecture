#include <iostream>

#include "SUGIPROJ/steps/initial.h"

using namespace sugi;


void initial::run() {
    std::cout << "oke" << std::endl;
    std::cout << this->getGraph().number_of_nodes() << std::endl;
}