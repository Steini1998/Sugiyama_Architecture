#include "LEDA/graph/graph.h"
#include "LEDA/graphics/panel.h"

#include "SUGIPROJ/steps/initial.h"
#include "SUGIPROJ/sugiyama.h"


using namespace sugi;


sugiyama::sugiyama(leda::GraphWin& gw) : m_graphwin { gw } {
	this->add(new initial {});
}

leda::GraphWin& sugiyama::getGraphWin() const {
	return m_graphwin;
}

void sugiyama::add(step* s) {
	s->setSugiyama(this);
	m_steps.push_back(s);
}

void sugiyama::remove(step* s) {
	m_steps.remove(s);
}

void sugiyama::view() {
	// Running all steps. Each step saves its intermediate result graph.
	this->executeAll();

	/* std::cout << "Printing node numbers per step" << std::endl;

	for (step* s : m_steps) {
		std::cout << s->getGraph().number_of_nodes() << std::endl;
	} */
	
	m_current_step_item = m_steps.first();

	// TODO: Input needs to be separated from sugiyama-class.
	leda::panel steps_process_panel("Steps");
	steps_process_panel.button("Stop", 0);
	steps_process_panel.button("Move Step Forward", 1);
	steps_process_panel.button("Move Step Backward", 2);

	bool still_active = true;

	while (still_active) {
		// this->viewCurrentGraph();
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

void sugiyama::executeAll() {
	leda::graph current_graph = m_graphwin.get_graph();
	for (step* s : m_steps) {
		s->setGraph(current_graph);
		s->run();
		current_graph = s->getGraph();
	}
}

void sugiyama::viewCurrentGraph() {
	leda::graph& current_graph = m_steps[m_current_step_item]->getGraph();
	m_graphwin.set_graph(current_graph);
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