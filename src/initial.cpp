#include <iostream>

#include "LEDA/geo/point.h"

#include "SUGIPROJ/steps/initial.h"

using namespace sugi;


void initial::run() {
    this->getSugiyama().getGraphWin().new_node(leda::point(5, 10));
    this->getSugiyama().getGraphWin().update_nodes();
    std::cout << "oke" << std::endl;
    std::cout << this->getGraph().number_of_nodes() << std::endl;
}