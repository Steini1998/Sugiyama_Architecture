#pragma once

#include "LEDA/graph/graph.h"


namespace sugi {
	
	class step {		
	public:

		leda::graph getGraph() const {
			return m_graph;
		}

		void setGraph(leda::graph g) {
			m_graph = g;
		}

		virtual void run() = 0;

	private:
		leda::graph m_graph;

	};
	
}