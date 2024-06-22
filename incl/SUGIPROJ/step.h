#pragma once

#include <LEDA/graph/graph.h>


namespace sugi {
	
	class step {
	protected:
		leda::graph m_received_graph;
		leda::graph m_processed_graph;
		
	public:
		step() = default;

		void setGraph(leda::graph g) {
			m_received_graph = g;
		}

		leda::graph getReceivedGraph() const {
			return m_received_graph;
		}

		leda::graph getProcessedGraph() const {
			return m_processed_graph;
		}

		virtual void go() = 0;

	};
	
}