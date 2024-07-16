#include <iostream>

#include "LEDA/graphics/graphwin.h"
#include "LEDA/geo/point.h"

#include "SUGIPROJ/sugiyama.h"
#include "SUGIPROJ/steps/cycle_breaking.h"

using namespace sugi;


void cycle_breaking::run() {
    std::cout << "Cycle-Breaking" << std::endl;

    leda::node n = m_graph.new_node();
    m_positions[n] = leda::point(5, 7);

    std::cout << m_graph.number_of_nodes() << std::endl;
}


leda::graph GreedyMakeAcyclic(leda::graph g) {
	
}


int main() {
	GraphWin gw {"Cycle-Breaking"};
	gw.display();
	
	while (gw.edit()) {
	
	}
	
	return 0;
}