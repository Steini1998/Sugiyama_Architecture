#pragma once

#include <LEDA/graphics/graphwin.h>

#include <LEDA/graph/graph.h>
#include <LEDA/geo/point.h>


namespace sugi {

	class positionable_graph {
	public:
		positionable_graph() = default;

		void takeSnaphshot(const leda::graph&, const leda::node_map<leda::point>&);

		void show(leda::GraphWin&);

	private:
		leda::graph m_graph;
		leda::node_array<leda::point> m_positions;

		void mapPositions(const leda::graph&, const leda::node_map<leda::point>&);
		
	};

}