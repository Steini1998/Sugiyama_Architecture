#include <iostream>

#include "LEDA/graphics/graphwin.h"
#include "LEDA/geo/point.h"

#include "SUGIPROJ/steps/cycle_breaking.h"
#include "SUGIPROJ/sugiyama.h"


using namespace sugi;


void cycle_breaking::run() {
    std::cout << "Cycle-Breaking" << std::endl;

    std::cout << this->getGraph().number_of_edges() << std::endl;
}