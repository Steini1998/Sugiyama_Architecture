LDFLAGS = -LIBPATH:$(LEDA_LIBRARY_DIR)

# Project-Directory-Structure
INCLUDE_DIR := incl
SOURCE_DIR := src
INTERMEDIATE_DIR := intermediates
BINARY_DIR := bin

# Relevant Source-Files
SOURCE_FILE_NAMES := sugiyama.cpp positionable_graph.cpp step.cpp step_viewer.cpp graph_update_tracker.cpp

SOURCE_FILES := $(addprefix $(SOURCE_DIR)/, $(SOURCE_FILE_NAMES))
OBJECT_FILES := $(addprefix $(INTERMEDIATE_DIR)/, $(patsubst %.cpp, %.obj, $(SOURCE_FILE_NAMES)))

# Libraries to create
LIBRARY_NAME := sugiyama
STATIC_LIBRARY := $(BINARY_DIR)/$(LIBRARY_NAME).lib
DYNAMIC_LIBRARY := $(BINARY_DIR)/$(LIBRARY_NAME).dll


.PHONY: all
all: $(STATIC_LIBRARY) $(DYNAMIC_LIBRARY)

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