# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
PRJ_ROOT_DIR := C:/Documents\ and\ Settings/MarkBuchanan/Desktop/frc/FRC2011
WS_ROOT_DIR := C:/Documents\ and\ Settings/MarkBuchanan/Desktop/frc



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = BuiltinDefaultCode/$(MODE_DIR)/BuiltinDefaultCode.out \
	 BuiltinDefaultCode_partialImage/$(MODE_DIR)/BuiltinDefaultCode_partialImage.o


#Rules

# BuiltinDefaultCode
ifeq ($(DEBUG_MODE),1)
BuiltinDefaultCode/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
BuiltinDefaultCode/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
BuiltinDefaultCode/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
BuiltinDefaultCode/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
BuiltinDefaultCode/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
BuiltinDefaultCode/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
BuiltinDefaultCode/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
BuiltinDefaultCode/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
BuiltinDefaultCode/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
BuiltinDefaultCode/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
BuiltinDefaultCode/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
BuiltinDefaultCode/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
BuiltinDefaultCode/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
BuiltinDefaultCode/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
BuiltinDefaultCode/$(MODE_DIR)/% : PROJECT_TYPE = DKM
BuiltinDefaultCode/$(MODE_DIR)/% : DEFINES = 
BuiltinDefaultCode/$(MODE_DIR)/% : EXPAND_DBG = 0
BuiltinDefaultCode/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
BuiltinDefaultCode/$(MODE_DIR)/% : CPU = PPC603
BuiltinDefaultCode/$(MODE_DIR)/% : TOOL_FAMILY = gnu
BuiltinDefaultCode/$(MODE_DIR)/% : TOOL = gnu
BuiltinDefaultCode/$(MODE_DIR)/% : TOOL_PATH = 
BuiltinDefaultCode/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
BuiltinDefaultCode/$(MODE_DIR)/% : LIBPATH = 
BuiltinDefaultCode/$(MODE_DIR)/% : LIBS = 
BuiltinDefaultCode/$(MODE_DIR)/% : OBJ_DIR := BuiltinDefaultCode/$(MODE_DIR)

OBJECTS_BuiltinDefaultCode = BuiltinDefaultCode_partialImage/$(MODE_DIR)/BuiltinDefaultCode_partialImage.o

BuiltinDefaultCode/$(MODE_DIR)/BuiltinDefaultCode.out : $(OBJECTS_BuiltinDefaultCode)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_BuiltinDefaultCode) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_BuiltinDefaultCode) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

BuiltinDefaultCode/$(MODE_DIR)/BuiltinDefaultCode_compile_file : $(FILE) ;

_clean :: BuiltinDefaultCode/$(MODE_DIR)/BuiltinDefaultCode_clean

BuiltinDefaultCode/$(MODE_DIR)/BuiltinDefaultCode_clean : 
	$(TRACE_FLAG)if [ -d "BuiltinDefaultCode" ]; then cd "BuiltinDefaultCode"; rm -rf $(MODE_DIR); fi


# BuiltinDefaultCode_partialImage
ifeq ($(DEBUG_MODE),1)
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : DEFINES = 
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : CPU = PPC603
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : TOOL = gnu
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : LIBPATH = 
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : LIBS = 
BuiltinDefaultCode_partialImage/$(MODE_DIR)/% : OBJ_DIR := BuiltinDefaultCode_partialImage/$(MODE_DIR)

BuiltinDefaultCode_partialImage/$(MODE_DIR)/Objects/FRC2011/FRC2011.o : C:/Documents\ and\ Settings/MarkBuchanan/Desktop/frc/FRC2011/FRC2011.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


BuiltinDefaultCode_partialImage/$(MODE_DIR)/Objects/FRC2011/Hardware/Arm.o : C:/Documents\ and\ Settings/MarkBuchanan/Desktop/frc/FRC2011/Hardware/Arm.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


BuiltinDefaultCode_partialImage/$(MODE_DIR)/Objects/FRC2011/Hardware/ThreeStateSolenoid.o : C:/Documents\ and\ Settings/MarkBuchanan/Desktop/frc/FRC2011/Hardware/ThreeStateSolenoid.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_BuiltinDefaultCode_partialImage = BuiltinDefaultCode_partialImage/$(MODE_DIR)/Objects/FRC2011/FRC2011.o \
	 BuiltinDefaultCode_partialImage/$(MODE_DIR)/Objects/FRC2011/Hardware/Arm.o \
	 BuiltinDefaultCode_partialImage/$(MODE_DIR)/Objects/FRC2011/Hardware/ThreeStateSolenoid.o

BuiltinDefaultCode_partialImage/$(MODE_DIR)/BuiltinDefaultCode_partialImage.o : $(OBJECTS_BuiltinDefaultCode_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_BuiltinDefaultCode_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

BuiltinDefaultCode_partialImage/$(MODE_DIR)/BuiltinDefaultCode_partialImage_compile_file : $(FILE) ;

_clean :: BuiltinDefaultCode_partialImage/$(MODE_DIR)/BuiltinDefaultCode_partialImage_clean

BuiltinDefaultCode_partialImage/$(MODE_DIR)/BuiltinDefaultCode_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "BuiltinDefaultCode_partialImage" ]; then cd "BuiltinDefaultCode_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := BuiltinDefaultCode_partialImage/$(MODE_DIR)/Objects/FRC2011/FRC2011.d BuiltinDefaultCode_partialImage/$(MODE_DIR)/Objects/FRC2011/Hardware/Arm.d BuiltinDefaultCode_partialImage/$(MODE_DIR)/Objects/FRC2011/Hardware/ThreeStateSolenoid.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
