#pragma once

#include "LEDA/graphics/graphwin.h"
#include "LEDA/core/list.h"

#include "SUGIPROJ/steps/step.h"


namespace sugi {
	
	class sugiyama {

		// friend class step; // step-objects can access all fields and functions from connected sugiyama-object

	public:
		sugiyama(leda::GraphWin&);

		void add(step*);
		void remove(step*);

		void process(); // run all steps sequential
		void view(); // iterate over intermediate solutions

		leda::graph& getGraph();
		leda::node_map<leda::point>& getPositions();

	private:
		leda::GraphWin& m_graphwin;

		/* Same graph and positions will be processed by steps. */
		leda::graph& m_graph;
		leda::node_map<leda::point> m_positions;

		leda::list<step*> m_steps;
		leda::list_item m_current_step_item;

		void viewCurrentGraph();

		void moveStepBackward();
		void moveStepForward();
	
	};
	
}