THIRD_DIR = third
LINENOISE_DIR = $(THIRD_DIR)/linenoise
BGCC_DIR = ../../output
BIN_DIR = bin
SRC_DIR = src
INC_DIR = include
CFLAG = -Wall -g
CCFLAG = $(CFLAG) -I$(INC_DIR) -I$(LINENOISE_DIR) -Ioutput-cpp -I$(BGCC_DIR)/include
LINK_FLAG = -L$(BGCC_DIR)/lib -lbgcc -lpthread

default: cctalk-server cctalk


cctalk-server: $(SRC_DIR)/ccserver.cpp gen_code
	$(CXX) -o $@ $< $(BIN_DIR)/talk.o $(BIN_DIR)/common.o $(BIN_DIR)/callback.o $(CCFLAG) $(LINK_FLAG)

cctalk: $(SRC_DIR)/cctalk.cpp gen_code linenoise
	$(CXX) -o $@ $< $(BIN_DIR)/linenoise.o $(BIN_DIR)/talk.o $(BIN_DIR)/common.o $(BIN_DIR)/callback.o $(CCFLAG) $(LINK_FLAG)

gen_code:
	rm -rf output-cpp
	cd bidl && ../$(BGCC_DIR)/bidl2sl callback.bidl common.bidl talk.bidl && mv output-cpp .. && cd ..
	$(CXX) $(CCFLAG) -c -o $(BIN_DIR)/talk.o output-cpp/talk.cpp
	$(CXX) $(CCFLAG) -c -o $(BIN_DIR)/common.o output-cpp/common.cpp
	$(CXX) $(CCFLAG) -c -o $(BIN_DIR)/callback.o output-cpp/callback.cpp

linenoise: $(LINENOISE_DIR)/linenoise.c $(LINENOISE_DIR)/linenoise.h
	$(CXX) $(CFLAG) -c -o $(BIN_DIR)/linenoise.o $<

clean:
	rm -rf $(BIN_DIR)/* cctalk cctalk-server *.log

