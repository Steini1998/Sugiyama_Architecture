#include <iostream>

#include "LEDA/graphics/graphwin.h"
#include "LEDA/geo/point.h"

#include "SUGIPROJ/sugiyama.h"
#include "SUGIPROJ/steps/cycle_breaking.h"

using namespace sugi;


void cycle_breaking::run() {
    std::cout << "Cycle-Breaking" << std::endl;

    leda::graph& g = m_sugiyama->getGraph();
    leda::node_map<leda::point>& pos = m_sugiyama->getPositions();

    leda::node n = g.new_node();
    pos[n] = leda::point(50, 70);

    std::cout << m_graph.number_of_nodes() << std::endl;
}
