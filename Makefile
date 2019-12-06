SHELL := /bin/bash
CXX ?= g++
CXXFLAGS ?= -Wall -Werror -Wextra -Weffc++ -std=c++14
LIBS += -lpthread
# source and objcet directorys
SRC_DIR ?= src
OBJ_DIR ?= objs
# name of executable (program)
execable ?= producer-consumer
# autodetect projects in SRC_DIR
PROJECT_DIRS := $(sort $(dir $(abspath $(wildcard $(SRC_DIR)/*/*.hpp))))
# includes
INCLUDES ?= $(addprefix -I,$(abspath $(SRC_DIR)))
# autodetect *.cpp files
CPPS := $(wildcard $(SRC_DIR)/*/*.cpp) $(wildcard $(SRC_DIR)/main.cpp)
# all object files
OBJS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(CPPS:.cpp=.o))
# all dependensy files
DEPS := $(OBJS:.o=.d)
# setting colored output
INTERACTIVE := $(shell [ -t 0 ] && echo 1)
NOCOLORS := 0
NOCOLORS := $(shell tput colors 2> /dev/null)
ifeq ($(shell test $(NOCOLORS) -ge 8 2> /dev/null; echo $$?), 0)
    BOLD := $(shell tput bold)
    RCOLOR := $(shell tput sgr0)
    BLACK := $(shell tput setaf 0)
    RED := $(shell tput setaf 1)
    GREEN := $(shell tput setaf 2)
    YELLOW := $(shell tput setaf 3)
    BLUE := $(shell tput setaf 4)
    MAGENTA := $(shell tput setaf 5)
    CYAN := $(shell tput setaf 6)
    WHITE := $(shell tput setaf 7)
endif

# exporting variables
export SRC_DIR
export OBJ_DIR
export execable
export CXXFLAGS
export LIBS
export INCLUDES
#########################################

_default: _makeODir $(execable)
	@echo -e "$(GREEN)Compiled.$(RCOLOR)"

.PHONY: install debug noassert mingw clean resolve resource_converter

install:
	@$(MAKE) --no-print-directory $(MAKEFILE)

_makeODir:
	@mkdir -p $(OBJ_DIR)
resolve:
	@echo -e "$(GREEN)Resolved.$(RCOLOR)"
	@find $(OBJ_DIR) -name *.d | xargs rm -rf
$(OBJ_DIR)/%.d: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo -en "$(YELLOW)Calculating dependencies...$(RCOLOR)\r"
	@$(CXX) $(INCLUDES) $(CXXFLAGS) -MM $< -o $@
	@sed -i 's|$(notdir $*).o:|$(@:.d=.o):|g' $@

-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo -e "$(BOLD)$(YELLOW)$(CXX) $(CXXFLAGS) -c $< -o $@$(RCOLOR)"
	@$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@
$(execable): $(OBJS)
	@echo -e "$(BOLD)$(GREEN)$(CXX) $(CXXFLAGS) $(DEF_FLAGS) <obj_files> -o $@ $(LIBS)$(RCOLOR)"
	@$(CXX) $(INCLUDES) $(CXXFLAGS) $(OBJS) -o $@ $(LIBS)
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(execable)
	@echo -e "$(GREEN)Cleaned.$(RCOLOR)"
mingwClean: _setMingw clean

help info:
	@echo -e "\nMakefile to compile $(BOLD)$(GREEN)$(execable)$(RCOLOR)\n"
	@echo -e "------$(RED) Use the following targets $(RCOLOR)-----------------"
	@echo -e "$(MAGENTA)<None>$(RCOLOR) | $(CYAN)install$(RCOLOR)\n\tto make the $(BOLD)$(GREEN)$(execable)$(RCOLOR)."
	@echo -e "$(CYAN)clean$(RCOLOR)\n\tto cleanup (use after $(CYAN)debug$(RCOLOR) to cleanup debug build)."
	@echo -e "$(CYAN)resolve$(RCOLOR)\n\tto resolve dependencies after hierarchical changes."
	@echo -e "$(CYAN)help$(RCOLOR) | $(CYAN)info$(RCOLOR)\n\tto type this message."
	@echo -e "------$(RED) Setable variables $(RCOLOR)-------------------------"
	@echo -e "$(YELLOW)CXX$(RCOLOR)\n\tto set the compiler."
	@echo -e "\tby default: '$(MAGENTA)$(CXX)$(RCOLOR)'"
	@echo -e "$(YELLOW)CXXFLAGS$(RCOLOR)\n\tto set compilation flags."
	@echo -e "\tby default: '$(MAGENTA)$(CXXFLAGS)$(RCOLOR)'"
	@echo -e "$(YELLOW)LIBS$(RCOLOR)\n\tto set other libs."
	@echo -e "\tby default: '$(MAGENTA)$(LIBS)$(RCOLOR)'"
	@echo -e "$(YELLOW)INCLUDES$(RCOLOR)\n\tto set additional include dirs."
	@echo -e "\tby default: '$(MAGENTA)$(INCLUDES)$(RCOLOR)'"
	@echo -e "$(YELLOW)execable$(RCOLOR)\n\tto rename the executable (program)."
	@echo -e "\tby default: '$(GREEN)$(execable)$(RCOLOR)'"
	@echo -e "--------------------------------------------------\n"
	@echo -e "For more information please look into Makefile.\n"
