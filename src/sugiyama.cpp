#include "LEDA/graph/graph.h"
#include "LEDA/graphics/panel.h"

#include "SUGIPROJ/sugiyama.h"
#include "SUGIPROJ/steps/input.h"

using namespace sugi;


sugiyama::sugiyama(leda::GraphWin& gw) 
	: m_graphwin{gw}, m_graph{gw.get_graph()} {
		m_positions = leda::node_map<leda::point>{m_graph};
		m_graphwin.get_position(m_positions);
		this->add(new input{});
}

void sugiyama::add(step* s) {
	s->setSugiyama(this);
	m_steps.push_back(s);
}

void sugiyama::remove(step* s) {
	m_steps.remove(s);
}

void sugiyama::process() {
	for (step* s : m_steps) {
		s->make();
	}
}

void sugiyama::view() {	
	m_current_step_item = m_steps.first();

	// TODO: Input needs to be separated from sugiyama-class.
	leda::panel steps_process_panel("Steps");
	steps_process_panel.button("Stop", 0);
	steps_process_panel.button("Move Step Forward", 1);
	steps_process_panel.button("Move Step Backward", 2);

	bool still_active = true;

	while (still_active) {
		switch (m_graphwin.open_panel(steps_process_panel)) {
			case 0: 
				still_active = false;
				m_current_step_item = m_steps.first();
				break;
			case 1:
				this->moveStepForward();
				break;
			case 2:
				this->moveStepBackward();
				break;
		}
		this->viewCurrentGraph();
	}
}

leda::graph& sugiyama::getGraph() {
    return m_graph;
}

leda::node_map<leda::point>& sugiyama::getPositions() {
    return m_positions;
}

void sugiyama::viewCurrentGraph() {
	step* current_step = m_steps[m_current_step_item];
	m_graphwin.set_graph(current_step->getGraph());
	m_graphwin.set_position(current_step->getPositions());
	m_graphwin.update_graph();
}

void sugiyama::moveStepBackward() {
	if (m_current_step_item == m_steps.first_item()) {
		return;
	}
	m_current_step_item = m_current_step_item->get_pred();
	return;
}

void sugiyama::moveStepForward() {
	if (m_current_step_item == m_steps.last_item()) {
		return;
	}
	m_current_step_item = m_current_step_item->get_succ();
	return;
}