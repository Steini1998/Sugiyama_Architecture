#include <stdio.h>

#include "LEDA/graphics/graphwin.h"

#include "SUGIPROJ/sugiyama.h"
#include "SUGIPROJ/steps/input.h"
#include "SUGIPROJ/steps/cycle_breaking.h"

#include "SUGIPROJ/views/step_viewer.h"
#include "SUGIPROJ/views/panel_ui.h"

using namespace sugi;

int main() {
    leda::GraphWin gw {"Sugiyama"};
	
	step_viewer sv {};
    sv.setUserInterface(new panel_ui{gw});
	
    gw.display();

	while (gw.edit()) {
		sugi::sugiyama sg {gw};
		sg.setStepViewer(sv);
		
		sg.add(new sugi::input{});
        sg.add(new sugi::cycle_breaking{});
        sg.add(new sugi::cycle_breaking{});

        sg.process();
        sg.show();
	}
    
    return 0;
}