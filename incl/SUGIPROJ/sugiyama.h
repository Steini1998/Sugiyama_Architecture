#include "LEDA/graphics/graphwin.h"
#include "LEDA/core/list.h"

#include "SUGIPROJ/step.h"


namespace sugi {
	
	class sugiyama {
	private:
		leda::GraphWin& m_graphwin;
		leda::graph m_initial_graph;
		leda::list<sugi::step*> m_steps {};
		int m_current_step = 0;

		void process(); // runs one step
		void unprocess(); // gets back one step
		
	public:
		sugiyama(leda::GraphWin& gw) : 
			m_graphwin { gw }, m_initial_graph { gw.get_graph() }
			{}

		void add(sugi::step*);
		void remove(sugi::step*);

		void run(); // runs all steps (with control)

		leda::graph getCurrentGraph() const;
		
	};
	
}