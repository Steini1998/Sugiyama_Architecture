#include "LEDA/graph/graph.h"

#include "SUGIPROJ/sugiyama.h"

using namespace sugi;


sugiyama::sugiyama(leda::GraphWin& gw) 
	: m_graphwin{gw}, m_graph{gw.get_graph()} {
		m_positions = leda::node_map<leda::point>{m_graph};
		m_graphwin.get_position(m_positions);
}

void sugiyama::add(step* s) {
	s->setSugiyama(this);
	m_steps.push_back(s);
}

void sugiyama::remove(step* s) {
	m_steps.remove(s);
}

void sugiyama::executeAllSteps() {
	for (step* s : m_steps) {
		s->execute();
	}
}

void sugiyama::viewAllSteps() {	
	m_step_viewer.setSteps(m_steps);
	m_step_viewer.view();
}

leda::GraphWin& sugiyama::getGraphWin() {
	return m_graphwin;
}

leda::graph& sugiyama::getGraph() {
    return m_graph;
}

leda::node_map<leda::point>& sugiyama::getPositions() {
    return m_positions;
}

graph_update_tracker& sugiyama::getGraphUpdateTracker() {
	return m_graph_update_tracker;
}

void sugiyama::setStepViewer(const step_viewer& sv) {
	m_step_viewer = sv;
}