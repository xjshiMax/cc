CXX = g++
SINGLE= log-test
LOG = bgcc.log* log-test.log* longline.log*
CFLAGS = -Wall -L.. -lbgcc -lpthread

INC_PATH_PREFIX = ../../output/include

INC_PATH += -I$(INC_PATH_PREFIX)

LD_PATH = -L../../output/lib/

$(SINGLE): log-test.cpp $(SRC)
	$(CXX) -g -o $@ $^ $(INC_PATH) $(LD_PATH)  $(CFLAGS)

clean:
	rm -rf $(SINGLE) $(LOG)

clean-log:
	rm -rf $(LOG)
