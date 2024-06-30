#pragma once

#include "LEDA/graph/graph.h"


namespace sugi {

	class sugiyama; // Forward declaration
	
	class step {		
	public:

		void setSugiyama(sugiyama* sg) {
			m_sugiyama = sg;
		} 

		leda::graph getGraph() const {
			return m_graph;
		}

		void setGraph(leda::graph g) {
			m_graph = g;
		}

		virtual void run() = 0;

	protected:
		sugiyama* m_sugiyama;

	private:
		leda::graph m_graph;

	};
	
}