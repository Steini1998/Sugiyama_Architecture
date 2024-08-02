linking_libs := user32.lib gdi32.lib msimg32.lib comdlg32.lib shell32.lib advapi32.lib wsock32.lib


all: bin/demo.exe
	

bin/demo.exe: intermediates/demo.obj intermediates/sugiyama.obj intermediates/positionable_graph.obj intermediates/step_viewer.obj intermediates/panel_ui.obj intermediates/step.obj intermediates/input.obj intermediates/cycle_breaking.obj
	cl -nologo -MT $^ -Febin/demo.exe .\\lib\\leda.lib $(linking_libs)


intermediates/%.obj: src/%.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT -I .\\incl $< -Fo$@

intermediates/sugiyama.obj: incl/SUGIPROJ/sugiyama.h incl/SUGIPROJ/steps/step.h incl/SUGIPROJ/views/step_viewer.h src/sugiyama.cpp src/step.cpp src/step_viewer.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT -I .\\incl src/sugiyama.cpp -Fointermediates/sugiyama.obj

intermediates/positionable_graph.obj: incl/SUGIPROJ/positionable_graph.h src/positionable_graph.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT -I .\\incl src/positionable_graph.cpp -Fointermediates/positionable_graph.obj

intermediates/step_viewer.obj: incl/SUGIPROJ/views/step_viewer.h incl/SUGIPROJ/views/ui.h src/step_viewer.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT -I .\\incl src/step_viewer.cpp -Fointermediates/step_viewer.obj

intermediates/panel_ui.obj: incl/SUGIPROJ/views/ui.h incl/SUGIPROJ/views/panel_ui.h src/panel_ui.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT -I .\\incl src/panel_ui.cpp -Fointermediates/panel_ui.obj

intermediates/step.obj: incl/SUGIPROJ/steps/step.h incl/SUGIPROJ/positionable_graph.h src/step.cpp src/positionable_graph.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT -I .\\incl src/step.cpp -Fointermediates/step.obj
	
intermediates/input.obj: incl/SUGIPROJ/steps/step.h incl/SUGIPROJ/steps/input.h src/step.cpp src/input.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT -I .\\incl src/input.cpp -Fointermediates/input.obj
	
intermediates/cycle_breaking.obj: incl/SUGIPROJ/steps/step.h incl/SUGIPROJ/steps/cycle_breaking.h src/step.cpp src/cycle_breaking.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT -I .\\incl src/cycle_breaking.cpp -Fointermediates/cycle_breaking.obj


.PRECIOUS: intermediates/%.obj
	
.PHONY: clean
clean:
	echo "Nothing"
	