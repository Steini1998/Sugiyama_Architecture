#include <stdio.h>

#include "LEDA/geo/point.h"
#include "LEDA/graphics/graphwin.h"
#include "LEDA/graph/graph.h"

using namespace leda;

int main() {
    GraphWin gw {"Testing"};
    gw.display();

    graph g{};
    leda::node_array<leda::point> positions;

	while (gw.edit()) {
		g = gw.get_graph();
        positions = node_array<leda::point>(g);
        gw.get_position(positions);
        gw.set_graph(g);
        gw.set_position(positions);
        gw.update_graph();
	}
    
    return 0;
}