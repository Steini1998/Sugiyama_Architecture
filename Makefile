linking_libs := user32.lib gdi32.lib msimg32.lib comdlg32.lib shell32.lib advapi32.lib wsock32.lib


all: bin/demo.exe
	

bin/demo.exe: intermediates/demo.obj intermediates/sugiyama.obj intermediates/cycle_breaking.obj intermediates/leveling.obj
	cl -nologo -MT  intermediates/demo.obj intermediates/sugiyama.obj intermediates/cycle_breaking.obj intermediates/leveling.obj -Febin/demo.exe .\\lib\\leda.lib $(linking_libs)

intermediates/%.obj: src/%.cpp
	cl -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT  -I .\\incl $< -Fo$@
	
	
.PRECIOUS: intermediates/%.obj
	
.PHONY: clean
clean:
	echo "Nothing"
	