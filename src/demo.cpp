#include <LEDA/graphics/graphwin.h>

#include "SUGIPROJ/sugiyama.h"
#include "SUGIPROJ/step.h"
#include "SUGIPROJ/leveling.h"

int main() {
    leda::GraphWin gw {};
    gw.display();

	while (gw.edit()) {
		sugi::sugiyama sg {gw};    
        sg.add(new sugi::leveling{});
        sg.add(new sugi::leveling{});
        sg.run();
	}
    
    return 0;
}