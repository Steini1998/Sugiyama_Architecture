#include "LEDA/graph/graph.h"
#include "SUGIPROJ/sugiyama.h"

using namespace sugi;


void sugiyama::add(step* s) {
	m_steps.push(s);
}

void sugiyama::remove(step* s) {
	m_steps.remove(s);
}

void sugiyama::run() {
	leda::graph current_graph { m_graphwin.get_graph() };
	for (step* s : m_steps) {
		s->setGraph(current_graph);
		s->go();
		current_graph = s->getProcessedGraph();
	}
}