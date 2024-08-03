#include "SUGIPROJ/views/step_viewer.h"

using namespace sugi;


void step_viewer::view() {
    m_current_step_item = m_steps.first();
    bool still_active = true;
    
    while (still_active) {
        switch (m_user_interface->get()) {
            case 0:
                still_active = false;
                break;
            case 1:
                moveStepBackward();
                break;
            case 2:
                moveStepForward();
                break;
        }
        showCurrentStepsResult();
    }
}

void step_viewer::setSteps(const leda::list<step*>& all_steps) {
    m_steps = all_steps;
}

void step_viewer::setUserInterface(ui* user_interface) {
    m_user_interface = user_interface;
}

void step_viewer::showCurrentStepsResult() {
	step* current_step = m_steps[m_current_step_item];
	current_step->showResult();
}

void step_viewer::moveStepBackward() {
	if (m_current_step_item == m_steps.first_item()) {
		return;
	}
	m_current_step_item = m_current_step_item->get_pred();
	return;
}

void step_viewer::moveStepForward() {
	if (m_current_step_item == m_steps.last_item()) {
		return;
	}
	m_current_step_item = m_current_step_item->get_succ();
	return;
}