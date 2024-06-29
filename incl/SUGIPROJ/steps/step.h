#pragma once

#include <LEDA/graph/graph.h>

#include "SUGIPROJ/sugiyama.h"


namespace sugi {
	
	class step {		
	public:
		step() = default;

		sugiyama& getSugiyama() const {
			return m_sugiyama;
		}

		void setSugiyama(sugiyama& sg) {
			m_sugiyama = sg;
		}

		leda::graph getGraph() const {
			return m_graph;
		}

		void setGraph(leda::graph g) {
			m_graph = g;
		}

		virtual void run() = 0;

	private:
		sugiyama& m_sugiyama;

		leda::graph m_graph;

	};
	
}