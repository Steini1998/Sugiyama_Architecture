CXX := cl
CXXFLAGS := -nologo -W3 -c -Zm300 -TP -EHsc -Ox -MT

INCLUDE_DIR := incl
SOURCE_DIR := src
INTERMEDIATE_DIR := intermediates
BINARY_DIR := bin

SOURCE_FILE_NAMES := sugiyama.cpp positionable_graph.cpp step.cpp step_viewer.cpp graph_update_tracker.cpp

SOURCE_FILES := $(addprefix $(SOURCE_DIR)/, $(SOURCE_FILE_NAMES))
OBJECT_FILES := $(addprefix $(INTERMEDIATE_DIR)/, $(patsubst %.cpp, %.obj, $(SOURCE_FILE_NAMES)))

LIBRARY_NAME := sugiyama
STATIC_LIBRARY := $(BINARY_DIR)/$(LIBRARY_NAME).lib
DYNAMIC_LIBRARY := $(BINARY_DIR)/$(LIBRARY_NAME).dll

SYSTEM_LIBS := user32.lib gdi32.lib msimg32.lib comdlg32.lib shell32.lib advapi32.lib wsock32.lib
LEDA_INCLUDE_DIR := ..\incl
LEDA_LIBRARY_DIR := ..\lib
LEDA_LIB := leda.lib

LDFLAGS := -L $(LEDA_LIBRARY_DIR)


# Static Library only contains this components binaries and not the system-libraries or leda-library
.PHONY: lib
lib: $(STATIC_LIBRARY)

$(STATIC_LIBRARY): $(OBJECT_FILES)
	LIB.EXE /OUT:$@ $^
	

.PHONY: dll
dll: $(DYNAMIC_LIBRARY)

$(DYNAMIC_LIBRARY): $(OBJECT_FILES)
	LINK.EXE /DLL /OUT:$@ $(LDFLAGS) $(SYSTEM_LIBS) $(LEDA_LIB) $^
	

$(INTERMEDIATE_DIR)/%.obj: override CPPFLAGS += -I $(LEDA_INCLUDE_DIR) -I $(INCLUDE_DIR)

$(INTERMEDIATE_DIR)/%.obj: $(SOURCE_DIR)/%.cpp
	$(COMPILE.cpp) $< -Fo$@


.PHONY: clean
clean:
	rm -f $(BINARY_DIR)/*
	rm -f $(INTERMEDIATE_DIR)/*