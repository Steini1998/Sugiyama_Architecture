#include "LEDA/graph/graph.h"
#include "SUGIPROJ/sugiyama.h"

using namespace sugi;


void sugiyama::process() {
	leda::graph current_graph = this->getCurrentGraph();
	s->setGraph(current_graph);
	s->go();
	m_current_step++;
}

void sugiyama::unprocess() {
	m_current_step--;
}


void sugiyama::add(step* s) {
	m_steps.push(s);
}

void sugiyama::remove(step* s) {
	m_steps.remove(s);
}

void sugiyama::run() {
	m_current_step = 0;
	bool should_continue = true;
	while (should_continue) {
		m_current_graph = (true) 
							? this->process() 
							: this->unprocess();		
	}
}

leda::graph sugiyama::getCurrentGraph() const {
	if (m_current_step == 0) 
		return m_initial_graph;
	
	return m_steps.get_item(m_current_step - 1);
}