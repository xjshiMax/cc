CXX = g++
BIDL2SL=../../output/bidl2sl
SERVER = server
CLIENT = client

OUTPUT_PATH=output

CXXFLAGS = -Wall -g -W -Werror -pipe -Wreorder -Wwrite-strings -Wswitch -Wno-sign-compare
LDFLAGS= -lbgcc -lssl -lpthread

INC_PATH = -I../../output/include
LD_PATH = -L../../output/lib/

BIDL_FILES=$(wildcard *.bidl)

BIDL_SOURCES  = output-cpp/callback.cpp 
BIDL_OBJS = $(patsubst %.cpp,%.o,$(BIDL_SOURCES))

SERVER_SOURCES = $(wildcard *server.cpp) $(wildcard *send*.cpp)
SERVER_OBJS = $(patsubst %.cpp,%.o,$(SERVER_SOURCES))

CLIENT_SOURCES = $(wildcard *client.cpp)  $(wildcard *recv*.cpp)
CLIENT_OBJS= $(patsubst %.cpp,%.o,$(CLIENT_SOURCES))

BIDL_FILES=$(notdir $(wildcard *.bidl))

all:$(CLIENT) $(SERVER)
	if [ ! -d $(OUTPUT_PATH) ]; then mkdir -p $(OUTPUT_PATH); fi
	cp $(SERVER) $(OUTPUT_PATH)/
	cp $(CLIENT) $(OUTPUT_PATH)/
	cp *.conf $(OUTPUT_PATH)/


$(SERVER): $(BIDL_OBJS) $(SERVER_OBJS)
	$(CXX) $(CXXFLAGS) -o $(SERVER) $(SERVER_OBJS) $(BIDL_OBJS) $(INC_PATH) $(LD_PATH) $(LDFLAGS)

$(CLIENT): $(BIDL_OBJS) $(CLIENT_OBJS) 	
	$(CXX) $(CXXFLAGS) -o $(CLIENT) $(CLIENT_OBJS) $(BIDL_OBJS) $(INC_PATH) $(LD_PATH) $(LDFLAGS)

$(SERVER_OBJS): %.o: %.cpp 	
	$(CXX) $(CXXFLAGS) -o $@ $(INC_PATH) -c $<

$(CLIENT_OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $(INC_PATH) -c $<

$(BIDL_OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $(INC_PATH) -c $<

$(BIDL_SOURCES):
	$(BIDL2SL) -g cpp $(BIDL_FILES)

clean:
	if [ -d $(OUTPUT_PATH) ]; then rm -rf $(OUTPUT_PATH)/*; fi
	if [ -d output-cpp ]; then rm -rf output-cpp/*; fi
	rm -fr $(SERVER) $(CLIENT) $(SERVER_OBJS) $(CLIENT_OBJS) *.log*
