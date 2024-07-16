#pragma once

#include "LEDA/graph/graph.h"
#include "LEDA/geo/point.h"


namespace sugi {

	class sugiyama; // Forward declaration
	
	class step {		
	public:

		void setSugiyama(sugiyama*);

		void setGraph(leda::graph);

		leda::graph getGraph();

		leda::node_map<leda::point> getPositions();

		void setPositions(leda::node_map<leda::point>);

		virtual void run() = 0;

	protected:
		sugiyama* m_sugiyama;

		leda::graph m_graph;
		leda::node_map<leda::point> m_positions;
		
	};
	
}