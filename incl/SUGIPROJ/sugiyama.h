#pragma once

#include "LEDA/graphics/graphwin.h"
#include "LEDA/core/list.h"

#include "SUGIPROJ/steps/step.h"
#include "SUGIPROJ/views/step_viewer.h"
#include "SUGIPROJ/views/ui.h"

namespace sugi {
	
	class sugiyama {
	public:
		sugiyama(leda::GraphWin&);

		void add(step*);
		void remove(step*);

		void process(); // run all steps sequential
		void show(ui*); // iterate over intermediate solutions

		leda::GraphWin& getGraphWin();
		
		leda::graph& getGraph();
		leda::node_map<leda::point>& getPositions();

		void setStepViewer(const step_viewer&);

	private:
		leda::GraphWin& m_graphwin;

		/* Same graph and positions will be processed by steps. */
		leda::graph& m_graph;
		leda::node_map<leda::point> m_positions;

		leda::list<step*> m_steps;
		step_viewer m_step_viewer;
	
	};
	
}