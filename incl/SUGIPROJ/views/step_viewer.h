#pragma once

#include "SUGIPROJ/steps/step.h"
#include "SUGIPROJ/views/ui.h"

namespace sugi {
    
    class step_viewer {
    public:
        step_viewer() = default;

        void view();

        void setSteps(const leda::list<step*>&);
        void setUserInterface(ui*);

    private:
		void showCurrentStepsResult();

		void moveStepBackward();
		void moveStepForward();

    private:
        leda::list<step*> m_steps;
        leda::list_item m_current_step_item;

        ui* m_user_interface;

    };

}