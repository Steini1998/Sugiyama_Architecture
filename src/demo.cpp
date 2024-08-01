#include <stdio.h>

#include "LEDA/graphics/graphwin.h"

#include "SUGIPROJ/sugiyama.h"
#include "SUGIPROJ/steps/cycle_breaking.h"

int main() {
    leda::GraphWin gw {"Sugiyama"};
    gw.display();

	while (gw.edit()) {
		sugi::sugiyama sg {gw};    
        sg.add(new sugi::cycle_breaking{});
        sg.add(new sugi::cycle_breaking{});

        sg.process();
        sg.view();
	}
    
    return 0;
}