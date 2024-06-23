#include "LEDA/graph/graph.h"
#include "SUGIPROJ/sugiyama.h"

using namespace sugi;


void sugiyama::add(step* s) {
	m_steps.push_back(s);
}

void sugiyama::remove(step* s) {
	m_steps.remove(s);
}

void sugiyama::run() {
	m_current_graph = m_initial_graph;
	m_current_step_item = m_steps.first();
	this->process();
	this->process();
}

void sugiyama::process() {
	step* step_to_be_executed = this->getCurrentStep();
	step_to_be_executed->setGraph(m_current_graph);
	step_to_be_executed->go();
	m_current_graph = step_to_be_executed->getGraph();
	moveStepForward();
}

void sugiyama::unprocess() {
	moveStepBackward();
}

sugi::step* sugiyama::getCurrentStep() const {
	return m_steps[m_current_step_item];
}

bool sugiyama::moveStepBackward() {
	if (m_current_step_item == m_steps.first_item()) {
		return false;
	}
	m_current_step_item = m_current_step_item->get_pred();
	return true;
}

bool sugiyama::moveStepForward() {
	if (m_current_step_item == m_steps.last_item()) {
		return false;
	}
	m_current_step_item = m_current_step_item->get_succ();
	return true;
}