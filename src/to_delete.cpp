#include <stdio.h>

#include "LEDA/geo/point.h"
#include "LEDA/graphics/graphwin.h"
#include "LEDA/graph/graph.h"

using namespace leda;



void printPositions(leda::node_array<leda::point> positions) {    
    leda::node n;
    leda::point p;
    forall_nodes(n, positions.get_graph()) {
        p = positions[n];
        std::cout << p.X() << " - " << p.Y() << std::endl;
    }
}

int main() {

    // g is the input graph (with 3 nodes)
    leda::graph g{};
    leda::node n1 = g.new_node();
    leda::node n2 = g.new_node();
    leda::node n3 = g.new_node();

    leda::node_map<leda::point> positions{g};
    positions[n1] = leda::point(45, 20);
    positions[n2] = leda::point(90, 90);
    positions[n3] = leda::point(270, 100);

    // positions_input should be a static copy
    leda::node_array<leda::point> positions_input = 
        static_cast<leda::node_array<leda::point>>(positions);

    printPositions(positions);
    printPositions(positions_input);

    leda::node n4 = g.new_node();

    printPositions(positions);
    printPositions(positions_input); // unfortunately still uses same graph

    /* Passed graph (holding static)

    leda::graph passed_graph {g};
    leda::node_array<leda::point> passed_positions {g};
    gw.get_position(passed_positions);

    // Now changes
    leda::node n3 = g.new_node();


    positions[n] = leda::point(25, 50);

    leda::graph g2{g};

    positions = leda::node_map<leda::point>{g2};
    leda::node n2 = g2.new_node();

    positions[n] = leda::point(25, 50);
    positions[n2] = leda::point(32, 67);
    
    gw.display();
    gw.edit(); */
}

int main_old() {
    GraphWin gw {"Testing"};
    gw.display();

    graph g{};

    /* node_array will not be updated automatically, but node_map will */
    // leda::node_array<leda::point> positions;
    leda::node_map<leda::point> positions;

    node v;

	while (gw.edit()) {
		g = gw.get_graph();
        // positions = node_array<leda::point>(g);
        positions = node_map<leda::point>(g);

        gw.get_position(positions);

        v = g.new_node();
        positions[v] = leda::point(45, 50);

        node w;
        leda::point p;
        forall_nodes(w, g) {
            p = positions[w];
            std::cout << p.X() << " - " << p.Y() << std::endl;
        }

        gw.set_graph(g);
        gw.set_position(positions);
        gw.update_graph();
	}
    
    return 0;
}