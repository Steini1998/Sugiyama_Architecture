#pragma once

#include <LEDA/graph/graph.h>


namespace sugi {
	
	class step {		
	public:
		step() = default;

		leda::graph getGraph() const {
			return m_graph;
		}

		void setGraph(leda::graph g) {
			m_graph = g;
		}

		virtual void go() = 0;

	private:
		leda::graph m_graph;

	};
	
}