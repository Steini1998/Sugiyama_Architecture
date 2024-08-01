#pragma once

#include "LEDA/graph/graph.h"
#include "LEDA/geo/point.h"


namespace sugi {

	class sugiyama; // Forward declaration
	
	class step {		
	public:

		void setSugiyama(sugiyama*);

		leda::graph& getGraph();

		leda::node_array<leda::point>& getPositions();

		void make(); // Template method

		virtual void run() = 0;

		void takeSnapshot();

	protected:
		sugiyama* m_sugiyama;

		/* Copied Snapshots of the current (original) state. */
		leda::graph m_graph;
		leda::node_array<leda::point> m_positions;

		leda::node_array<leda::point> mapPositions(const leda::graph&, const leda::graph&, const leda::node_map<leda::point>&);
		
	};
	
}