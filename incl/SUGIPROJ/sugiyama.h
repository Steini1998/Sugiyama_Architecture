#include "LEDA/graphics/graphwin.h"
#include "LEDA/core/list.h"

#include "SUGIPROJ/step.h"


namespace sugi {
	
	class sugiyama {
	private:
		leda::GraphWin& m_graphwin;
		leda::list<sugi::step*> m_steps;
		
	public:
		sugiyama(leda::GraphWin& gw) : m_graphwin {gw} {}

		void add(sugi::step*);
		void remove(sugi::step*);
		void run();
	};
	
}