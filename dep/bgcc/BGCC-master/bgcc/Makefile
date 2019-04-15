CXX = g++
#CXXFLAGS = -Wall -fPIC -g -DNDEBUG

CXXFLAGS = -Wall -W -pipe -Wno-unused-parameter -Wreorder -Wwrite-strings -Wswitch -Wno-sign-compare\
	           -g3 -DVERSION=\"${SCMPF_MODULE_VERSION}\"\
              -fPIC -finline-functions -Winline -Wreturn-type -Wtrigraphs -Wformat -Wparentheses -Wpointer-arith -Werror 

INC_DIR += -I.
SRC_DIR += .
LIB_DIR +=

OUTPUT_DIR = ../$(OUTPUT_PATH)
OUTPUT_INCLUDE_DIR = $(OUTPUT_DIR)/include
OUTPUT_INCLUDE_LIBS_DIR = $(OUTPUT_INCLUDE_DIR)/libs
OUTPUT_LIBRARY_DIR = $(OUTPUT_DIR)/lib
LIBRARY_NAME = libbgcc
STATIC_LIBRARY_NAME = $(LIBRARY_NAME).a
SO_SUBVERSION = 0
DYNAMIC_LIBRARY_NAME = $(LIBRARY_NAME).so

SOURCE := $(foreach src, $(SRC_DIR) $(SRC_DIR)/libs, \
	$(wildcard \
	$(addprefix $(src)/*,.cpp .c) ) )

INCLUDES := $(foreach src, $(SRC_DIR), \
	$(wildcard \
	$(addprefix $(src), /*.h /*.hpp) ) )

INCLUDES_LIBS := $(foreach src, $(SRC_DIR)/libs, \
	$(wildcard \
	$(addprefix $(src), /*.h /*.hpp) ) )

INC_DIR += $(foreach src, $(SRC_DIR) $(SRC_DIR)/libs, \
	$(addprefix -I,$(src)) )

OBJECTS = $(patsubst %.cpp,%.o, \
	$(patsubst %.c,%.o,$(SOURCE)) )

all: lib inc
	
lib: $(OBJECTS)
	-mkdir -p $(OUTPUT_LIBRARY_DIR)
	ar cr $(OUTPUT_LIBRARY_DIR)/$(STATIC_LIBRARY_NAME) $^

inc: 
	mkdir -p $(OUTPUT_INCLUDE_DIR)
	cp $(INCLUDES) $(OUTPUT_INCLUDE_DIR)
	
	rm -rf $(OUTPUT_INCLUDE_LIBS_DIR)
	mkdir -p $(OUTPUT_INCLUDE_LIBS_DIR)
	cp $(INCLUDES_LIBS) $(OUTPUT_INCLUDE_LIBS_DIR)
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c  -o $@ $(INC_DIR) $^

clean:
	rm -f $(OBJECTS)
	echo $(OUTPUT_DIR)
