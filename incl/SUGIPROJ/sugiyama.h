#pragma once

#include "LEDA/graphics/graphwin.h"
#include "LEDA/core/list.h"

#include "SUGIPROJ/steps/step.h"


namespace sugi {
	
	class sugiyama {		
	public:
		sugiyama(leda::GraphWin&);

		leda::GraphWin& getGraphWin() const;

		void add(step*);
		void remove(step*);

		void view(); // call executeAll() and iterating over graphs

	private:
		leda::GraphWin& m_graphwin;

		leda::list<step*> m_steps;
		leda::list_item m_current_step_item;

		void executeAll(); // runs all steps and creates all intermediate results

		void viewCurrentGraph();

		void moveStepBackward();
		void moveStepForward();
	
	};
	
}