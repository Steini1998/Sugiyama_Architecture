# Compiler with Options (e.g. for "COMPILER.cpp")
CXX := cl
CXXFLAGS := -nologo -W3 -Zm300 -TP -EHsc -Ox -MT

# Project-Directory-Structure
INCLUDE_DIR := incl
SOURCE_DIR := src
INTERMEDIATE_DIR := intermediates
BINARY_DIR := bin

LEDA_INCLUDE_DIR ?= ..\incl

# Relevant Source-Files
SOURCE_FILE_NAMES := sugiyama.cpp positionable_graph.cpp step.cpp step_viewer.cpp graph_update_tracker.cpp

SOURCE_FILES := $(addprefix $(SOURCE_DIR)/, $(SOURCE_FILE_NAMES))
OBJECT_FILES := $(addprefix $(INTERMEDIATE_DIR)/, $(patsubst %.cpp, %.obj, $(SOURCE_FILE_NAMES)))

# Libraries to create
LIBRARY_NAME := sugiyama
STATIC_LIBRARY := $(BINARY_DIR)/$(LIBRARY_NAME).lib


# Static Library only contains this components binaries and not the system-libraries or leda-library
$(STATIC_LIBRARY): $(OBJECT_FILES)
	LIB.EXE /OUT:$@ $^
	

$(INTERMEDIATE_DIR)/%.obj: override CPPFLAGS += -I $(LEDA_INCLUDE_DIR) -I $(INCLUDE_DIR)

$(INTERMEDIATE_DIR)/%.obj: $(SOURCE_DIR)/%.cpp
	$(COMPILE.cpp) -Fo$@ $<


.PHONY: clean
clean:
	rm -f $(BINARY_DIR)/*.lib
	rm -f $(INTERMEDIATE_DIR)/*.obj