#pragma once

#include "LEDA/graph/graph.h"
#include "LEDA/geo/point.h"


namespace sugi {

	class sugiyama; // Forward declaration
	
	class step {		
	public:

		void setSugiyama(sugiyama*);

		leda::graph& getGraph();

		void setGraph(leda::graph);

		leda::node_array<leda::point>& getPositions();

		virtual void run() = 0;

	protected:
		sugiyama* m_sugiyama;

	private:
		leda::graph m_graph;
		leda::node_array<leda::point> m_positions;

		void setPositions();

	};
	
}