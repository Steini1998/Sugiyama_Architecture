#include "SUGIPROJ/sugiyama.h"

using namespace sugi;

void step::setSugiyama(sugiyama* sg) {
    m_sugiyama = sg;
} 

leda::graph& step::getGraph() {
    return m_graph;
}

leda::node_array<leda::point>& step::getPositions() {
    return m_positions;
}

void step::make() {
    run();
    takeSnapshot();
}

void step::takeSnapshot() {
    m_graph = m_sugiyama->getGraph(); // creates a copy
    m_positions = mapPositions(m_graph, m_sugiyama->getGraph(), m_sugiyama->getPositions());
}

leda::node_array<leda::point> step::mapPositions(const leda::graph& new_graph, const leda::graph& old_graph, const leda::node_map<leda::point>& old_positions) {
    leda::node_array<leda::point> new_positions{new_graph};
    
    leda::list<leda::node> old_nodes = old_graph.all_nodes();
    leda::list<leda::node> new_nodes = new_graph.all_nodes();

    for (int node_pos = 0; node_pos < old_nodes.length(); node_pos++) {
        leda::list_item li_node_old = old_nodes.get_item(node_pos);
        leda::list_item li_node_new = new_nodes.get_item(node_pos);

        leda::node old_node = old_nodes[li_node_old];
        leda::node new_node = new_nodes[li_node_new];

        leda::point node_position_old = old_positions[old_node];
        new_positions[new_node] = leda::point(node_position_old.X(), node_position_old.Y());
    }
    return new_positions;
}