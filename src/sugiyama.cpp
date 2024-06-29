#include "LEDA/graph/graph.h"
#include "LEDA/graphics/panel.h"

#include "SUGIPROJ/sugiyama.h"
#include "SUGIPROJ/steps/initial.h"

using namespace sugi;


sugiyama::sugiyama(leda::GraphWin& gw) : m_graphwin { gw } {
	step* initial_step = new initial {};
	initial_step->setGraph(gw.get_graph());
	this->add(initial_step);
}

void sugiyama::add(step* s) {
	m_steps.push_back(s);
}

void sugiyama::remove(step* s) {
	m_steps.remove(s);
}

void sugiyama::executeAll() {
	leda::graph current_graph = m_steps.head()->getGraph();
	for (step* s : m_steps) {
		s->setGraph(current_graph);
		s->run();
		current_graph = s->getGraph();
	}
}

void sugiyama::view() {
	// Running all steps. Each step saves its result graph.
	this->executeAll();
	
	m_current_step_item = m_steps.first();

	leda::panel steps_process_panel("Steps");
	steps_process_panel.button("Stop", 0);
	steps_process_panel.button("Move Step Forward", 1);
	steps_process_panel.button("Move Step Backward", 2);

	bool still_active = true;

	while (still_active) {
		switch (m_graphwin.open_panel(steps_process_panel)) {
			case 0: 
				still_active = false;
				break;
			case 1:
				this->moveStepForward();
				break;
			case 2:
				this->moveStepBackward();
				break;
		}
	}
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