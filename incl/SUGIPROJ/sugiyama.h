#include "LEDA/graphics/graphwin.h"
#include "LEDA/core/list.h"

#include "SUGIPROJ/steps/step.h"


namespace sugi {
	
	class sugiyama {		
	public:
		sugiyama(leda::GraphWin& gw) : 
			m_graphwin { gw }, m_initial_graph { gw.get_graph() }
			{}

		void add(sugi::step*);
		void remove(sugi::step*);

		void run(); // runs all steps (with control)

	private:
		leda::GraphWin& m_graphwin;
		leda::graph m_initial_graph;

		leda::graph m_current_graph;
		leda::list<sugi::step*> m_steps;
		leda::list_item m_current_step_item;

		void process(); // runs one step
		void unprocess(); // runs back one step

		sugi::step* getCurrentStep() const;

		bool moveStepBackward();
		bool moveStepForward();
	
	};
	
}