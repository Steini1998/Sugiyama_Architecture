linking_libs := user32.lib gdi32.lib msimg32.lib comdlg32.lib shell32.lib advapi32.lib wsock32.lib

dll: intermediates/graph_update_tracker.obj intermediates/positionable_graph.obj \
		intermediates/step_viewer.obj intermediates/step.obj \
		intermediates/sugiyama.obj
	LINK.EXE /DLL /OUT:SUGIYAMA.DLL $(linking_libs) .\\lib\\leda.lib $^

lib: intermediates/graph_update_tracker.obj intermediates/positionable_graph.obj \
		intermediates/step_viewer.obj intermediates/step.obj \
		intermediates/sugiyama.obj
	LIB.EXE /OUT:sugiyama.lib $^

intermediates/%.obj: src/%.cpp incl/SUGIPROJ/%.h
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT -I .\\incl $< -Fo$@

.PRECIOUS: intermediates/%.obj
	
.PHONY: clean
clean:
	echo "Nothing"