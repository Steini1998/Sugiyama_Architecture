#include "LEDA/graphics/graphwin.h"
#include "LEDA/core/list.h"

#include "SUGIPROJ/steps/step.h"


namespace sugi {
	
	class sugiyama {		
	public:
		sugiyama(leda::GraphWin&);

		void add(sugi::step*);
		void remove(sugi::step*);

		void view(); // iterating over graphs

	private:
		leda::GraphWin& m_graphwin;

		leda::list<sugi::step*> m_steps;
		leda::list_item m_current_step_item;

		void executeAll(); // runs all steps

		void moveStepBackward();
		void moveStepForward();
	
	};
	
}