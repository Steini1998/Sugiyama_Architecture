linking_libs := user32.lib gdi32.lib msimg32.lib comdlg32.lib shell32.lib advapi32.lib wsock32.lib


all: bin/demo.exe
	

bin/demo.exe: intermediates/demo.obj intermediates/sugiyama.obj intermediates/step.obj intermediates/input.obj intermediates/cycle_breaking.obj
	cl -nologo -MT intermediates/demo.obj intermediates/sugiyama.obj intermediates/step.obj intermediates/input.obj intermediates/cycle_breaking.obj -Febin/demo.exe .\\lib\\leda.lib $(linking_libs)


intermediates/%.obj: src/%.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT  -I .\\incl $< -Fo$@

intermediates/sugiyama.obj: incl/SUGIPROJ/sugiyama.h src/sugiyama.cpp incl/SUGIPROJ/steps/step.h src/step.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT  -I .\\incl src/sugiyama.cpp -Fointermediates/sugiyama.obj
	
intermediates/step.obj: incl/SUGIPROJ/steps/step.h src/step.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT  -I .\\incl src/step.cpp -Fointermediates/step.obj
	
intermediates/input.obj: incl/SUGIPROJ/steps/step.h incl/SUGIPROJ/steps/input.h src/step.cpp src/input.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT  -I .\\incl src/input.cpp -Fointermediates/input.obj
	
intermediates/cycle_breaking.obj: incl/SUGIPROJ/steps/step.h incl/SUGIPROJ/steps/cycle_breaking.h src/step.cpp src/cycle_breaking.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT  -I .\\incl src/cycle_breaking.cpp -Fointermediates/cycle_breaking.obj


.PRECIOUS: intermediates/%.obj
	
.PHONY: clean
clean:
	echo "Nothing"
	