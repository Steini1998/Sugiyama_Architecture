#include <SUGIPROJ/positionable_graph.h>


using namespace sugi;


void positionable_graph::takeSnapshot(const leda::graph& g, const leda::node_map<leda::point>& pos) {
	m_graph = g;  // create copy from graph
	m_positions = leda::node_array<leda::point>{m_graph};
	mapPositions(g, pos);
}

void positionable_graph::show(leda::GraphWin& gw) {
	gw.set_graph(m_graph);
	gw.set_position(m_positions);
	gw.update_graph();
}

void positionable_graph::mapPositions(const leda::graph& old_graph, const leda::node_map<leda::point>& old_positions) {
	leda::list<leda::node> old_nodes = old_graph.all_nodes();
	leda::list<leda::node> new_nodes = m_graph.all_nodes();

	for (int node_pos = 0; node_pos < old_nodes.length(); node_pos++) {
		leda::list_item li_node_old = old_nodes.get_item(node_pos);
		leda::list_item li_node_new = new_nodes.get_item(node_pos);

		leda::node old_node = old_nodes[li_node_old];
		leda::node new_node = new_nodes[li_node_new];

		leda::point node_position_old = old_positions[old_node];
		m_positions[new_node] = leda::point{node_position_old.X(), node_position_old.Y()};
	}
}